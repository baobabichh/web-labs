#include "UserInfoController.h"
#include <c/GraphQLParser.h>
#include <c/GraphQLAstToJSON.h>
#include <AstNode.h>
#include <GraphQLParser.h>
#include <json/json.h>

#include "grpc_functions.h"

std::string escapeLike(const std::string& str)
{
    std::string result;
    for (const char ch : str)
    {
        if (ch == '%' || ch == '_') result += '\\';
        result += ch;
    }
    return result;
}



std::string graphql_to_json(const std::string& graphql, std::string& err)
{
    const char* error{};
    auto AST = facebook::graphql::parseString(graphql.c_str(), &error);
    if (!AST) {
        std::cerr << "Parser failed with error: " << error << std::endl;
        err = std::string{err};
        free((void *)error);
        return {};
    }

    const char *json = graphql_ast_to_json(reinterpret_cast<const struct GraphQLAstNode *>(AST.get()));
    std::string res{json};
    free((void *)json);
    return res;
}

struct UserQuery
{
    std::vector<uint32_t> ids{};
    std::vector<std::string> fields{};
};

UserQuery parseGraphQLResponse(const std::string &jsonText, std::string& err)
{
    Json::Value root;
    Json::CharReaderBuilder readerBuilder;
    std::string errs;

    std::istringstream s(jsonText);
    if (!Json::parseFromStream(readerBuilder, s, &root, &errs))
    {
       err ="Failed to parse JSON: " + errs;
       return {};
    }

    UserQuery query;

    const auto &definitions = root["definitions"];
    for (const auto &definition : definitions)
    {
        const auto &selections = definition["selectionSet"]["selections"];
        for (const auto &selection : selections)
        {
            const auto &arguments = selection["arguments"];
            for (const auto &argument : arguments)
            {
                if (argument["name"]["value"].asString() == "id")
                {
                    query.ids.push_back(std::stoll(argument["value"]["value"].asString()));
                }
            }

            const auto &userSelections = selection["selectionSet"]["selections"];
            for (const auto &userSelection : userSelections)
            {
                query.fields.push_back(userSelection["name"]["value"].asString());
            }
        }
    }

    static const std::set<std::string> good_fields{"id", "name", "photo"};
    for(auto& field : query.fields)
    {
        std::transform(field.begin(), field.end(), field.begin(), [](unsigned char c){ return std::tolower(c); });
        if(!good_fields.count(field))
        {
            err = "bad field " + field;
            return query;
        }
    }


    return query;
}

void UserInfoController::getUserInfoGraph(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    // Get the request body, which should contain the GraphQL query
    std::string query_string{req->getBody().data()};

    std::cout << "query_string: " << query_string << "\n";

    std::string err{};
    const std::string graph_json = graphql_to_json(query_string, err);
    if(err.size())
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = err;
        jsonResponse["Status"] = "Fail";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    // Retrieve user ID from session
    auto session = req->getSession();
    const size_t user_id = session->get<size_t>("user_id");

    err = {};
    auto users_query = parseGraphQLResponse(graph_json, err);
    if(err.size())
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = err;
        jsonResponse["Status"] = "Fail";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    std::ostringstream ss{};

    ss << "SELECT id, ";
    {
        int added{0};
        for(const auto& field : users_query.fields)
        {
            if(field == "photo" || field == "id")
            {
                continue;
            }

            if(added)
            {
                ss << ", ";
            }

            ss << field << " ";
            added++;
        }
    }
    ss << " from Users ";
    {
        int added{0};
        if(users_query.ids.size())
        {
            ss << " where id in (";
            for(const auto& id : users_query.ids)
            {
                if(added)
                {
                    ss << ", ";
                }
                ss << id;
                added++;
            }
            ss << ")";
        }
    }

    std::string sql_query{ss.str()};

    std::cout << "sql_query: " << sql_query << "\n";


    // Convert AST to JSON for easier handling
    std::string astJson = graph_json;
    Json::Value jsonRoot;
    Json::CharReaderBuilder readerBuilder;
    std::string errs;
    std::istringstream s(astJson);
    if (!Json::parseFromStream(readerBuilder, s, &jsonRoot, &errs)) {
        // Handle JSON parsing errors
        Json::Value jsonResponse;
        jsonResponse["Message"] = std::string("Failed to parse AST JSON: ") + errs;
        jsonResponse["Status"] = "Fail";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    /*
        {
            "data": {
                "User": {
                    "ID": 1,
                    "Name": "John Doe",
                    "Photo": "https://example.com/photos/johndoe.jpg"
                }
            }
        }
    */

    auto dbClient = app().getDbClient("our_chat");

    try 
    {
        orm::Result result = dbClient->execSqlSync(sql_query, 1);

        Json::Value jsonResponse;
        Json::Value usersJson(Json::arrayValue);

        for (const auto &row : result)
        {
            Json::Value userJson;

            for(const auto& field : users_query.fields)
            {
                if(field == "photo")
                {
                    userJson["photo"] = "/get_user_photo?user_id=" + row["id"].as<std::string>();
                    continue;
                }

                userJson[field] = row[field].as<std::string>();
            }
            
            usersJson.append(userJson);
        }
        jsonResponse["data"]["Users"] = usersJson;
        jsonResponse["Status"] = "Success";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
    }
    catch (const orm::DrogonDbException &e)
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = e.base().what();
        jsonResponse["Status"] = "Fail";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }
}

void UserInfoController::getUserInfo(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto session = req->getSession();
    auto dbClient = app().getDbClient("our_chat");

    const size_t user_id = session->get<size_t>("user_id");
    try 
    {
        orm::Result result = dbClient->execSqlSync("SELECT ID, Name, Password FROM Users where ID = ?", std::to_string(user_id), 1);

        for (auto row : result)
        {
            Json::Value jsonResponse;
            jsonResponse["ID"] = row["ID"].as<size_t>();
            jsonResponse["Name"] = row["Name"].as<std::string>();
            jsonResponse["Password"] = row["Password"].as<std::string>();
            jsonResponse["Status"] = "Success";
            auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
            response->setStatusCode(k200OK);
            callback(response);
            return;
        }
    }
    catch (const orm::DrogonDbException &e)
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = e.base().what();
        jsonResponse["Status"] = "Fail";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    Json::Value jsonResponse;
    jsonResponse["Message"] = "No such user";
    jsonResponse["Status"] = "Fail";
    auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
    response->setStatusCode(k200OK);
    callback(response);
    return;
}

void UserInfoController::updateUserInfo(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto session = req->getSession();
    auto dbClient = app().getDbClient("our_chat");

    std::string new_name = req->getParameter("Name");
    std::string new_password = req->getParameter("Password");

    const size_t user_id = session->get<size_t>("user_id");
    try 
    {
        orm::Result result = dbClient->execSqlSync("UPDATE Users set Name = ?, Password = ? where ID = ?", new_name, new_password, std::to_string(user_id), 1);

        {
            Json::Value jsonResponse;
            jsonResponse["Status"] = "Success";
            auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
            response->setStatusCode(k200OK);
            callback(response);
            return;
        }
    }
    catch (const orm::DrogonDbException &e)
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = e.base().what();
        jsonResponse["Status"] = "Fail";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    Json::Value jsonResponse;
    jsonResponse["Message"] = "Unreachable";
    jsonResponse["Status"] = "Fail";
    auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
    response->setStatusCode(k200OK);
    callback(response);
    return;
}

void UserInfoController::deleteUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto session = req->getSession();
    auto dbClient = app().getDbClient("our_chat");

    const size_t user_id = session->get<size_t>("user_id");
    try 
    {
        orm::Result result = dbClient->execSqlSync("DELETE FROM Users WHERE ID = ?",std::to_string(user_id), 1);

        {
            session->erase("user_id");
            Json::Value jsonResponse;
            jsonResponse["Status"] = "Success";
            auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
            response->setStatusCode(k200OK);
            callback(response);
            return;
        }
    }
    catch (const orm::DrogonDbException &e)
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = e.base().what();
        jsonResponse["Status"] = "Fail";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    Json::Value jsonResponse;
    jsonResponse["Message"] = "Unreachable";
    jsonResponse["Status"] = "Fail";
    auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
    response->setStatusCode(k200OK);
    callback(response);
    return;
}

void UserInfoController::findUsers(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto dbClient = app().getDbClient("our_chat");

    std::string search_param = req->getParameter("name");
    if(search_param.empty())
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = "Parameter name is empty";
        jsonResponse["Status"] = "Fail";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    std::string like_str = "%" + escapeLike(search_param) + "%";

    try 
    {
        orm::Result result = dbClient->execSqlSync("SELECT ID, Name FROM Users WHERE Name like ? or CAST(ID AS CHAR) like ?", like_str, like_str, 1);

        Json::Value jsonResponse;
        Json::Value usersArray(Json::arrayValue);

        for (auto row : result)
        {
            Json::Value user;
            user["ID"] = row["ID"].as<size_t>();
            user["Name"] = row["Name"].as<std::string>();
            usersArray.append(user);
        }

        jsonResponse["Users"] = usersArray;
        jsonResponse["Status"] = "Success";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }
    catch (const orm::DrogonDbException &e)
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = e.base().what();
        jsonResponse["Status"] = "Fail";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    Json::Value jsonResponse;
    jsonResponse["Message"] = "Unreachable";
    jsonResponse["Status"] = "Fail";
    auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
    response->setStatusCode(k200OK);
    callback(response);
    return;
}

void UserInfoController::getOtherUserInfo(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto session = req->getSession();
    auto dbClient = app().getDbClient("our_chat");

    std::string user_id = req->getParameter("user_id");
    if(user_id.empty())
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = "Parameter user_id is empty";
        jsonResponse["Status"] = "Fail";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    try 
    {
        orm::Result result = dbClient->execSqlSync("SELECT ID, Name FROM Users where ID = ?", user_id, 1);

        for (auto row : result)
        {
            Json::Value jsonResponse;
            jsonResponse["ID"] = row["ID"].as<size_t>();
            jsonResponse["Name"] = row["Name"].as<std::string>();
            jsonResponse["Status"] = "Success";
            auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
            response->setStatusCode(k200OK);
            callback(response);
            return;
        }
    }
    catch (const orm::DrogonDbException &e)
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = e.base().what();
        jsonResponse["Status"] = "Fail";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    Json::Value jsonResponse;
    jsonResponse["Message"] = "No such user";
    jsonResponse["Status"] = "Fail";
    auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
    response->setStatusCode(k200OK);
    callback(response);
    return;
}

void UserInfoController::addChat(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto dbClient = app().getDbClient("our_chat");
    auto session = req->getSession();

    std::string user_id = req->getParameter("user_id");
    const size_t my_user_id = session->get<size_t>("user_id");

    if(user_id == std::to_string(my_user_id))
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = "Can not create chat with yourself";
        jsonResponse["Status"] = "Fail";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    if(user_id.empty())
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = "Parameter user_id is empty";
        jsonResponse["Status"] = "Fail";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    try 
    {
        orm::Result result = dbClient->execSqlSync("SELECT ID FROM UserChats WHERE UserID1 = ? and UserID2 = ?", std::to_string(my_user_id), user_id, 1);

        for (auto row : result)
        {
            Json::Value jsonResponse;
            jsonResponse["Message"] = "There is already chat";
            jsonResponse["Status"] = "Fail";
            auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
            response->setStatusCode(k200OK);
            callback(response);
            return;
        }
    }
    catch (const orm::DrogonDbException &e)
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = e.base().what();
        jsonResponse["Status"] = "Fail";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    try 
    {
        orm::Result result = dbClient->execSqlSync("INSERT INTO UserChats (UserID1, UserID2) VALUES (?, ?)", std::to_string(my_user_id), user_id, 1);

        Json::Value jsonResponse;
        jsonResponse["Status"] = "Success";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }
    catch (const orm::DrogonDbException &e)
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = e.base().what();
        jsonResponse["Status"] = "Fail";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    Json::Value jsonResponse;
    jsonResponse["Message"] = "Unreachable";
    jsonResponse["Status"] = "Fail";
    auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
    response->setStatusCode(k200OK);
    callback(response);
    return;
}

void UserInfoController::getChats(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto dbClient = app().getDbClient("our_chat");
    auto session = req->getSession();

    const size_t my_user_id = session->get<size_t>("user_id");

    try 
    {
        orm::Result result = dbClient->execSqlSync("SELECT c.UserID2, u.Name FROM UserChats c inner join Users u on u.id = c.UserID2 WHERE c.UserID1 = ? ", std::to_string(my_user_id), 1);

        Json::Value jsonResponse;
        Json::Value chats_array(Json::arrayValue);

        for (auto row : result)
        {
            Json::Value chat;
            chat["UserID2"] = row["UserID2"].as<size_t>();
            chat["Name"] = row["Name"].as<std::string>();
            chats_array.append(chat);
        }

        jsonResponse["Chats"] = chats_array;
        jsonResponse["Status"] = "Success";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }
    catch (const orm::DrogonDbException &e)
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = e.base().what();
        jsonResponse["Status"] = "Fail";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    Json::Value jsonResponse;
    jsonResponse["Message"] = "Unreachable";
    jsonResponse["Status"] = "Fail";
    auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
    response->setStatusCode(k200OK);
    callback(response);
    return;
}

void UserInfoController::deleteChat(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto dbClient = app().getDbClient("our_chat");
    auto session = req->getSession();

    const size_t my_user_id = session->get<size_t>("user_id");
    std::string user_id = req->getParameter("user_id");
    if(user_id.empty())
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = "Parameter user_id is empty";
        jsonResponse["Status"] = "Fail";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    try 
    {
        orm::Result result = dbClient->execSqlSync("DELETE FROM UserChats WHERE UserID1 = ? and UserID2 = ?", std::to_string(my_user_id), user_id, 1);

        Json::Value jsonResponse;
        jsonResponse["Status"] = "Success";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }
    catch (const orm::DrogonDbException &e)
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = e.base().what();
        jsonResponse["Status"] = "Fail";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    Json::Value jsonResponse;
    jsonResponse["Message"] = "Unreachable";
    jsonResponse["Status"] = "Fail";
    auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
    response->setStatusCode(k200OK);
    callback(response);
    return;
}

void UserInfoController::getMessages(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto dbClient = app().getDbClient("our_chat");
    auto session = req->getSession();

    const size_t my_user_id = session->get<size_t>("user_id");
    std::string user_id = req->getParameter("user_id");
    if(user_id.empty())
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = "Parameter user_id is empty";
        jsonResponse["Status"] = "Fail";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    try 
    {
        orm::Result result = dbClient->execSqlSync("SELECT UserID1, UserID2, Content, CreateTS FROM Messages WHERE UserID1 in (?, ?) and UserID2 in (?, ?) order by CreateTS limit 10000", std::to_string(my_user_id), user_id, std::to_string(my_user_id), user_id, 1);

        Json::Value jsonResponse;
        Json::Value messages_array(Json::arrayValue);

        for (auto row : result)
        {
            Json::Value message;
            message["UserID1"] = row["UserID1"].as<size_t>();
            message["UserID2"] = row["UserID2"].as<size_t>();
            message["Content"] = row["Content"].as<std::string>();
            message["CreateTS"] = row["CreateTS"].as<std::string>();
            messages_array.append(message);
        }

        jsonResponse["Messages"] = messages_array;
        jsonResponse["Status"] = "Success";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
    }
    catch (const orm::DrogonDbException &e)
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = e.base().what();
        jsonResponse["Status"] = "Fail";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    Json::Value jsonResponse;
    jsonResponse["Message"] = "Unreachable";
    jsonResponse["Status"] = "Fail";
    auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
    response->setStatusCode(k200OK);
    callback(response);
    return;
}

#include "UserInfoController.h"

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
            jsonResponse["Message"] = "There is olready chat";
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
        orm::Result result = dbClient->execSqlSync("SELECT UserID2 FROM UserChats WHERE UserID1 = ? ", std::to_string(my_user_id), 1);

        Json::Value jsonResponse;
        Json::Value chats_array(Json::arrayValue);

        for (auto row : result)
        {
            Json::Value chat;
            chat["UserID2"] = row["UserID2"].as<size_t>();
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
        orm::Result result = dbClient->execSqlSync("SELECT UserID1, UserID2, Content, CreateTS FROM Messages WHERE UserID1 in (?, ?) and UserID2 in (?, ?) order by CreateTS", std::to_string(my_user_id), user_id, std::to_string(my_user_id), user_id, 1);

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

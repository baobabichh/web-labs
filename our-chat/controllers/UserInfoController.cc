#include "UserInfoController.h"

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

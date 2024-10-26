#include "UserRegistrationController.h"

void UserRegistrationController::registerUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    std::string email = req->getParameter("email");
    std::string password = req->getParameter("password");

    if(email.size() < 5)
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = "email.size() < 5";
        jsonResponse["Status"] = "Fail";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    if(password.size() < 5)
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = "password.size() < 5";
        jsonResponse["Status"] = "Fail";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    auto dbClient = app().getDbClient("our_chat");

    try 
    {
        orm::Result result = dbClient->execSqlSync("SELECT * FROM Users where Email = ?", email, 1);

        for (auto row : result)
        {
            Json::Value jsonResponse;
            jsonResponse["Message"] = "There is already user with such email";
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
        orm::Result result = dbClient->execSqlSync("insert into Users (email, password) value (?, ?)", email, password, 1);
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

    {
        Json::Value jsonResponse;
        jsonResponse["Status"] = "Success";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }
}

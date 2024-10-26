#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class UserRegistrationController : public drogon::HttpController<UserRegistrationController>
{
  public:
    METHOD_LIST_BEGIN
      ADD_METHOD_TO(UserRegistrationController::registerUser, "/register_user", Post);
      ADD_METHOD_TO(UserRegistrationController::registerUser, "/login_user", Post);
    METHOD_LIST_END

    void registerUser(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    void loginUser(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
};

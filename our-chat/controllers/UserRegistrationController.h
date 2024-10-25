#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class UserRegistrationController : public drogon::HttpController<UserRegistrationController>
{
  public:
    METHOD_LIST_BEGIN
    METHOD_ADD(UserRegistrationController::registerUser, "register_user/{1}/{2}", Get);

    METHOD_LIST_END
    void registerUser(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, std::string email, std::string password);
};

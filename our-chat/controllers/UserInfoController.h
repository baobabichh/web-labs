#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class UserInfoController : public drogon::HttpController<UserInfoController>
{
  public:
    METHOD_LIST_BEGIN
      ADD_METHOD_TO(UserInfoController::getUserInfo, "/get_user_info", Get, "LoginFilter");
      ADD_METHOD_TO(UserInfoController::updateUserInfo, "/update_user_info", Put, "LoginFilter");
      ADD_METHOD_TO(UserInfoController::deleteUser, "/delete_user", Delete, "LoginFilter");
      ADD_METHOD_TO(UserInfoController::findUsers, "/find_users", Get, "LoginFilter");

      ADD_METHOD_TO(UserInfoController::addChat, "/add_chat", Get, "LoginFilter");
      ADD_METHOD_TO(UserInfoController::getChats, "/get_chats", Get, "LoginFilter");
      ADD_METHOD_TO(UserInfoController::deleteChat, "/delete_chat", Get, "LoginFilter");

      ADD_METHOD_TO(UserInfoController::getMessages, "/get_messages", Get, "LoginFilter");
    METHOD_LIST_END

    void getUserInfo(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    void updateUserInfo(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    void deleteUser(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    void findUsers(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);

    void addChat(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    void getChats(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    void deleteChat(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    void getMessages(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
};

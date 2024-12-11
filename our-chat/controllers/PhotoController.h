#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class PhotoController : public drogon::HttpController<PhotoController>
{
  public:
    METHOD_LIST_BEGIN
      ADD_METHOD_TO(PhotoController::updateUserPhoto, "/register_user", Post);
      ADD_METHOD_TO(PhotoController::getUserPhoto, "/login_user", Post);
    METHOD_LIST_END

    void updateUserPhoto(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    void getUserPhoto(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
};

#include "PhotoController.h"

#include "grpc_functions.h"

// Add definition of your processing function here

void PhotoController::updateUserPhoto(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    auto session = req->getSession();
    auto dbClient = app().getDbClient("our_chat");

    const size_t user_id = session->get<size_t>("user_id");

    std::string img_data = req->getParameter("ImageData");
    std::vector<char> img_data_vec{std::begin(img_data), std::end(img_data)};


    if(img_data_vec.size() > 1000000)
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = "Image is too big";
        jsonResponse["Status"] = "Error";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    if(SendPhotoDataToServer("0.0.0.0:50051", std::to_string(user_id), img_data_vec))
    {
        Json::Value jsonResponse;
        jsonResponse["Status"] = "Success";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }
    else
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = "Can not save image";
        jsonResponse["Status"] = "Error";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }
}

void PhotoController::getUserPhoto(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    auto session = req->getSession();
    auto dbClient = app().getDbClient("our_chat");

    std::string user_id = req->getParameter("user_id");
    if(user_id.empty())
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = "Param user_id is empty";
        jsonResponse["Status"] = "Error";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    std::vector<char> data{};

    if(GetPhotoDataOfUser("0.0.0.0:50051", user_id, data))
    {
        std::cout << "data.size(): " << data.size() << "\n";

        auto response = HttpResponse::newHttpResponse();
        response->setStatusCode(k200OK);

        response->setContentTypeCodeAndCustomString(
            drogon::CT_APPLICATION_OCTET_STREAM, "image/png"
        );

        response->setBody(std::string(data.begin(), data.end()));
        callback(response);
        return;
    }
    else
    {
        std::cout << "data.size(): " << data.size() << "\n";

        Json::Value jsonResponse;
        jsonResponse["Message"] = "Can not get image";
        jsonResponse["Status"] = "Error";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }
}


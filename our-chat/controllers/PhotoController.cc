#include "PhotoController.h"

#include "grpc_functions.h"

// Add definition of your processing function here

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<char> convertStringToCharVector(const std::string& input) {
    std::vector<char> charVector;
    std::stringstream ss(input);
    std::string number;

    // Use ',' as the delimiter to split the string into numbers
    while (std::getline(ss, number, ',')) {
        try {
            // Convert the number string to an integer
            int num = std::stoi(number);

            // Convert the integer to a char and add it to the vector
            // Make sure the number is within the valid range for a char
            if (num < 0 || num > 255) {
                throw std::out_of_range("Number out of char range");
            }
            charVector.push_back(static_cast<char>(num));
        } catch (const std::exception& e) {
            std::cerr << "Error converting '" << number << "': " << e.what() << std::endl;
        }
    }

    return charVector;
}

void PhotoController::updateUserPhoto(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    auto session = req->getSession();
    auto dbClient = app().getDbClient("our_chat");

    const size_t user_id = session->get<size_t>("user_id");

    std::string img_data = req->getParameter("ImageData");
    std::string img_ext = req->getParameter("ImageExt");

    if(img_ext.empty())
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = "No param ImageExt";
        jsonResponse["Status"] = "Error";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    std::cout << "img_data.size(): " << img_data.size() << "\n";


    for(size_t i = 0; i < img_data.size(); i++)
    {
        if(img_data[i] == '[' || img_data[i] == ']')
        {
            img_data.erase(std::begin(img_data) + i);
        }
    }

    std::vector<char> img_data_vec{convertStringToCharVector(img_data)};

    std::cout << "send data: " << img_data_vec.size() << "\n";


    if(img_data_vec.size() > 20000000)
    {
        Json::Value jsonResponse;
        jsonResponse["Message"] = "Image is too big";
        jsonResponse["Status"] = "Error";
        auto response = HttpResponse::newHttpJsonResponse(jsonResponse);
        response->setStatusCode(k200OK);
        callback(response);
        return;
    }

    try 
    {
        orm::Result result = dbClient->execSqlSync("UPDATE Users set PhotoExt = ? where ID = ?", img_ext, std::to_string(user_id), 1);
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

    std::string img_ext{};
    try 
    {
        orm::Result result = dbClient->execSqlSync("SELECT PhotoExt FROM Users WHERE id = ?", user_id, 1);

        int add_count{0};
        for (auto row : result)
        {
            img_ext = row["PhotoExt"].as<std::string>();
            ++add_count;
            break;
        }

        if(!add_count)
        {
            Json::Value jsonResponse;
            jsonResponse["Message"] = "There is no user with such id";
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

    std::vector<char> data{};

    if(GetPhotoDataOfUser("0.0.0.0:50051", user_id, data))
    {
        std::cout << "data.size(): " << data.size() << "\n";

        auto response = HttpResponse::newHttpResponse();
        response->setStatusCode(k200OK);

        response->setContentTypeCodeAndCustomString(
            drogon::CT_APPLICATION_OCTET_STREAM, "image/" + img_ext
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


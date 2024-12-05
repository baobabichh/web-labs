#include "MessagesController.h"

std::string jsonValueToString(const Json::Value& jsonData)
{
    Json::StreamWriterBuilder writerBuilder;
    std::string jsonString = Json::writeString(writerBuilder, jsonData);
    return jsonString;
}

void MessagesController::handleNewMessage(const WebSocketConnectionPtr& wsConnPtr, std::string &&message, const WebSocketMessageType &type)
{
    std::string my_user_id = std::to_string(_con_to_user_id[wsConnPtr]);

    if (type == drogon::WebSocketMessageType::Text)
    {
        Json::Value jsonData;
        Json::CharReaderBuilder readerBuilder;
        std::string errs;

        std::istringstream iss(message);

        if (Json::parseFromStream(readerBuilder, iss, &jsonData, &errs))
        {
            auto dbClient = app().getDbClient("our_chat");

            std::string to_user_id = jsonData["user_id"].asString();
            std::string content = jsonData["content"].asString();

            if(content.empty())
            {
                Json::Value jsonResponse;
                jsonResponse["Message"] = "Field content is empty";
                jsonResponse["Status"] = "Fail";
                wsConnPtr->send(jsonValueToString(jsonResponse));
                return;
            }

            if(to_user_id.empty())
            {
                Json::Value jsonResponse;
                jsonResponse["Message"] = "Field to_user_id is empty";
                jsonResponse["Status"] = "Fail";
                wsConnPtr->send(jsonValueToString(jsonResponse));
                return;
            }

            try 
            {
                orm::Result result = dbClient->execSqlSync("SELECT ID FROM Users where ID in (?, ?)", my_user_id, to_user_id, 1);

                if(result.size() != 2)
                {
                    Json::Value jsonResponse;
                    jsonResponse["Message"] = "There is no such user";
                    jsonResponse["Status"] = "Fail";
                    wsConnPtr->send(jsonValueToString(jsonResponse));
                    return;
                }
            }
            catch (const orm::DrogonDbException &e)
            {
                Json::Value jsonResponse;
                jsonResponse["Message"] = e.base().what();
                jsonResponse["Status"] = "Fail";
                wsConnPtr->send(jsonValueToString(jsonResponse));
                return;
            }

            try 
            {
                orm::Result result = dbClient->execSqlSync("insert into Messages (UserID1, UserID2, Content) value (?, ?, ?)", my_user_id, to_user_id, content, 1);
            }
            catch (const orm::DrogonDbException &e)
            {
                Json::Value jsonResponse;
                jsonResponse["Message"] = e.base().what();
                jsonResponse["Status"] = "Fail";
                wsConnPtr->send(jsonValueToString(jsonResponse));
                return;
            }

            const size_t to_user_id_int = std::stoull(to_user_id);

            if(_user_id_to_con.count(to_user_id_int))
            {
                Json::Value jsonResponse;
                jsonResponse["Content"] = content;
                jsonResponse["FromUserID"] = size_t(std::stoull(my_user_id));
                jsonResponse["Type"] = "NewMessaage";
                _user_id_to_con[to_user_id_int]->send(jsonValueToString(jsonResponse));
            }

            {
                Json::Value jsonResponse;
                jsonResponse["Status"] = "Success";
                wsConnPtr->send(jsonValueToString(jsonResponse));
                return;
            }
        }
        else
        {
            Json::Value jsonResponse;
            jsonResponse["Message"] = errs;
            jsonResponse["Status"] = "Fail";
            wsConnPtr->send(jsonValueToString(jsonResponse));
            return;
        }
    }
}

void MessagesController::handleNewConnection(const HttpRequestPtr &req, const WebSocketConnectionPtr& wsConnPtr)
{
    auto session = req->getSession();
    const size_t my_user_id = session->get<size_t>("user_id");
    _con_to_user_id.insert({wsConnPtr, my_user_id});
    _user_id_to_con.insert({my_user_id, wsConnPtr});
}

void MessagesController::handleConnectionClosed(const WebSocketConnectionPtr& wsConnPtr)
{
    const auto user_id = _con_to_user_id[wsConnPtr];
    _con_to_user_id.erase(wsConnPtr);
    _user_id_to_con.erase(user_id);
}

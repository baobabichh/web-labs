#pragma once

#include <drogon/WebSocketController.h>

using namespace drogon;

class MessagesController : public drogon::WebSocketController<MessagesController>
{
  public:
    void handleNewMessage(const WebSocketConnectionPtr&, std::string &&, const WebSocketMessageType &) override;
    void handleNewConnection(const HttpRequestPtr &, const WebSocketConnectionPtr&) override;
    void handleConnectionClosed(const WebSocketConnectionPtr&) override;
    WS_PATH_LIST_BEGIN
    WS_PATH_ADD("/chat", "LoginFilter");
    WS_PATH_LIST_END

  private:
    std::unordered_map<WebSocketConnectionPtr, size_t> _con_to_user_id;
    std::unordered_map<size_t, WebSocketConnectionPtr> _user_id_to_con;
};

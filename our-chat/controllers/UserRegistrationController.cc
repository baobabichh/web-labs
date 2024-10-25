#include "UserRegistrationController.h"

// Add definition of your processing function here

void UserRegistrationController::registerUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    std::cout << "hello\n";

    std::string email = req->getParameter("email");
    std::string password = req->getParameter("password");

    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k200OK);
    resp->setContentTypeCode(CT_TEXT_HTML);
    resp->setBody("Your Page Contents " + email + " " + password);
    callback(resp);
}

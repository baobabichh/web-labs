#include "LoginFilter.h"

using namespace drogon;

void LoginFilter::doFilter(const HttpRequestPtr &req, FilterCallback &&fcb, FilterChainCallback &&fccb)
{
    std::cout << "LoginFilter is executing..." << std::endl;

    auto session = req->getSession();

    if (!session->find("user_id"))
    {
        if (req->getPath() != "/index.html")
        { 
            auto res = drogon::HttpResponse::newRedirectionResponse("/index.html");
            fcb(res);
            return;
        }
    }
    fccb();
}

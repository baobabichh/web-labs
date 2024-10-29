#include <drogon/drogon.h>
#include "filters/LoginFilter.h"
int main()
{
    drogon::app().addListener("0.0.0.0", 50505);
    drogon::app().loadConfigFile("../config.json");
    drogon::app().run();
    return 0;
}

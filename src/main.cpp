#include <string>
#include "curlhandler.hpp"
#include "jsonhandler.hpp"

int main()
{
    bool ret = false;
    std::string jsonData;
    Curlhandler curlhandler;

    ret = curlhandler.init();
    if (ret == true)
    {
        std::string url = "https://blockchain.info/ticker";
        ret = curlhandler.setRequest(url);
        if (ret == true)
        {
            jsonData = curlhandler.GetResponse();
        }
    }

    Jsonhandler jason(jsonData);
    jason.print();

    return 0;
}


#include <string>
#include <iostream>
#include "curlhandler.hpp"

size_t curl_callback(void *ptr, size_t size, size_t nmemb, std::string *data)
{
    data->append((char *)ptr, size * nmemb);
    return size * nmemb;
}

Curlhandler::Curlhandler()
{
    curl_global_init(CURL_GLOBAL_ALL);
}
bool Curlhandler::init(void)
{
    _curl = curl_easy_init();
    if (!_curl)
    {
        std::cout << "ERROR : Curl initialization\n"
                  << std::endl;
        cleanup();
        return false;
    }
    _headers = curl_slist_append(_headers, "User-Agent: libcurl-agent/1.0");
    _headers = curl_slist_append(_headers, "Content-Type: application/json");
    _headers = curl_slist_append(_headers, "Cache-Control: no-cache");

    curl_easy_setopt(_curl, CURLOPT_HTTPHEADER, _headers);
    curl_easy_setopt(_curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(_curl, CURLOPT_SSL_VERIFYHOST, 0L);

    curl_easy_setopt(_curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(_curl, CURLOPT_TIMEOUT, 10L);                 // maximum time allowed for operation to finish, its in seconds
                                                                   // pass the url
    curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, curl_callback); // pass our call back function to handle received data
    curl_easy_setopt(_curl, CURLOPT_WRITEDATA, &_response_string); // pass the variable to hold the received data
    return true;
}
Curlhandler::~Curlhandler()
{
}

void Curlhandler::cleanup()
{
    if (_curl)
        curl_easy_cleanup(_curl);
    if (_headers)
        curl_slist_free_all(_headers);
    curl_global_cleanup();
}
bool Curlhandler::setRequest(const std::string url)
{
    bool ret = true;
    curl_easy_setopt(_curl, CURLOPT_URL, url.c_str());
    CURLcode status = curl_easy_perform(_curl);
    if (status != false)
    {
        std::cout << "Error: Request failed on URL : " << url << std::endl;
        std::cout << "Error Code: " << status << " Error Detail : " << curl_easy_strerror(status) << std::endl;
        ret = false;
    }

    cleanup();
    return ret;
}

std::string Curlhandler::GetResponse()
{
    return _response_string;
}
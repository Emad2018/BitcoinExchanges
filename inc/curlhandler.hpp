#ifndef CURLHANDLER_HPP
#define CURLHANDLER_HPP
#include <curl/curl.h>
#include <string>
class Curlhandler
{
private:
    /* data */
    std::string _url;
    std::string _response_string;
    CURL *_curl = NULL;
    struct curl_slist *_headers = NULL;

public:
    Curlhandler();
    ~Curlhandler();
    bool init(void);
    void cleanup();
    bool setRequest(const std::string url);
    std::string GetResponse();
};

#endif /* CURLHANDLER_HPP */

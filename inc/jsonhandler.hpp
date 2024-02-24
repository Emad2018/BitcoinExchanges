#ifndef JSONHANDLER_HPP
#define JSONHANDLER_HPP
#include <nlohmann/json.hpp>
#include <string>
class Jsonhandler
{
private:
    /* data */
    nlohmann::json _jasondata;

public:
    Jsonhandler(std::string InputString);
    ~Jsonhandler();
    void print();
};

#endif /* JSONHANDLER_HPP */

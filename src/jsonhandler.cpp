#include <nlohmann/json.hpp>
#include <iostream>
#include <format>
#include "jsonhandler.hpp"

#define MOSTTRADEDCURRENCIESLENGHT 28

const std::string MostTradedCurrencies[MOSTTRADEDCURRENCIESLENGHT] = {
    "USD", "EUR", "JPY", "GBP",
    "CNY", "AUD", "CAD", "CHF",
    "HKD", "SGD", "SEK", "KRW",
    "NZD", "INR", "TWD", "BRL",
    "DKK", "PLN", "THB", "CZK",
    "TRY", "HUF", "CLP", "RUB",
    "RON", "ARS", "HRK", "ISK"};

Jsonhandler::Jsonhandler(std::string InputString)
{
    _jasondata = nlohmann::json::parse(InputString);
}
Jsonhandler::~Jsonhandler()
{
}
void Jsonhandler::print(void)
{
    std::cout << std::format("{:-^57}\n", " ");
    std::cout << std::format("|{:^10}: {:^20} | {:^20}|\n", "Currency", "buy", "sell");
    std::cout << std::format("{:-^57}\n", "");
    for (int i = 0; i < MOSTTRADEDCURRENCIESLENGHT; i++)
    {
        std::string key = MostTradedCurrencies[i];
        float sell = _jasondata[key]["sell"];
        float buy = _jasondata[key]["buy"];
        std::string symbol = _jasondata[key]["symbol"];

        std::cout << std::format("|{:^10}: {:^20.3f} | {:^20.3f}|\n", symbol, buy, sell);
        std::cout << std::format("{:-^57}\n", "");
    }
}

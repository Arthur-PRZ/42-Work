#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    initMap(std::ifstream("data.csv"));
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : bitcoinPrice(copy.bitcoinPrice)
{

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if (this != &copy)
    {
        bitcoinPrice = copy.bitcoinPrice;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::initMap(std::ifstream file)
{
    std::map<std::string, float>::iterator it = bitcoinPrice.begin();
    std::string line;
    unsigned int i;

    (void)std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream streamLine(line);
        std::string content;

        std::getline(streamLine, content, ',');
        std::string date = content;
        std::getline(streamLine, content);
        float value = std::atof(content.c_str());
        bitcoinPrice[date] = value;
    }
}

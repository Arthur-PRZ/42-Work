#ifndef _BITCOINEXCHANGE_HPP_
#define _BITCOINEXCHANGE_HPP_

#include <fstream>
#include <map>
#include <sstream>
#include <iostream>
#include <cstdlib>

class BitcoinExchange
{
    private :

    std::map<std::string, float>  bitcoinPrice;

    public :

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &copy);
    BitcoinExchange& operator=(const BitcoinExchange &copy);
    ~BitcoinExchange();

    std::string trim(const std::string& line);

    void initMap(std::string fileName);

    bool checkLine(std::string &line, std::string &date, std::string &bitcoin);
    bool isDateValid(const std::string& date);
    bool checkValue(const std::string& valueStr);
    bool splitLine(const std::string& line, std::string& date, std::string& value);

    void printBitcoinValue(std::ifstream &file);
};

#endif
#ifndef _BITCOINEXCHANGE_HPP_
#define _BITCOINEXCHANGE_HPP_

#include <fstream>
#include <map>
#include <sstream>

class BitcoinExchange
{
    private :

    std::map<std::string, float>  bitcoinPrice;

    public :

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &copy);
    BitcoinExchange& operator=(const BitcoinExchange &copy);
    ~BitcoinExchange();

    void initMap(std::ifstream file);
};

#endif
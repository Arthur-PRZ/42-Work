#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    initMap("data.csv");
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

void BitcoinExchange::initMap(std::string fileName)
{
    std::ifstream file(fileName.c_str());
    // std::map<std::string, float>::iterator it = bitcoinPrice.begin();
    std::string line;

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

std::string BitcoinExchange::trim(const std::string& line)
{
    size_t start = line.find_first_not_of(" \t");
    size_t end = line.find_last_not_of(" \t");
    if (start == std::string::npos)
        return "";
    return line.substr(start, end - start + 1);
}

bool BitcoinExchange::splitLine(const std::string& line, std::string& date, std::string& value)
{
    size_t pos = line.find("|");
    if (pos == std::string::npos)
        return false;
    date = trim(line.substr(0, pos));
    value = trim(line.substr(pos + 1));
    return true;
}

bool BitcoinExchange::isDateValid(const std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.size(); ++i) {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009 || month < 1 || month > 12)
        return false;

    int dayInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (month == 2 && leap)
        dayInMonth[1] = 29;

    if (day < 1 || day > dayInMonth[month - 1])
        return false;

    if (year == 2009 && month == 1 && day < 3)
        return false;

    return true;
}

bool BitcoinExchange::checkValue(const std::string& valueStr)
{
    char *end;
    float value = std::strtof(valueStr.c_str(), &end);

    if (*end != '\0')
    {
        std::cout << "Error: bad input  => " << valueStr << std::endl;
        return false;
    }
    if (value < 0)
    {
        std::cout << "Error: not a positive number => " << value << std::endl;
        return false;
    }
    if (value > 1000)
    {
        std::cout << "Error: too large number => " << value << std::endl;
        return false;    
    }
    return true;
}

bool BitcoinExchange::checkLine(std::string &line, std::string &date, std::string &bitcoin)
{
    if (line.empty())
        return false;
    if (!splitLine(line, date, bitcoin))
    {
        std::cout << "Error: bad input  => " << line << std::endl;
        return false;
    }
    if (!isDateValid(date))
    {
        std::cout << "Error: date invalid => " << date << std::endl;
        return false;
    }
    if (!checkValue(bitcoin))
        return false;
    return true;
}

void BitcoinExchange::printBitcoinValue(std::ifstream &file)
{
    std::string line;
    std::string date;
    std::string bitcoin;

    (void)file;
    (void)std::getline(file, line);

    while (std::getline(file, line))
    {
        if (!checkLine(line, date, bitcoin))
            continue;

        std::map<std::string, float>::iterator it = bitcoinPrice.lower_bound(date);
        if (it == bitcoinPrice.end() || it->first != date)
        {
            if (it != bitcoinPrice.begin())
                --it;
            else
            {
                std::cerr << "Error: no earlier date available" << std::endl;
                continue;
            }
        }
        std::cout << date << " => " << bitcoin << " = " << std::atof(bitcoin.c_str())* it->second << std::endl;
    }
}
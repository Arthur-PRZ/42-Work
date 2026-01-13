#include <string>
#include <sstream>
#include <iostream>


void stringToIntValue(std::string str)
{
    std::stringstream ss(str);
    int intValue;
    if (!(ss >> intValue))
    {
        std::cout << "Error : invalid integer" << std::endl;
        return ;
    }
    if (!ss.eof())
    {
        std::cout << "Error : extra characters" << std::endl;
    }
    std::cout << "Int value : " << intValue << std::endl;
}

void stingToCharValue(std::string str)
{
    if (str.length() != 1)
    {
        std::cout << "Too many characters" << std::endl;
        return ;
    }
    if (str[0] >= 32 && str[0] <= 126)
    {
        std::cout << "Char value : " << str[0] << std::endl;
    }
}
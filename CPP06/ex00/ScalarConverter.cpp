#include "ScalarConverter.hpp"
#include "utils.cpp"
#include <cstdlib>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    (void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    (void)copy;
}

ScalarConverter::~ScalarConverter()
{
}

void convert(std::string &str)
{
    if (!checkInput(str))
    {
        std::cout << "Invalid input" << std::endl;
        return ;
    }
    eType type = getType(str);
    
    char charValue;
    int intValue;
    float floatValue;
    double doubleValue;

    if (type == CHAR)
    {
        charValue = str[0];
        floatValue = static_cast<float>(charValue);
        doubleValue = static_cast<double>(charValue);
        intValue = static_cast<int>(charValue);
    }
    else if (type == INT)
    {
        intValue = std::atoi(str.c_str());
        charValue = static_cast<char>(intValue);
        floatValue = static_cast<float>(intValue);
        doubleValue = static_cast<double>(intValue);
    }
    else if (type == FLOAT)
    {
        floatValue = std::atof(str.c_str());
        charValue = static_cast<char>(floatValue);
        doubleValue = static_cast<double>(floatValue);
        intValue = static_cast<int>(floatValue);
    }
    else if (type == DOUBLE)
    {
        doubleValue = std::strtod(str.c_str(), NULL);
        charValue = static_cast<char>(doubleValue);
        floatValue = static_cast<float>(doubleValue);
        intValue = static_cast<int>(doubleValue);
    }
    std::cout << "char: " << charValue << std::endl;
    std::cout << "int: " << intValue << std::endl;
    std::cout << "float: " << floatValue << std::endl;
    std::cout << "double: " << doubleValue << std::endl;
}
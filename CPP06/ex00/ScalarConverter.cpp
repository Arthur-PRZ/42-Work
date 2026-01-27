#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cerrno>

enum eType { CHAR, INT, FLOAT, DOUBLE, INVALID, POSITIVE_INF, NEGATIVE_INF, NAN };
bool checkInput(std::string &input);
eType getType(std::string &str);
void printConvImp();

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
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(std::string str)
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
    bool isIntInitialized = true;
    bool isInteger = true;

    // bool overflowInt = false;
    // bool overflowFoat = false;
    // bool overflowDouble = false;

    if (type == POSITIVE_INF)
    {
        std::cout << "char: impossible"<< std::endl;
        std::cout << "int: impossible"<< std::endl;
        std::cout << "float: +inff"  << std::endl;
        std::cout << "double: +inf" << std::endl;
        return ;
    }
    if (type == NEGATIVE_INF)
    {
        std::cout << "char: impossible"<< std::endl;
        std::cout << "int: impossible"<< std::endl;
        std::cout << "float: -inff"  << std::endl;
        std::cout << "double: -inf" << std::endl;
        return ;

    }
    if (type == NAN)
    {
        std::cout << "char: impossible"<< std::endl;
        std::cout << "int: impossible"<< std::endl;
        std::cout << "float: nanf"  << std::endl;
        std::cout << "double: nan" << std::endl;
        return ;
    }
    if (type == CHAR)
    {
        charValue = str[0];
        floatValue = static_cast<float>(charValue);
        doubleValue = static_cast<double>(charValue);
        intValue = static_cast<int>(charValue);
    }
    else if (type == INT)
    {
        long temp = std::strtol(str.c_str(), NULL, 10);

        if (errno == ERANGE || temp < INT_MIN || temp > INT_MAX)
        {
            printConvImp();
            return ;
        }

        intValue = std::atoi(str.c_str());
        charValue = static_cast<char>(intValue);
        floatValue = static_cast<float>(intValue);
        doubleValue = static_cast<double>(intValue);
    }
    else if (type == FLOAT)
    {
        long temp = std::strtol(str.c_str(), NULL, 10);

        if (errno == ERANGE || temp > FLT_MAX || temp < -FLT_MAX)
        {
            printConvImp();
            return ;
        }

        floatValue = std::atof(str.c_str());
        if (floatValue != static_cast<int>(floatValue))
            isInteger = false;
        charValue = static_cast<char>(floatValue);
        doubleValue = static_cast<double>(floatValue);
        if (floatValue == static_cast<int>(floatValue))
            intValue = static_cast<int>(floatValue);
        else
            isIntInitialized = false;
    }
    else if (type == DOUBLE)
    {
        long temp = std::strtol(str.c_str(), NULL, 10);

        if (errno == ERANGE || temp > DBL_MAX || temp < -DBL_MAX )
        {
            printConvImp();
            return ;
        }

        doubleValue = std::strtod(str.c_str(), NULL);
        if (doubleValue != static_cast<int>(doubleValue))
            isInteger = false;
        charValue = static_cast<char>(doubleValue);
        floatValue = static_cast<float>(doubleValue);
        if (doubleValue == static_cast<int>(doubleValue))
            intValue = static_cast<int>(doubleValue);
        else
            isIntInitialized = false;

    }
    if (charValue < 32 || charValue > 126)
        std::cout << "char: Non displayable"<< std::endl;
    else if (!isInteger)
        std::cout << "char: impossible"<< std::endl;
    else
        std::cout << "char: " << charValue << std::endl;
    if (isIntInitialized)
        std::cout << "int: " << intValue << std::endl;
    else
        std::cout << "int: impossible"<< std::endl;
    std::cout << "float: " <<  std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
    std::cout << "double: " <<  std::fixed << std::setprecision(1) << doubleValue << std::endl;

}
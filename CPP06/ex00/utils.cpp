#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cerrno>
#include <cmath>

enum eType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID,
    POSITIVE_INF,
    NEGATIVE_INF,
    NAN_TYPE,
};

void printConvImp()
{
    std::cout << "char: conversion is impossible"<< std::endl;
    std::cout << "int: conversion is impossible"<< std::endl;
    std::cout << "float: conversion is impossible" << std::endl;
    std::cout << "double: conversion is impossible" << std::endl;
}

void charConvert(char *charValue, int *intValue, float *floatValue,
        double *doubleValue, char c)
{
    *charValue = c;
    *floatValue = static_cast<float>(*charValue);
    *doubleValue = static_cast<double>(*charValue);
    *intValue = static_cast<int>(*charValue);
}

bool intConvert(char *charValue, int *intValue, float *floatValue,
        double *doubleValue, bool *charOverflow, std::string str)
{
    long temp = std::strtol(str.c_str(), NULL, 10);

    if (errno == ERANGE || temp < INT_MIN || temp > INT_MAX)
    {
        printConvImp();
        return false;
    }

    *intValue = std::atoi(str.c_str());
    if (*intValue == static_cast<char>(*intValue))
        *charValue = static_cast<char>(*intValue);
    else
        *charOverflow = true;
    *floatValue = static_cast<float>(*intValue);
    *doubleValue = static_cast<double>(*intValue);
    return true;
}

bool floatConvert(char *charValue, int *intValue, float *floatValue,
        double *doubleValue, bool *charOverflow, bool *isIntInitialized, std::string str)
{
    long temp = std::strtol(str.c_str(), NULL, 10);

    if (errno == ERANGE || temp > FLT_MAX || temp < -FLT_MAX)
    {
        printConvImp();
        return false;
    }

    *floatValue = std::atof(str.c_str());

    if (*floatValue == static_cast<char>(*floatValue))
        *charValue = static_cast<char>(*floatValue);
    else
        *charOverflow = true;
    *doubleValue = static_cast<double>(*floatValue);

    if (fmod(*floatValue, 1.0) != 0.0)
        *isIntInitialized = false;
    else
        *intValue = static_cast<int>(*floatValue);
    return true;
}

bool doubleConvert(char *charValue, int *intValue, float *floatValue,
        double *doubleValue, bool *charOverflow, bool *isIntInitialized, std::string str)
{
    long temp = std::strtol(str.c_str(), NULL, 10);

    if (errno == ERANGE || temp > DBL_MAX || temp < -DBL_MAX )
    {
        printConvImp();
        return false;
    }

    *doubleValue = std::strtod(str.c_str(), NULL);

    if (*doubleValue == static_cast<char>(*doubleValue))
        *charValue = static_cast<char>(*doubleValue);
    else
        *charOverflow = true;
    *floatValue = static_cast<float>(*doubleValue);
    if (fmod(*doubleValue, 1.0) != 0.0)
        *isIntInitialized = false;
    else
        *intValue = static_cast<int>(*doubleValue);
    return true;
}

void pseudoLiteralsHandling(eType type)
{
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
}

bool checkInput(std::string &input)
{
    int pointNbr = 0;
    bool asChar = false;
    bool asFigure = false;

    if (input == "+inf" || input == "+inff" || input =="-inff"
        || input == "-inf" || input == "nan" || input == "nanf")
        return true;

    for (size_t i = 0; i < input.length(); i++)
    {
        char c = input[i];
        if ((c == '+' || c == '-') && i != 0)
            return false;
        if (c == '.')
        {
            pointNbr++;
            if (pointNbr > 1)
            {
                std::cout << "b" << std::endl;
                return false;
            }
        }
        if (c == 'f' && i != input.length() - 1)
            return false;
        if (isdigit(c) == false && c != '.' && c != 'f' && c != '-' && c != '+')
        {
            if (asChar)
                return false;
            asChar = true;
            if (asChar && asFigure)
                return false;
        }
        if (isdigit(c))
        {
            asFigure = true;
            if (asChar && asFigure)
                return false;
        }
    }
    if (!asChar && !asFigure && input[0] != '\0')
    {
        std::cout << "f" << std::endl;
        return false;
    }
    return true;
}

eType getType(std::string &str)
{
    if (str.length() == 1 && isdigit(str[0]) == false) 
        return CHAR;

    if (str == "+inf" || str == "+inff")
        return POSITIVE_INF;
    if (str == "-inf" || str == "-inff")
        return NEGATIVE_INF;
    if (str == "nan" || str == "nanf")
        return NAN_TYPE;

    bool asF = false;
    bool asPoint = false;
    size_t i = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;

    for (; i < str.length(); i++)
    {
        if (str[i] == '.')
            asPoint = true;
        if (str[i] == 'f')
            asF = true;
    }

    if (asF == true)
        return FLOAT;
    if (asPoint == true)
        return DOUBLE;
    return INT;
}

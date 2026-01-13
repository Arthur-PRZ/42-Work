#include "ScalarConverter.hpp"
#include "convert.cpp"
#include <cstdlib>

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter  default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    (void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    std::cout << "ScalarConverter operator = called" << std::endl;
    (void)copy;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConvertor destructor called" << std::endl;
}

void convert(std::string &str)
{
    stringToIntValue(str);
}
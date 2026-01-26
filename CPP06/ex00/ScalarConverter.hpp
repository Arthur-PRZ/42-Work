#ifndef _SCALARCONVERTER_HPP_
#define _SCALARCONVERTER_HPP_

#include <iostream>
#include <string>

class ScalarConverter
{
    private :

    ScalarConverter();
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter &operator=(const ScalarConverter &copy);
    ~ScalarConverter();

    public :

    static void convert(std::string str);
};

#endif


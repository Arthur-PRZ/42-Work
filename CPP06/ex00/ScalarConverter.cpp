#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cerrno>

enum eType { CHAR, INT, FLOAT, DOUBLE, INVALID, POSITIVE_INF, NEGATIVE_INF, NAN_TYPE };
bool checkInput(std::string &input);
eType getType(std::string &str);
void printConvImp();
void pseudoLiteralsHandling(eType type);
void charConvert(char *charValue, int *intValue, float *floatValue, double *doubleValue, char c);
bool intConvert(char *charValue, int *intValue, float *floatValue,
                double *doubleValue, bool *charOverflow, std::string str);
bool floatConvert(char *charValue, int *intValue, float *floatValue,
                double *doubleValue, bool *charOverflow, bool *isIntInitialized, std::string str);
bool doubleConvert(char *charValue, int *intValue, float *floatValue,
                double *doubleValue, bool *charOverflow, bool *isIntInitialized, std::string str);


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
    
    if (type == POSITIVE_INF || type == NEGATIVE_INF || type == NAN_TYPE)
    {
        pseudoLiteralsHandling(type);
        return ;
    }

    char charValue = '\0';
    int intValue = 0;
    float floatValue = 0;
    double doubleValue = 0;
    bool isIntInitialized = true;
    bool charOverflow = false;

    if (type == CHAR)
    {
        charConvert(&charValue, &intValue, &floatValue, &doubleValue, str[0]);
    }
    else if (type == INT)
    {
        if (!intConvert(&charValue, &intValue, &floatValue, &doubleValue, &charOverflow, str))
            return ;
    }
    else if (type == FLOAT)
    {
        if (!floatConvert(&charValue, &intValue, &floatValue, &doubleValue,
            &charOverflow, &isIntInitialized, str))
            return ;
    }
    else if (type == DOUBLE)
    {
        if (!doubleConvert(&charValue, &intValue, &floatValue, &doubleValue,
            &charOverflow, &isIntInitialized, str))
            return ;
    }
    
    if (charOverflow || charValue < 0)
        std::cout << "char: impossible"<< std::endl;
    else if (charValue < 32 || charValue > 126)
        std::cout << "char: Non displayable"<< std::endl;
    else
        std::cout << "char: " << charValue << std::endl;
    if (isIntInitialized)
        std::cout << "int: " << intValue << std::endl;
    else
        std::cout << "int: impossible"<< std::endl;
    std::cout << "float: " <<  std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
    std::cout << "double: " <<  std::fixed << std::setprecision(1) << doubleValue << std::endl;

}
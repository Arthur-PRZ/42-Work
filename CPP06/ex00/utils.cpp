#include <string>
#include <sstream>
#include <iostream>
#include <string>

enum eType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
};

bool checkInput(std::string &input)
{
    int pointNbr = 0;
    bool asChar = false;
    bool asFigure = false;

    if (input.empty())
        return false;

    for (size_t i = 0; i < input.length(); i++)
    {
        char c = input[i];
        if ((c == '+' || c == '-') && i != 0)
        {
            return false;
        }
        if (c == '.')
        {
            pointNbr++;
            if (pointNbr > 1)
                return false;
        }
        if (c == 'f' && i != input.length() - 1)
        {    
            return false;
        }
        if (isprint(c) && isdigit(c) == false)
        {
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
    if (!asChar && !asFigure)
        return false;
    return true;
}

eType getType(std::string &str)
{
    if (str.length() == 1 && isprint(str[0]) && isdigit(str[0]) == false) 
        return CHAR;

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

// void stringToIntValue(std::string str)
// {
//     std::stringstream ss(str);
//     int intValue;
//     if (!(ss >> intValue))
//     {
//         std::cout << "Error : invalid integer" << std::endl;
//         return ;
//     }
//     if (!ss.eof())
//     {
//         std::cout << "Error : extra characters" << std::endl;
//     }
//     std::cout << "Int value : " << intValue << std::endl;
// }

// void stingToCharValue(std::string str)
// {
//     if (str.length() != 1)
//     {
//         std::cout << "Too many characters" << std::endl;
//         return ;
//     }
//     if (str[0] >= 32 && str[0] <= 126)
//     {
//         std::cout << "Char value : " << str[0] << std::endl;
//     }
// }



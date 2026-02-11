#ifndef _RPN_HPP_
#define _RPN_HPP_

#include <stack>
#include <string>
#include <sstream>
#include <iostream>

class RPN
{
    private :

    std::stack<int> stack;

    public :

    RPN();
    RPN(const RPN &copy);
    RPN &operator=(const RPN &copy);
    ~RPN();

    int calculate(std::string str);

};


#endif
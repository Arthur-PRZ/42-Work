#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &copy) : stack(copy.stack)
{
}

RPN &RPN::operator=(const RPN &copy)
{
    if (this != &copy)
    {
        stack = copy.stack;
    }
    return *this;
}

RPN::~RPN()
{
}

int RPN::calculate(std::string input)
{
    std::stringstream stream(input);
    std::string str;

    while (stream >> str)
    {
        int value;
        std::stringstream cur(str);

        if (cur >> value && cur.eof())
        {
            if (value > 9)
                throw std::runtime_error("Error: only number below 10 are allowed");
            stack.push(value);
        }
        else if (str == "*" || str == "-" || str == "+" || str == "/")
        {
            if (stack.size() < 2)
                throw std::runtime_error("Error: not enough number");
            int second = stack.top();
            stack.pop();
            int first = stack.top();
            stack.pop();
            if (str == "*")
                stack.push(first * second);
            if (str == "-")
                stack.push(first - second);
            if (str == "+")
                stack.push(first + second);            
            if (str == "/")
            {
                if (second == 0)
                    throw std::runtime_error("Error: can't divide by 0");
                stack.push(first / second);       
            }

        }
        else
            throw std::runtime_error("Error: input invalid");
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error: the size of the stack is invalid");
    return stack.top();
}
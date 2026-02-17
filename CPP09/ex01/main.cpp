#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./RPN \"3 4 + 5 -\"" << std::endl;
        return 1;
    }
    RPN rpn;
    std::string str(argv[1]);

    try
    {
        std::cout << rpn.calculate(str) << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
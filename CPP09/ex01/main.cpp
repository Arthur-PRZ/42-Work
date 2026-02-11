#include "RPN.hpp"

int main(int argc, char **argv)
{
    RPN rpn;
    std::string str(argv[1]);

    (void)argc;
    try
    {
        std::cout << rpn.calculate(str) << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
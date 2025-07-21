#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error : Need only one parameter" << std::endl;
        return 1;
    }
    
    Harl harl;

    harl.complain(argv[1]);
}
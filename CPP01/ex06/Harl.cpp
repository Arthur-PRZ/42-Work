#include "Harl.hpp"
#include "iostream"
#include "string"

Harl::Harl()
{
};

Harl::~Harl()
{
};

void    Harl::debug( void )
{
    std::cout << "Debug : I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info( void )
{
    std::cout << "Info : I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning( void )
{
    std::cout << "Warning : I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void    Harl::error( void )
{
    std::cout << "Error : This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain( std::string level )
{
    if (level != "DEBUG" && level != "WARNING" && level != "INFO" && level != "ERROR")
    {
        std::cout << "Level not found" << std::endl;
        return ;
    }
    switch (level[0])
    {
        case 'D':
            debug();
        case 'I':
            info();
        case 'W':
            warning();
        case 'E':
            error();
    }
}

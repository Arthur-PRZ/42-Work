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
    std::string  levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void         (Harl::*functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 5; i++)
    {
        if (level == levels[i])
        {
            (this->*functions[i])();
            return;
        }
    }
    std::cout << "Level not found" << std::endl;
}

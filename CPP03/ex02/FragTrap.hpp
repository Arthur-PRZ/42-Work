#pragma once

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class FragTrap : public ClapTrap
{

    public :

    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& fragTrap);
    ~FragTrap();
    FragTrap& operator=(const FragTrap& fragTrap);

    void attack(const std::string& target); 
    void highFiveGuys(void);
};
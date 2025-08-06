#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
    protected :

    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;

    public :

    ClapTrap();
    ClapTrap(const ClapTrap& clapTrap);
    ClapTrap(const std::string& newName);
    ~ClapTrap();
    ClapTrap& operator=(const ClapTrap& ClapTrap);

    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
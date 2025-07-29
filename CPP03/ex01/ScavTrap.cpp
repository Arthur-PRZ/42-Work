#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "Scavtrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "Scavtrap name constructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) : ClapTrap(scavTrap)
{
    std::cout << "Scavtrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Scavtrap copy constructor called" << std::endl;
}

ScavTrap& operator=(const ScavTrap& scavTrap);
{
};

void guardGate()
{
};
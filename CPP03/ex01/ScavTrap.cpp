#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "ScavTrap name constructor called" << std::endl;
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
    std::cout << "Scavtrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap)
{
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &scavTrap)
        {
            ClapTrap::operator=(scavTrap);
        }
        return *this;
};

void ScavTrap::attack(const std::string& target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        energyPoints--;
        std::cout << "ScavTrap " << name << " attacks " << target
        << " causing " << attackDamage << " points of damage !" << std::endl;
    }
    else if (energyPoints < 1)
        std::cout << "ScavTrap " << name << " can't attack, no energy points left.";
    else if (hitPoints < 1)
        std::cout << "ScavTrap " << name << " can't attack, you are dead.";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is in Gate keeper mode" << std::endl;
}
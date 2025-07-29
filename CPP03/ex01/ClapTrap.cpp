#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("theStrongest"), hitPoints(100000000), energyPoints(100000000), attackDamage(100000000)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = clapTrap;
}

ClapTrap::ClapTrap(const std::string& newName) : name(newName), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "Name constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ClapTrap)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &ClapTrap)
    {
        attackDamage = ClapTrap.attackDamage;
        hitPoints = ClapTrap.hitPoints;
        energyPoints = ClapTrap.energyPoints;
        attackDamage = ClapTrap.attackDamage;
    }
    return *this;

}

void ClapTrap::attack(const std::string& target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        energyPoints--;
        std::cout << "ClapTrap " << name << " attacks " << target
        << " causing " << attackDamage << " points of damage !" << std::endl;
    }
    else if (energyPoints < 1)
        std::cout << "ClapTrap " << name << " can't attack, no energy points left.";
    else if (hitPoints < 1)
        std::cout << "ClapTrap " << name << " can't attack, you are dead.";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints -= amount;
    std::cout << "ClapTrap " << name << " took " << amount
                << " points of damage, HP: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        energyPoints--;
        std::cout << "ClapTrap " << name << " regain " << amount << " HP." << std::endl;
        hitPoints += amount;
    }
    else if (energyPoints < 1)
        std::cout << "ClapTrap " << name << " can't repair, no energy points left.";
    else if (hitPoints < 1)
        std::cout << "ClapTrap " << name << " can't repair, you are dead.";
}
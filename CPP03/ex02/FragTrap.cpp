#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "FragTrap name constructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& FragTrap) : ClapTrap(FragTrap)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& FragTrap)
{
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &FragTrap)
        {
            ClapTrap::operator=(FragTrap);
        }
        return *this;
};

void FragTrap::attack(const std::string& target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        energyPoints--;
        std::cout << "FragTrap " << name << " attacks " << target
        << " causing " << attackDamage << " points of damage !" << std::endl;
    }
    else if (energyPoints < 1)
        std::cout << "FragTrap " << name << " can't attack, no energy points left.";
    else if (hitPoints < 1)
        std::cout << "FragTrap " << name << " can't attack, you are dead.";
}

void FragTrap::highFiveGuys(void)
{
    std::cout << "FragTrap " << name << " want a high-fives" << std::endl;
}

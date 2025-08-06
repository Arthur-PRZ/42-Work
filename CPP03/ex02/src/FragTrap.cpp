#include "../includes/FragTrap.hpp"
#include "../includes/ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    name = "defaultFragTrap";
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "FragTrap name constructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& fragTrap)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = fragTrap;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap)
{
        std::cout << "FragTrap copy assignment operator called" << std::endl;
        if (this != &fragTrap)
        {
            name = fragTrap.name;
            hitPoints = fragTrap.hitPoints;
            energyPoints = fragTrap.energyPoints;
            attackDamage = fragTrap.attackDamage;;
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
        std::cout << "FragTrap " << name << " can't attack, no energy points left." << std::endl;
    else if (hitPoints < 1)
        std::cout << "FragTrap " << name << " can't attack, you are dead." << std::endl;
}

void FragTrap::highFiveGuys(void)
{
    std::cout << "FragTrap " << name << " want a high-fives" << std::endl;
}

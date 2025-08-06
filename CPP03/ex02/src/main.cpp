#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int main()
{
    FragTrap FragTrap1("FragTrap1");
    FragTrap FragTrap2("FragTrap2");
    FragTrap FragTrapCopy(FragTrap2);

    FragTrap1.attack("ScavTrap2");
    FragTrap1.highFiveGuys();
    FragTrap2.takeDamage(100);
    FragTrap2.beRepaired(20);
    FragTrap2.attack("ScavTrap1");
    FragTrap1.takeDamage(20);

    FragTrap FragTrapEqual = FragTrap2;

    FragTrapEqual.highFiveGuys();
    FragTrapCopy.highFiveGuys();
}
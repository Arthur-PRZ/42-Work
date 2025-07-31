#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap FragTrap1("Frag");
    FragTrap FragTrap2("Trap");

    FragTrap1.attack("Trap");
    FragTrap2.takeDamage(30);
    FragTrap2.beRepaired(30);
    FragTrap2.attack("Scav");
    FragTrap1.takeDamage(30);

    FragTrap1.highFiveGuys();
    FragTrap2.highFiveGuys();
}
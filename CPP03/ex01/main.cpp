#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap ScavTrap1("Scav");
    ScavTrap ScavTrap2("Trap");

    ScavTrap1.attack("Trap");
    ScavTrap1.guardGate();
    ScavTrap2.takeDamage(20);
    ScavTrap2.beRepaired(20);
    ScavTrap2.attack("Scav");
    ScavTrap1.takeDamage(20);
}
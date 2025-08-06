#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main()
{
    ScavTrap ScavTrap1("ScavTrap1");
    ScavTrap ScavTrap2("ScavTrap2");
    ScavTrap ScavTrapCopy(ScavTrap2);

    ScavTrap1.attack("ScavTrap2");
    ScavTrap1.guardGate();
    ScavTrap2.takeDamage(100);
    ScavTrap2.beRepaired(20);
    ScavTrap2.attack("ScavTrap1");
    ScavTrap1.takeDamage(20);

    ScavTrap ScavTrapEqual = ScavTrap2;

    ScavTrapEqual.guardGate();
    ScavTrapCopy.guardGate();
}
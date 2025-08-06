#include "ClapTrap.hpp"

int main()
{
    ClapTrap ClapTrap1("ClapTrap1");
    ClapTrap ClapTrap2("ClapTrap2");
    ClapTrap ClapTrapCopy(ClapTrap2);
    ClapTrap defaultClapTrap;

    ClapTrap1.attack("ClapTrap2");
    ClapTrap2.takeDamage(3);
    ClapTrap2.beRepaired(3);
    ClapTrap2.attack("ClapTrap1");
    ClapTrap1.takeDamage(10);
    ClapTrap1.beRepaired(3);
    ClapTrap1.attack("ClapTrap2");

    ClapTrap ClapTrapEqual = ClapTrap1;

    ClapTrapCopy.attack("Claptrap2");
    ClapTrapEqual.attack("ClapTrapCopy");
    defaultClapTrap.attack("ClapTrap1");
}
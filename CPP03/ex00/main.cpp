#include "ClapTrap.hpp"

int main()
{
    ClapTrap ClapTrap1("Clap");
    ClapTrap ClapTrap2("Trap");

    ClapTrap1.attack("Trap");
    ClapTrap2.takeDamage(3);
    ClapTrap2.beRepaired(3);
    ClapTrap2.attack("Clap");
    ClapTrap1.takeDamage(3);
}
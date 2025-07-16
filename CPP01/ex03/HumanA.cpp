#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &newWeapon) : name(name), weapon(newWeapon)
{
}

HumanA::~HumanA()
{
}

void    HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
#pragma once
#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
    private :

    std::string name;
    Weapon *weapon;

    public :

    HumanB(std::string newName);
    ~HumanB();
    void    attack();
    void    setWeapon(Weapon& newWeapon);

};

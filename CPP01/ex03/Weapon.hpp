#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "Weapon.h"

class Weapon
{
    private :

    std::string type;    

    public :

    Weapon();
    ~Weapon();
    const std::string& getType();
    void    setType(std::string newType);
};

#endif
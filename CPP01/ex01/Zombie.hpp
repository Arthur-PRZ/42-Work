#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "Zombie.h"

class Zombie
{
    private :

    std::string name;

    public :

    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void    annonce(void);
    void    setName(std::string newName);
};

#endif
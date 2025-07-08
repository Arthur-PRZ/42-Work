#include "Zombie.h"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name) : name(name)
{
}

Zombie::~Zombie()
{
    std::cout << name << ": has been destruct" << std::endl;
}

void    Zombie::annonce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void  Zombie::setName(std::string newName)
{
    name = newName;
} 

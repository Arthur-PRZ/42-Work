#include "Zombie.h" 

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


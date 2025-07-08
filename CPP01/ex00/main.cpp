#include "Zombie.h"

int main()
{
    Zombie* z = newZombie("Zombie1");
    z->annonce();
    randomChump("Zombie2");
    delete z;
}
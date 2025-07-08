#include "Zombie.h"

int main()
{
    int nbrOfZombies(5);

    Zombie* horde = zombieHorde(nbrOfZombies, "Zombie");
    for (int i = 0; i < nbrOfZombies; i++)
    {
        horde[i].annonce();
    }
    delete []horde;
}
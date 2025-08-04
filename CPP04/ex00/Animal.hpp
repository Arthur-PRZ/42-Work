#include "string"
#include <iostream>

class Animal
{
    protected :

    std::string type;

    public :

    Animal();
    Animal(const Animal& animal);
    Animal& operator=(const Animal& animal);
    ~Animal();

    virtual void makeSound();
};
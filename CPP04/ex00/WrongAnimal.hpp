#include "string"
#include <iostream>

class WrongAnimal
{
    protected :

    std::string type;

    public :

    WrongAnimal();
    WrongAnimal(const WrongAnimal& wrongAnimal);
    WrongAnimal& operator=(const WrongAnimal& wrongAnimal);
    ~WrongAnimal();

    virtual void makeSound();
};
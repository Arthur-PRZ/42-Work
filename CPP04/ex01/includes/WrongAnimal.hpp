#pragma once

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
    virtual ~WrongAnimal();

    virtual void makeSound() const;
    virtual const std::string& getType() const;
};
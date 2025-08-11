#pragma once

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
    virtual ~Animal();

    virtual void makeSound() const = 0;
    virtual const std::string& getType() const;
};
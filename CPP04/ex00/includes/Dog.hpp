#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
    protected :

    std::string type;

    public :

    Dog();
    Dog(const Dog& dog);
    Dog& operator=(const Dog& dog);
    ~Dog();

    void makeSound() const;
    const std::string& getType() const;

};
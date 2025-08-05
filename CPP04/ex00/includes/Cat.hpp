#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
    protected :

    std::string type;

    public :

    Cat();
    Cat(const Cat& Cat);
    Cat& operator=(const Cat& Cat);
    ~Cat();

    void makeSound() const;
    const std::string& getType() const;
};
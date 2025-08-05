#pragma once

#include "string"
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    protected :

    std::string type;

    public :

    WrongCat();
    WrongCat(const WrongCat& wrongCat);
    WrongCat& operator=(const WrongCat& wrongCat);
    ~WrongCat();

    void makeSound() const;
    const std::string& getType() const;
};
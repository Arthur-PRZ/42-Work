#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private :

    std::string type;
    Brain* brain;

    public :

    Cat();
    Cat(const Cat& Cat);
    Cat& operator=(const Cat& Cat);
    ~Cat();

    void makeSound() const;
    const std::string& getType() const;
};
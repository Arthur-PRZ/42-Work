#include "../includes/Animal.hpp"

Animal::Animal() : type("animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& animal)
{
    std::cout << "Animal copy constructor called" << std::endl;
    type = animal.type;
}

Animal& Animal::operator=(const Animal& animal)
{
    if (this != &animal)
        type = animal.type;
    return *this;
}
Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}

const std::string& Animal::getType() const
{
    return type;
}
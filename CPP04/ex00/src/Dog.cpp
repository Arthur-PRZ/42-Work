#include "../includes/Dog.hpp"

Dog::Dog() : Animal::Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog& dog)
{
    std::cout << "Dog copy constructor called" << std::endl;
    type = dog.type;
}

Dog& Dog::operator=(const Dog& dog)
{
    if (this != &dog)
        type = dog.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Wooooff" << std::endl;
}

const std::string& Dog::getType() const
{
    return type;
}
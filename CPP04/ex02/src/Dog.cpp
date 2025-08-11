#include "../includes/Dog.hpp"

Dog::Dog() : Animal::Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog& dog)
{
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*dog.brain);
}

Dog& Dog::operator=(const Dog& dog)
{
    if (this != &dog)
    {
        type = dog.type;
        delete brain;
        brain = new Brain(*dog.brain);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << "Wooooff" << std::endl;
}

const std::string& Dog::getType() const
{
    return type;
}
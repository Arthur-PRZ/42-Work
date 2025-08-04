#include "Cat.hpp"

Cat::Cat() : Animal::Animal()
{
    std::cout << "Cat default constructor called" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat& cat)
{
    std::cout << "Cat copy constructor called" << std::endl;
    type = cat.type;
}

Cat& Cat::operator=(const Cat& cat)
{
    if (this != &cat)
        type = cat.type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void makeSound()
{
    std::cout << "Meeeeoooww" << std::endl;
}
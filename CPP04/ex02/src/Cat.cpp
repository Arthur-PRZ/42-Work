#include "../includes/Cat.hpp"

Cat::Cat() : Animal::Animal()
{
    std::cout << "Cat default constructor called" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat& cat)
{
    std::cout << "Cat copy constructor called" << std::endl;
    brain = new Brain(*cat.brain);
}

Cat& Cat::operator=(const Cat& cat)
{
    if (this != &cat)
    {
        type = cat.type;
        delete brain;
        brain = new Brain(*cat.brain);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const
{
    std::cout << "Meeeeoooww" << std::endl;
}

const std::string& Cat::getType() const
{
    return type;
}
#include "WrongCat.hpp"

WrongCat::WrongCat() : type("wrongCat")
{
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongCat)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    type = wrongCat.type;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongCat)
{
    if (this != &wrongCat)
        type = wrongCat.type;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void makeSound()
{
    std::cout << "WrongCat sound" << std::endl;
}
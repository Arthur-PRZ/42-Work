#include "../includes/WrongCat.hpp"

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

void WrongCat::makeSound() const
{
    std::cout << "WrongCat sound" << std::endl;
}

const std::string& WrongCat::getType() const
{
    return type;
}
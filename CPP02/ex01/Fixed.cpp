#include "Fixed.hpp"
#include <iostream>
#include <math.h>

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const int& other)
{
    std::cout << "Int constructor called" << std::endl;
    value = other * (1 << nbrFracionalBits);
}

Fixed::Fixed(const float& nbr)
{
    std::cout << "Float constructor called" << std::endl;
    value = roundf(nbr * (1 << nbrFracionalBits));
}

float Fixed::toFloat( void ) const
{
    return static_cast<float>(value) / (1 << nbrFracionalBits);
}

int Fixed::toInt( void ) const
{
    return value / (1 << nbrFracionalBits);
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        value = fixed.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

int Fixed::getRawBits( void ) const
{
    return value;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    value = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

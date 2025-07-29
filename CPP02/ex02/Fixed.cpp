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
    return (float)value / (1 << nbrFracionalBits);
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

bool Fixed::operator>(const Fixed& fixed) const
{
    if (this->getRawBits() > fixed.getRawBits())
        return true;
    return false;
}

bool Fixed::operator<(const Fixed& fixed) const
{
    if (this->getRawBits() < fixed.getRawBits())
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed& fixed)
{
    if (this->getRawBits() >= fixed.getRawBits())
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed& fixed)
{
    if (this->getRawBits() <= fixed.getRawBits())
        return true;
    return false;
}

bool Fixed::operator==(const Fixed& fixed)
{
    if (this->getRawBits() == fixed.getRawBits())
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed& fixed)
{
    if (this->getRawBits() != fixed.getRawBits())
        return true;
    return false;
}

Fixed Fixed::operator+(const Fixed& fixed)
{
    return (this->value + fixed.value); 
}

Fixed Fixed::operator-(const Fixed& fixed)
{
    return (this->value - fixed.value); 
}

Fixed Fixed::operator*(const Fixed& fixed)
{
    return (this->toFloat() * fixed.toFloat()); 
}

Fixed Fixed::operator/(const Fixed& fixed)
{
    return (this->toFloat() / fixed.toFloat()); 
}

Fixed& Fixed::operator++()
{
    this->value++;
    return *this; 
}

Fixed& Fixed::operator--()
{
    this->value--;
    return *this; 
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --*this;
    return temp;
}

int Fixed::getRawBits( void ) const
{
    return this->value;
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

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
    if (fixed1 < fixed2)
        return fixed1;
    return fixed2;
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
    if (fixed1 < fixed2)
        return fixed1;
    return fixed2;
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
    if (fixed1 > fixed2)
        return fixed1;
    return fixed2;
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
    if (fixed1 > fixed2)
        return fixed1;
    return fixed2;
}
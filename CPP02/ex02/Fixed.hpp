#pragma once

#include <iostream>

class Fixed
{
    private :

    int value;
    static const int nbrFracionalBits = 8;

    public :

    Fixed();
    Fixed(const Fixed& other);
    Fixed(const int& other);
    Fixed(const float& other);
    ~Fixed();

    bool operator>(const Fixed& fixed);
    bool operator<(const Fixed& fixed);
    bool operator>=(const Fixed& fixed);
    bool operator<=(const Fixed& fixed);
    bool operator==(const Fixed& fixed);
    bool operator!=(const Fixed& fixed);

    Fixed& operator=(const Fixed& fixed);
    Fixed operator+(const Fixed& fixed);
    Fixed operator-(const Fixed& fixed);
    Fixed operator*(const Fixed& fixed);
    Fixed operator/(const Fixed& fixed);

    Fixed& operator++();
    Fixed& operator--();
    Fixed& operator++(int);
    Fixed& operator--(int);

    int     toInt( void ) const;
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
    float   toFloat( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
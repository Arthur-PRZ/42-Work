#pragma once

class Fixed
{
    private :

    int nbr;
    static const int nbrFracionalBits = 8;

    public :

    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};
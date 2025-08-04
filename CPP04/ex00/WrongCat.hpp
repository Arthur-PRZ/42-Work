#include "string"
#include <iostream>

class WrongCat
{
    protected :

    std::string type;

    public :

    WrongCat();
    WrongCat(const WrongCat& wrongCat);
    WrongCat& operator=(const WrongCat& wrongCat);
    ~WrongCat();

    virtual void makeSound();
};
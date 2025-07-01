#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "phonebook.h"

class PhoneBook
{
    private :

    Contact contacts[7];
    int curr_contact;

    public :

    PhoneBook();
    void add();
    void search();
};

#endif
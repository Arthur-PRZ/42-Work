#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "PhoneBook.h"

class PhoneBook
{
    private :

    Contact contacts[8];
    int curr_contact;
    int total_contacts;

    public :

    PhoneBook();
    void add();
    void search();
};

#endif
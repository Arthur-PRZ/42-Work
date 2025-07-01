#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "phonebook.h"

class Contact
{
    private :

    string	firstName;
    string	lastName;
	string	nickname;
	string	darkestSecret;
    string	phoneNbr;


	public :

	Contact();
	void	setFirstName(string newFirstName);
	void	setLastName(string newLastName);
	void	setNickname(string newNickname);
	void	setDarkestSecret(string newDarksetSecret);
	void	setPhoneNbr(string newPhoneNbr);
	// void getContactInfo();
	// void changeName(string name);
	// void changePhoneNbr(int phoneNbr);
};

#endif
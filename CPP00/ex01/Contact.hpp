#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "PhoneBook.h"

class Contact
{
    private :

    std::string	firstName;
    std::string	lastName;
	std::string	nickname;
	std::string	darkestSecret;
    std::string	phoneNbr;


	public :

	Contact();
	void	setFirstName(std::string newFirstName);
	void	setLastName(std::string newLastName);
	void	setNickname(std::string newNickname);
	void	setDarkestSecret(std::string newDarksetSecret);
	void	setPhoneNbr(std::string newPhoneNbr);
	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickname();
	std::string	getDarkestSecret();
	std::string	getPhoneNbr();
};

#endif
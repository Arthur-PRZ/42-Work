#include "phonebook.h"

PhoneBook::PhoneBook() : curr_contact(0)
{
}

void PhoneBook::add()
{
    string  input;

    std::cout << "Please enter the first name" << std::endl;
    cin >> input;
    contacts[curr_contact].setFirstName(input);

    std::cout << "Please enter the last name" << std::endl;
    cin >> input;
    contacts[curr_contact].setLastName(input);

    std::cout << "Please enter the nickname" << std::endl;
    cin >> input;
    contacts[curr_contact].setNickname(input);

    std::cout << "Please enter the darkest secret" << std::endl;
    cin >> input;
    contacts[curr_contact].setDarkestSecret(input);

    std::cout << "Please enter the phone nbr" << std::endl;
    cin >> input;
    contacts[curr_contact].setPhoneNbr(input);

    curr_contact = (curr_contact + 1) % 8;    
}

void PhoneBook::search()
{

}

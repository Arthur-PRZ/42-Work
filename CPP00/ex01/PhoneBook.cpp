#include "PhoneBook.h"
#include "using.h"

PhoneBook::PhoneBook() : curr_contact(0), total_contacts(0)
{
}

void checkInput(string &str)
{
    while(str[0] == '\0')
    {
        cout << "Invalid input, please enter a valid one" << endl;
        getline(cin, str);
    }
}

static bool checkNbr(string input)
{
    for (int i = 0; input[i]; i++)
    {
        if (input[i] && (input[i] < '0' || input[i] > '9'))
            return false;
    }
    return true;
}

void PhoneBook::add()
{
    string firstName, lastName, nickname, darkestSecret, phoneNbr;

    std::cout << "Please enter the first name" << std::endl;
    getline(cin, firstName);
    checkInput(firstName);

    std::cout << "Please enter the last name" << std::endl;
    getline(cin, lastName);
    checkInput(lastName);

    std::cout << "Please enter the nickname" << std::endl;
    getline(cin, nickname);
    checkInput(nickname);

    std::cout << "Please enter the phone nbr" << std::endl;
    getline(cin, phoneNbr);
    checkInput(phoneNbr);
    while (!checkNbr(phoneNbr))
    {
        std::cout << "Please enter a right phone nbr" << std::endl;
        getline(cin, phoneNbr);
        checkInput(phoneNbr);
    }

    std::cout << "Please enter the darkest secret" << std::endl;
    getline(cin, darkestSecret);
    checkInput(darkestSecret);

    contacts[curr_contact].setFirstName(firstName);
    contacts[curr_contact].setLastName(lastName);
    contacts[curr_contact].setNickname(nickname);
    contacts[curr_contact].setPhoneNbr(phoneNbr);
    contacts[curr_contact].setDarkestSecret(darkestSecret);

    curr_contact = (curr_contact + 1) % 8;    
    if (total_contacts < 8)
        total_contacts++;    
}

string truncate10(const string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::search()
{
    string  input;
    int     index;

    cout << "Contacts:"  << endl;
    for (int i = 0; i < total_contacts; i++)
    {
        cout << setw(10) << i << "|";
        cout << setw(10) << truncate10(contacts[i].getFirstName()) << "|";
        cout << setw(10) << truncate10(contacts[i].getLastName()) << "|";
        cout << setw(10) << truncate10(contacts[i].getNickname()) << endl;
    }
    cout << "Enter the index of the contact you want more informations" << endl;
    getline(cin, input);
    checkInput(input);
    std::stringstream iss(input);
    if (!(iss >> index))
        cout << "Index invalid" << endl;
    else if (index >= 0 && index < total_contacts && total_contacts != 0)
    {
        cout << "Contact first name: " << contacts[index].getFirstName() << endl;
        cout << "Contact last name: " << contacts[index].getLastName() << endl;
        cout << "Contact nickname: " << contacts[index].getNickname() << endl;
        cout << "Contact darkest secret: " << contacts[index].getDarkestSecret() << endl;
        cout << "Contact phone number: " << contacts[index].getPhoneNbr() << endl;
    }
    else
        cout << "Index invalid" << endl;
}

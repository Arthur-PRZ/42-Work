#include "phonebook.h"
#include "using.h"

PhoneBook::PhoneBook() : curr_contact(0), total_contacts(0)
{
}

static void checkInput(string &str)
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
    string  input;

    std::cout << "Please enter the first name" << std::endl;
    getline(cin, input);
    checkInput(input);
    contacts[curr_contact].setFirstName(input);

    std::cout << "Please enter the last name" << std::endl;
    getline(cin, input);
    checkInput(input);
    contacts[curr_contact].setLastName(input);

    std::cout << "Please enter the nickname" << std::endl;
    getline(cin, input);
    checkInput(input);
    contacts[curr_contact].setNickname(input);

    std::cout << "Please enter the darkest secret" << std::endl;
    getline(cin, input);
    checkInput(input);
    contacts[curr_contact].setDarkestSecret(input);

    std::cout << "Please enter the phone nbr" << std::endl;
    getline(cin, input);
    checkInput(input);
    while (!checkNbr(input))
    {
        std::cout << "Please enter a right phone nbr" << std::endl;
        getline(cin, input);
        checkInput(input);
    }
    contacts[curr_contact].setPhoneNbr(input);

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

#include "phonebook.h"
#include "using.h"

Contact::Contact() : firstName("unknow"), lastName("unknow"), nickname("unknow"),
    darkestSecret("unknow"), phoneNbr("-1")
{
}

void    Contact::setFirstName(string newFirstName)
{
    firstName = newFirstName;
}

void    Contact::setLastName(string newLastName)
{
    lastName = newLastName;
}
void    Contact::setNickname(string newNickname)
{
    nickname = newNickname;
}

void    Contact::setDarkestSecret(string newDarkestSecret)
{
    darkestSecret = newDarkestSecret;
}

void    Contact::setPhoneNbr(string newPhoneNbr)
{
    phoneNbr = newPhoneNbr;
}

string    Contact::getFirstName()
{
    return firstName;
}

string    Contact::getLastName()
{
    return lastName;
}
string    Contact::getNickname()
{
    return nickname;
}

string    Contact::getDarkestSecret()
{
    return darkestSecret;
}

string    Contact::getPhoneNbr()
{
    return phoneNbr;
}

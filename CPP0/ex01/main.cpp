#include "phonebook.h"

int main(void)
{
    PhoneBook phoneBook;
	string	input;

	cout << "CMD available : ADD, SEARCH, EXIT" << endl;
	cin >> input;
	while (input != "EXIT")
	{
		if (input == "ADD")
			phoneBook.add();
		else if (input == "SEARCH")
			phoneBook.search();
		cout << "CMD available : ADD, SEARCH, EXIT" << endl;
		cin >> input;
	}
}
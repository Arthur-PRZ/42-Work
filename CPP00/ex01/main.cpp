#include "PhoneBook.h"
#include "using.h"

int main(void)
{
    PhoneBook phoneBook;
	string	input;

	cout << "CMD available : ADD, SEARCH, EXIT" << endl;
	if (!getline(cin, input))
		std::exit(0);
	while (input != "EXIT")
	{
		if (input == "ADD")
			phoneBook.add();
		else if (input == "SEARCH")
			phoneBook.search();
		cout << "CMD available : ADD, SEARCH, EXIT" << endl;
		if (!getline(cin, input))
			std::exit(0);
	}
}
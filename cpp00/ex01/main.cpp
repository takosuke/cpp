#include <string>
#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"


int	main() {
	std::string command;
	bool	exit = false;
	PhoneBook thePhoneBook;

	while (!exit)
	{
		std::cout << "Please input one of the following commands:\nADD\nSEARCH\nEXIT\n===========================" << std::endl;
		if (!(std::getline(std::cin, command)))
			return (1);
		if (command == "ADD")
			thePhoneBook.addContact();
		else if (command == "SEARCH")
			thePhoneBook.searchContact();
		else if (command == "LIST")
			thePhoneBook.listContacts();
		else if (command == "EXIT" || std::cin.eof())
		{
			std::cout << "Bye bye" << std::endl;
			exit = true;
		}
	}
	return 0;
}



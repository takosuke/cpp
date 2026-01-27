#include "PhoneBook.hpp"
#include <filesystem>
#include <ios>
#include <limits>
#include <string>
#include <iostream>

PhoneBook::PhoneBook() : _index(0), _last(-1) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(void)
{
	std::string	input;

	_last = _index;
	_contacts[_index].setInfo();
	_contacts[_index].displayContact(_index);
	std::cout << "Contact nr " << _index <<  " Added" << std::endl;
	if (_index < 7)
		_index++;
}

void PhoneBook::searchContact(void)
{
	int	index;

	if (_index == 0)
	{
		std::cout << "No contacts yet please add some first" << std::endl;
		return ;
	}
	std::cout << "Select a contact by index [0 - " << _last << "]" << std::endl;
	if (!(std::cin >> index ))
		std::cout << "Error" << std::endl;
	if (index > _last || index < 0)
	{
		std::cout << "Error: Index not in range" << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	_contacts[index].displayContact(index);
}

void PhoneBook::listContacts(void)
{
	if (_index > 0)
	{
		std::cout << "LIST OF CONTACTS: " << std::endl;
		for (int i = 0; i <= _last; i++)
			_contacts[i].displayContact(i);
	}
	else
		std::cout << "No contacts in the phone book please add some" << std::endl;
}

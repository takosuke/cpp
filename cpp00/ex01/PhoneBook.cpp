#include "PhoneBook.hpp"
#include <limits>
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : _index(0), _count(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(void)
{
	if (!_contacts[_index].isEmpty())
	{
		std::cout << COLOR_YELLOW << "Erasing contact "
			<< _contacts[_index].getFirstName() << " "
			<< _contacts[_index].getLastName()
			<< " with index " << _index << COLOR_RESET << std::endl;
	}
	_contacts[_index].setInfo();
	std::cout << COLOR_GREEN << "Contact #" << _index << " added successfully!" << COLOR_RESET << std::endl;
	_index = (_index + 1) % 8;
	if (_count < 8)
		_count++;
}

void PhoneBook::searchContact(void)
{
	int	index;

	if (_count == 0)
	{
		std::cout << COLOR_RED << "No contacts yet! Please add some first." << COLOR_RESET << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << COLOR_CYAN << "+----------+----------+----------+----------+" << COLOR_RESET << std::endl;
	std::cout << COLOR_CYAN << "|" << std::setw(10) << "Index"
		<< "|" << std::setw(10) << "First Name"
		<< "|" << std::setw(10) << "Last Name"
		<< "|" << std::setw(10) << "Nickname" << "|" << COLOR_RESET << std::endl;
	std::cout << COLOR_CYAN << "+----------+----------+----------+----------+" << COLOR_RESET << std::endl;
	for (int i = 0; i < _count; i++)
		_contacts[i].displayContactRow(i);
	std::cout << COLOR_CYAN << "+----------+----------+----------+----------+" << COLOR_RESET << std::endl;
	std::cout << std::endl;
	std::cout << COLOR_CYAN << "Select a contact by index [0 - " << (_count - 1) << "]: " << COLOR_RESET;
	if (!(std::cin >> index))
	{
		std::cout << COLOR_RED << "Invalid input!" << COLOR_RESET << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (index < 0 || index >= _count)
	{
		std::cout << COLOR_RED << "Index out of range!" << COLOR_RESET << std::endl;
		return ;
	}
	_contacts[index].displayContactFull(index);
}

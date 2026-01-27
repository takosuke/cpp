#include "PhoneBook.hpp"
#include <ios>
#include <limits>

PhoneBook::PhoneBook()
{
	this->_index = 0;
}

PhoneBook::~PhoneBook()
{}

void PhoneBook::addContact(void)
{
	std::string	input;

	std::cout << "Insert first name: " << std::endl;
	while (true)
	{
		if (std::getline(std::cin, input))
		{
			if (input.empty())
			{
				std::cout << "field cannot be empty" << std::endl;
				continue;
			}
			else
			{
				this->_contacts[this->_index].setFirstName(input);
				break ;
			}
		}
	}
	std::cout << "Insert last name: " << std::endl;
	while (true)
	{
		if (std::getline(std::cin, input))
		{
			if (input.empty())
			{
				std::cout << "field cannot be empty" << std::endl;
				continue;
			}
			else
			{
				this->_contacts[this->_index].setLastName(input);
				break ;
			}
		}
	}
	std::cout << "Insert nickname: " << std::endl;
	while (true)
	{
		if (std::getline(std::cin, input))
		{
			if (input.empty())
			{
				std::cout << "field cannot be empty" << std::endl;
				continue;
			}
			else
			{
				this->_contacts[this->_index].setNickName(input);
				break ;
			}
		}
	}
	std::cout << "Insert phone number: " << std::endl;
	while (true)
	{
		if (std::getline(std::cin, input))
		{
			if (input.empty())
			{
				std::cout << "field cannot be empty" << std::endl;
				continue;
			}
			else
			{
				this->_contacts[this->_index].setPhoneNr(input);
				break ;
			}
		}
	}
	std::cout << "Tell me your darkest secret: " << std::endl;
	while (true)
	{
		if (std::getline(std::cin, input))
		{
			if (input.empty())
			{
				std::cout << "field cannot be empty" << std::endl;
				continue;
			}
			else
			{
				this->_contacts[this->_index].setDarkestSecret(input);
				break ;
			}
		}
	}
	this->_contacts[this->_index].displayContact(_index);
	std::cout << "Contact Added" << std::endl;
	if (this->_index < 7)
		this->_index++;
}

void PhoneBook::searchContact(void)
{
	int	index;

	if (this->_index == 0)
	{
		std::cout << "No contacts yet please add some first" << std::endl;
		return ;
	}
	std::cout << "Select a contact by index [0 - " << this->_index - 1 << "]" << std::endl;
	if (!(std::cin >> index ))
		std::cout << "Error" << std::endl;
	if (index > this->_index - 1 || index < 0)
	{
		std::cout << "Error: Index not in range" << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	this->_contacts[index].displayContact(index);
}

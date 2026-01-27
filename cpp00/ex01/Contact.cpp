#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include "utils.hpp"

Contact::Contact() {}
Contact::~Contact()
{}

std::string Contact::addContactField(std::string msg)
{
	std::string	input;

	std::cout << msg << std::endl;
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
				break ;
		}
	}
	return (input);
}

void	Contact::setInfo()
{
	_first_name = Contact::addContactField("Enter your first name: ");
	_last_name = Contact::addContactField("Enter your last name: ");
	_nickname = Contact::addContactField("Enter your nickname: ");
	_phone_nr = Contact::addContactField("Enter your phone number: ");
	_darkest_secret = Contact::addContactField("Tell me your darkest secret: ");
}

void	Contact::displayContact(int index)
{
	std::cout << std::setw(10) <<  index << "|";
	std::cout << std::setw(10) << truncate(_first_name, 10) << "|";
	std::cout << std::setw(10) << truncate(_last_name, 10) << "|";
	std::cout << std::setw(10) << truncate(_nickname, 10) << std::endl;
}

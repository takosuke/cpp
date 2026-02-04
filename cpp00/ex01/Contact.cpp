#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

Contact::Contact() {}
Contact::~Contact() {}

std::string Contact::truncate(const std::string& str, size_t max)
{
	if (str.length() <= max)
		return str;
	std::string truncated = str.substr(0, max - 1);
	truncated += '.';
	return truncated;
}

bool Contact::isValidPhoneNumber(const std::string& phone)
{
	for (size_t i = 0; i < phone.length(); i++)
	{
		char c = phone[i];
		if (!((c >= '0' && c <= '9') || c == '+' || c == '-'))
			return false;
	}
	return true;
}

std::string Contact::addContactField(std::string msg, bool isPhone)
{
	std::string	input;

	std::cout << COLOR_CYAN << msg << COLOR_RESET << std::endl;
	while (true)
	{
		std::cout << COLOR_YELLOW << "> " << COLOR_RESET;
		if (std::getline(std::cin, input))
		{
			if (input.empty())
			{
				std::cout << COLOR_RED << "Field cannot be empty!" << COLOR_RESET << std::endl;
				continue;
			}
			if (isPhone && !isValidPhoneNumber(input))
			{
				std::cout << COLOR_RED << "Invalid phone number! Only digits, '+' and '-' allowed." << COLOR_RESET << std::endl;
				continue;
			}
			break ;
		}
		else
			return "";
	}
	return (input);
}

void	Contact::setInfo()
{
	_first_name = Contact::addContactField("Enter first name:", false);
	_last_name = Contact::addContactField("Enter last name:", false);
	_nickname = Contact::addContactField("Enter nickname:", false);
	_phone_nr = Contact::addContactField("Enter phone number:", true);
	_darkest_secret = Contact::addContactField("Tell me your darkest secret:", false);
}

std::string Contact::getFirstName(void) const
{
	return _first_name;
}

std::string Contact::getLastName(void) const
{
	return _last_name;
}

bool Contact::isEmpty(void) const
{
	return _first_name.empty();
}

void	Contact::displayContactRow(int index) const
{
	std::cout << COLOR_WHITE << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << truncate(_first_name, 10);
	std::cout << "|" << std::setw(10) << truncate(_last_name, 10);
	std::cout << "|" << std::setw(10) << truncate(_nickname, 10);
	std::cout << "|" << COLOR_RESET << std::endl;
}

void	Contact::displayContactFull(int index) const
{
	std::cout << std::endl;
	std::cout << COLOR_BOLD << COLOR_CYAN << "  Contact Details #" << index << COLOR_RESET << std::endl;
	std::cout << COLOR_CYAN << "  ===================" << COLOR_RESET << std::endl;
	std::cout << COLOR_GREEN << "  First Name     : " << COLOR_WHITE << _first_name << COLOR_RESET << std::endl;
	std::cout << COLOR_GREEN << "  Last Name      : " << COLOR_WHITE << _last_name << COLOR_RESET << std::endl;
	std::cout << COLOR_GREEN << "  Nickname       : " << COLOR_WHITE << _nickname << COLOR_RESET << std::endl;
	std::cout << COLOR_GREEN << "  Phone Number   : " << COLOR_WHITE << _phone_nr << COLOR_RESET << std::endl;
	std::cout << COLOR_GREEN << "  Darkest Secret : " << COLOR_WHITE << _darkest_secret << COLOR_RESET << std::endl;
	std::cout << std::endl;
}

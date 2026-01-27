#include "Contact.hpp"


Contact::Contact()
{}

Contact::~Contact()
{}

void	Contact::setFirstName(const std::string& firstName)
{
	this->_first_name = firstName;
}

void	Contact::setLastName(const std::string& lastName)
{
	this->_last_name = lastName;
}

void	Contact::setNickName(const std::string& nickName)
{
	this->_nickname = nickName;
}

void	Contact::setPhoneNr(const std::string& phoneNr)
{
	this->_phone_nr = phoneNr;
}

void	Contact::setDarkestSecret(const std::string& darkestSecret)
{
	this->_darkest_secret = darkestSecret;
}

void	Contact::displayContact(int index)
{
	std::cout << std::setw(10) <<  index << "|";
	std::cout << std::setw(10) << truncate(this->_first_name, 10) << "|";
	std::cout << std::setw(10) << truncate(this->_last_name, 10) << "|";
	std::cout << std::setw(10) << truncate(this->_nickname, 10) << std::endl;
}

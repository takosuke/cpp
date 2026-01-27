#pragma once

#include <string>

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_nr;
		std::string _darkest_secret;
	public:
		Contact();
		~Contact();

		std::string	addContactField(std::string msg);
		void	setInfo();
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickName(void);
		void displayContact(int index);
};

#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <iostream>
#include <iomanip>
#include "utils.hpp"

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
		void setFirstName(const std::string& firstName);
		void setLastName(const std::string& lastName);
		void setNickName(const std::string& nickName);
		void setPhoneNr(const std::string& phoneNr);
		void setDarkestSecret(const std::string& darkestSecret);
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickName(void);
		void displayContact(int index);
};
#endif

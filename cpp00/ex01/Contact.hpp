#ifndef CONTACT_H
#define CONTACT_H

#include <string>

#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_WHITE   "\033[37m"
#define COLOR_BOLD    "\033[1m"

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_nr;
		std::string _darkest_secret;

		static std::string truncate(const std::string& str, size_t max);
		static bool isValidPhoneNumber(const std::string& phone);

	public:
		Contact();
		~Contact();

		std::string	addContactField(std::string msg, bool isPhone);
		void		setInfo();
		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		bool		isEmpty(void) const;
		void		displayContactRow(int index) const;
		void		displayContactFull(int index) const;
};

#endif

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
private:
	Contact	_contacts[8];
	int		_index;
	int		_count;
public:
	PhoneBook();
	~PhoneBook();
	void addContact(void);
	void searchContact(void);
};

#endif

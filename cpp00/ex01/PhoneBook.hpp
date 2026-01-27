#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include "utils.hpp"

class PhoneBook {
private:
	Contact	_contacts[8];
	int	_index;
	int	_last;
public: 
	PhoneBook();
	~PhoneBook();
	void addContact(void);
	void searchContact(void);
	void listContacts(void);
	};

#endif

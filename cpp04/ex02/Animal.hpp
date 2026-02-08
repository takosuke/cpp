#pragma once
#include <iostream>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal& a);
		Animal& operator=(const Animal& a);
		virtual ~Animal(void);

		std::string getType(void) const;
		virtual void makeSound(void) const = 0;
};

#pragma once
#include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& a);
		WrongAnimal& operator=(const WrongAnimal& a);
		~WrongAnimal(void);

		std::string getType(void) const;
		void makeSound(void) const;
};

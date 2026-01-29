#pragma once
#include "Animal.hpp"

class Dog : public Animal
{

	public:
		Dog(void);
		Dog(const Dog& c);
		Dog& operator=(const Dog& c);
		~Dog(void);

		void makeSound(void) const;
};

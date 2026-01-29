#pragma once
#include "Animal.hpp"

class Cat : public Animal
{

	public:
		Cat(void);
		Cat(const Cat& c);
		Cat& operator=(const Cat& c);
		~Cat(void);

		void makeSound(void) const;
};

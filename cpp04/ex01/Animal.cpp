#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "animal base default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "animal base parametrized constructor called" << std::endl;
}

Animal::Animal(const Animal& a)
{
	*this = a;
	std::cout << "animal base copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& a)
{
	if (this != &a)
		_type = a._type;
	std::cout << "animal base assignment operator called" << std::endl;
	return *this;
}
Animal::~Animal(void)
{
	std::cout << "animal base destructor called" << std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << "I'm not a real animal so I only make imaginary sounds" << std::endl;
}

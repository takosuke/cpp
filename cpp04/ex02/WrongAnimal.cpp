#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "wrong animal base default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "wrong animal base parametrized constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& a): _type(a._type)
{
	std::cout << "wrong animal base copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a)
{
	if (this != &a)
		_type = a._type;
	std::cout << "wrong animal base assignment operator called" << std::endl;
	return *this;
}
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "wrong animal base destructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return _type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "I'm not even a real wrong animal so I only make wrong imaginary sounds" << std::endl;
}

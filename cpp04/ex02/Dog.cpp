#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
	_brain = new Brain();
	_brain->ideas[0] = "I love bones";
	_brain->ideas[1] = "Chase the mailman";
}

Dog::Dog(const Dog& c) : Animal(c)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain(*c._brain);
}

Dog& Dog::operator=(const Dog& c)
{
	if (this != &c)
	{
		this->_type = c._type;
		delete this->_brain;
		this->_brain = new Brain(*c._brain);
	}
	std::cout << "Dog copy operator called" << std::endl;
	return *this;
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "GUAU" << std::endl;
}

Brain* Dog::getBrain(void) const
{
	return _brain;
}

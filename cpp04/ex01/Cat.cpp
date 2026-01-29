#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
	_brain = new Brain();
	_brain->ideas[0] = "I hate mondays";
	_brain->ideas[1] = "Yum catnip";
}

Cat::Cat(const Cat& c) : Animal(c)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain(*c._brain);
}

Cat& Cat::operator=(const Cat& c)
{
	if (this != &c)
	{
		this->_type = c._type;
		delete this->_brain;
		this->_brain = new Brain(*c._brain);
	}
	std::cout << "Cat copy operator called" << std::endl;
	return *this;
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "MIAU" << std::endl;
}

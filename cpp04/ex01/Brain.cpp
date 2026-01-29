#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &b)
{
	*this = b;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &b)
{
	if (this != &b)
	{
		for (int i = 0; i < 100; i++)
		{
			if (this->ideas[i] != b.ideas[i])
				this->ideas[i] = b.ideas[i];
		}
	}
	std::cout << "Brain copy assignment constructor called." << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

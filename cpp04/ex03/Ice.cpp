#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}
Ice::Ice(const Ice& ice) : AMateria(ice) {}
Ice& Ice::operator=(const Ice& ice)
{
	if (this != &ice)
		_type = ice.getType();
	return *this;
}

Ice::~Ice() {}

Ice* Ice::clone() const
{
	Ice* ice = new Ice(*this);
	return ice;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

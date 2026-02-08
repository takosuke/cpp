#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}
Cure::Cure(const Cure& cure) : AMateria(cure) {}
Cure& Cure::operator=(const Cure& cure)
{
	if (this != &cure)
		_type = cure.getType();
	return *this;
}

Cure::~Cure() {}

Cure* Cure::clone() const
{
	Cure* cure = new Cure(*this);
	return cure;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

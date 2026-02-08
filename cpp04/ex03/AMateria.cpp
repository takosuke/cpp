#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria& am) : _type(am._type) {
}

AMateria& AMateria::operator=(const AMateria& am)
{
	if (this != &am)
		_type = am._type;
	return *this;
}

AMateria::~AMateria() {}

std::string const& AMateria::getType() const 
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}

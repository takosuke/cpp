#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure& cure);
		Cure &operator=(const Cure& cure);
		~Cure();

		Cure* clone() const;
		void use(ICharacter& target);
};

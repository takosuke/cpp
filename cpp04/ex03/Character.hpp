#pragma once
#include "ICharacter.hpp"
#include <string>

class AMateria;

class Character : public ICharacter {

	private:
		const static int _max = 4;
		std::string _name;
		AMateria* _materia[_max];
		AMateria* _garbage[100];
		int _garbage_count;

	public:
		Character();
		Character(std::string name);
		Character(const Character& ch);
		Character &operator=(const Character& ch);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

};

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("Default Character"), _garbage_count(0)
{
	for (int i = 0; i < _max; i++)
		_materia[i] = NULL;
	for (int i = 0; i < 100; i++)
		_garbage[i] = NULL;
}

Character::Character(std::string name) : _name(name), _garbage_count(0)
{
	for (int i = 0; i < _max; i++)
		_materia[i] = NULL;
	for (int i = 0; i < 100; i++)
		_garbage[i] = NULL;
}

Character::Character(const Character& ch)
{
	_name = ch._name;
	_garbage_count = 0;
	for (int i = 0; i < _max; i++)
	{
		if (ch._materia[i] != NULL)
			_materia[i] = ch._materia[i]->clone();
		else
			_materia[i] = NULL;
	}
	for (int i = 0; i < 100; i++)
		_garbage[i] = NULL;
}

Character& Character::operator=(const Character& ch)
{
	if (this != &ch)
	{
		_name = ch._name;
		// dont know if this is necessary
		for (int i = 0; i < _max; i++)
		{
			delete _materia[i];
			_materia[i] = NULL;
		}
		for (int i = 0; i < _max; i++)
		{
			if (ch._materia[i] != NULL)
				_materia[i] = ch._materia[i]->clone();
			else
				_materia[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < _max; i++)
		delete _materia[i];
	for (int i = 0; i < _garbage_count; i++)
		delete _garbage[i];
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < _max; i++)
	{
		if (_materia[i] == NULL)
		{
			_materia[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= _max || _materia[idx] == NULL)
		return ;
	_garbage[_garbage_count++] = _materia[idx];
	_materia[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= _max || _materia[idx] == NULL)
		return ;
	_materia[idx]->use(target);
}

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < _max; i++)
		_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& ms)
{
	for (int i = 0; i < _max; i++)
	{
		if (_materia[i])
			_materia[i] = ms._materia[i]->clone();
		else
			_materia[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ms)
{
	if (this != &ms)
	{
		// dont know if this is necessary
		for (int i = 0; i < _max; i++)
		{
			delete _materia[i];
			_materia[i] = NULL;
		}
		for (int i = 0; i < _max; i++)
		{
			if (_materia[i])
				_materia[i] = ms._materia[i]->clone();
			else
				_materia[i] = NULL;
		}
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < _max; i++)
	{
		delete _materia[i];
	}
}

void learnMateria(AMateria*)
{
	j
}

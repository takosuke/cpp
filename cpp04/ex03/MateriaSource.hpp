#include "IMateriaSource.hpp"
#include <string>

class MateriaSource: public IMateriaSource
{
	private:
		const static int _max = 4;
		AMateria* _materia[_max];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& ms);
		MateriaSource& operator=(const MateriaSource& ms);
		~MateriaSource();

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

};

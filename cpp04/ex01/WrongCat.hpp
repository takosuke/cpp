#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

	public:
		WrongCat(void);
		WrongCat(const WrongCat& c);
		WrongCat& operator=(const WrongCat& c);
		~WrongCat(void);
};

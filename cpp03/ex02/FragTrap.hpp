#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& ft);
		FragTrap& operator=(const FragTrap& ft);
		~FragTrap(void);
	
		void highFiveGuys(void);
};

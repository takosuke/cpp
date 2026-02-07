#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& st);
		ScavTrap& operator=(const ScavTrap& st);
		~ScavTrap(void);
		
		void attack(const std::string& target);
		void guardGate(void);
};

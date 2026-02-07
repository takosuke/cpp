#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& dt);
		DiamondTrap& operator=(const DiamondTrap& dt);
		~DiamondTrap(void);

		void attack(const std::string& target);
		void whoAmI();
};

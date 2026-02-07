#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== DiamondTrap Orthodox Canonical Form ===" << std::endl;
	{
		DiamondTrap a;
		DiamondTrap b("Bravo");
		DiamondTrap c(b);
		DiamondTrap d;
		d = b;
	}
	std::cout << std::endl;

	std::cout << "=== DiamondTrap stats check (HP:100 EP:50 DMG:30) ===" << std::endl;
	{
		DiamondTrap dt("Diamond");
		std::cout << "HP: " << dt.getHp()
			<< " EP: " << dt.getEp()
			<< " DMG: " << dt.getDamage() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== Construction/destruction chaining ===" << std::endl;
	{
		std::cout << "-- Creating ClapTrap --" << std::endl;
		ClapTrap ct("BaseBot", 10, 10, 0);
		std::cout << "-- Creating ScavTrap --" << std::endl;
		ScavTrap sv("ScavBot");
		std::cout << "-- Creating FragTrap --" << std::endl;
		FragTrap ft("FragBot");
		std::cout << "-- Creating DiamondTrap --" << std::endl;
		DiamondTrap dt("DiaBot");
		std::cout << "-- Leaving scope --" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== DiamondTrap whoAmI ===" << std::endl;
	{
		DiamondTrap dt("Hero");
		dt.whoAmI();
	}
	std::cout << std::endl;

	std::cout << "=== DiamondTrap attack (uses ScavTrap) ===" << std::endl;
	{
		DiamondTrap dt("Attacker");
		dt.attack("Enemy");
	}
	std::cout << std::endl;

	std::cout << "=== DiamondTrap combat ===" << std::endl;
	{
		DiamondTrap dt("Tank");
		dt.attack("Enemy");
		dt.takeDamage(30);
		std::cout << "HP after 30 dmg: " << dt.getHp() << std::endl;
		dt.beRepaired(10);
		std::cout << "HP after repair 10: " << dt.getHp() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== DiamondTrap special abilities ===" << std::endl;
	{
		DiamondTrap dt("Multi");
		dt.guardGate();
		dt.highFiveGuys();
	}
}

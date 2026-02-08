#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

int main(void)
{
	std::cout << YELLOW << "=== DiamondTrap Orthodox Canonical Form ===" << RESET << std::endl;
	{
		DiamondTrap a;
		DiamondTrap b("Bravo");
		DiamondTrap c(b);
		DiamondTrap d;
		d = b;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== DiamondTrap stats check (HP:100 EP:50 DMG:30) ===" << RESET << std::endl;
	{
		DiamondTrap dt("Diamond");
		std::cout << "HP: " << dt.getHp()
			<< " EP: " << dt.getEp()
			<< " DMG: " << dt.getDamage() << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== Construction/destruction chaining ===" << RESET << std::endl;
	{
		std::cout << YELLOW << "-- Creating ClapTrap --" << RESET << std::endl;
		ClapTrap ct("BaseBot", 10, 10, 0);
		std::cout << YELLOW << "-- Creating ScavTrap --" << RESET << std::endl;
		ScavTrap sv("ScavBot");
		std::cout << YELLOW << "-- Creating FragTrap --" << RESET << std::endl;
		FragTrap ft("FragBot");
		std::cout << YELLOW << "-- Creating DiamondTrap --" << RESET << std::endl;
		DiamondTrap dt("DiaBot");
		std::cout << YELLOW << "-- Leaving scope --" << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== DiamondTrap whoAmI ===" << RESET << std::endl;
	{
		DiamondTrap dt("Hero");
		dt.whoAmI();
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== DiamondTrap attack (uses ScavTrap) ===" << RESET << std::endl;
	{
		DiamondTrap dt("Attacker");
		dt.attack("Enemy");
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== DiamondTrap combat ===" << RESET << std::endl;
	{
		DiamondTrap dt("Tank");
		dt.attack("Enemy");
		dt.takeDamage(30);
		std::cout << "HP after 30 dmg: " << dt.getHp() << std::endl;
		dt.beRepaired(10);
		std::cout << "HP after repair 10: " << dt.getHp() << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== DiamondTrap special abilities ===" << RESET << std::endl;
	{
		DiamondTrap dt("Multi");
		dt.guardGate();
		dt.highFiveGuys();
	}
}

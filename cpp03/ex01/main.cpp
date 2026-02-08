#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

int main(void)
{
	std::cout << YELLOW << "=== ScavTrap Orthodox Canonical Form ===" << RESET << std::endl;
	{
		ScavTrap a;
		ScavTrap b("Bravo");
		ScavTrap c(b);
		ScavTrap d;
		d = b;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== ScavTrap stats check ===" << RESET << std::endl;
	{
		ScavTrap sv("Scout");
		std::cout << "HP: " << sv.getHp()
			<< " EP: " << sv.getEp()
			<< " DMG: " << sv.getDamage() << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== Construction/destruction chaining ===" << RESET << std::endl;
	{
		std::cout << YELLOW << "-- Creating ClapTrap --" << RESET << std::endl;
		ClapTrap ct("BaseBot", 10, 10, 0);
		std::cout << YELLOW << "-- Creating ScavTrap --" << RESET << std::endl;
		ScavTrap sv("DerivedBot");
		std::cout << YELLOW << "-- Leaving scope --" << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== ScavTrap special ability ===" << RESET << std::endl;
	{
		ScavTrap guard("Guardian");
		guard.guardGate();
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== ScavTrap combat ===" << RESET << std::endl;
	{
		ScavTrap tank("Tank");
		tank.attack("Enemy");
		tank.takeDamage(30);
		std::cout << "HP after 30 dmg: " << tank.getHp() << std::endl;
		tank.beRepaired(10);
		std::cout << "HP after repair 10: " << tank.getHp() << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== ScavTrap energy depletion (50 EP) ===" << RESET << std::endl;
	{
		ScavTrap bot("Energetic");
		for (int i = 0; i < 50; i++)
			bot.attack("Target");
		std::cout << "EP after 50 attacks: " << bot.getEp() << std::endl;
		bot.attack("Target");
		bot.beRepaired(1);
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== ScavTrap overkill ===" << RESET << std::endl;
	{
		ScavTrap bot("Fragile");
		bot.takeDamage(100);
		std::cout << "HP: " << bot.getHp() << std::endl;
		bot.attack("Ghost");
		bot.beRepaired(50);
		bot.takeDamage(1);
	}
}

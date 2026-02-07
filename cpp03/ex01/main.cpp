#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== ScavTrap Orthodox Canonical Form ===" << std::endl;
	{
		ScavTrap a;
		ScavTrap b("Bravo");
		ScavTrap c(b);
		ScavTrap d;
		d = b;
	}
	std::cout << std::endl;

	std::cout << "=== ScavTrap stats check ===" << std::endl;
	{
		ScavTrap sv("Scout");
		std::cout << "HP: " << sv.getHp()
			<< " EP: " << sv.getEp()
			<< " DMG: " << sv.getDamage() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== Construction/destruction chaining ===" << std::endl;
	{
		std::cout << "-- Creating ClapTrap --" << std::endl;
		ClapTrap ct("BaseBot", 10, 10, 0);
		std::cout << "-- Creating ScavTrap --" << std::endl;
		ScavTrap sv("DerivedBot");
		std::cout << "-- Leaving scope --" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== ScavTrap special ability ===" << std::endl;
	{
		ScavTrap guard("Guardian");
		guard.guardGate();
	}
	std::cout << std::endl;

	std::cout << "=== ScavTrap combat ===" << std::endl;
	{
		ScavTrap tank("Tank");
		tank.attack("Enemy");
		tank.takeDamage(30);
		std::cout << "HP after 30 dmg: " << tank.getHp() << std::endl;
		tank.beRepaired(10);
		std::cout << "HP after repair 10: " << tank.getHp() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== ScavTrap energy depletion (50 EP) ===" << std::endl;
	{
		ScavTrap bot("Energetic");
		for (int i = 0; i < 50; i++)
			bot.attack("Target");
		std::cout << "EP after 50 attacks: " << bot.getEp() << std::endl;
		bot.attack("Target");
		bot.beRepaired(1);
	}
	std::cout << std::endl;

	std::cout << "=== ScavTrap overkill ===" << std::endl;
	{
		ScavTrap bot("Fragile");
		bot.takeDamage(100);
		std::cout << "HP: " << bot.getHp() << std::endl;
		bot.attack("Ghost");
		bot.beRepaired(50);
		bot.takeDamage(1);
	}
}

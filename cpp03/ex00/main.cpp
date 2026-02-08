#include "ClapTrap.hpp"
#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

int main(void)
{
	std::cout << YELLOW << "=== Orthodox Canonical Form ===" << RESET << std::endl;
	{
		ClapTrap a;
		ClapTrap b("Bravo");
		ClapTrap c(b);
		ClapTrap d;
		d = b;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== Basic actions ===" << RESET << std::endl;
	{
		ClapTrap kuro("Kuro");
		std::cout << "HP: " << kuro.getHp()
			<< " EP: " << kuro.getEp()
			<< " DMG: " << kuro.getDamage() << std::endl;
		kuro.attack("Shiro");
		kuro.takeDamage(3);
		std::cout << "HP after 3 dmg: " << kuro.getHp() << std::endl;
		kuro.beRepaired(2);
		std::cout << "HP after repair 2: " << kuro.getHp() << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== Energy depletion ===" << RESET << std::endl;
	{
		ClapTrap bot("EnergyBot");
		for (int i = 0; i < 10; i++)
			bot.attack("Target");
		std::cout << "EP after 10 attacks: " << bot.getEp() << std::endl;
		bot.attack("Target");
		bot.beRepaired(5);
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== Death and post-death actions ===" << RESET << std::endl;
	{
		ClapTrap weak("Weak");
		weak.takeDamage(10);
		std::cout << "HP: " << weak.getHp() << std::endl;
		weak.attack("Nobody");
		weak.beRepaired(100);
		weak.takeDamage(1);
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== Overkill damage ===" << RESET << std::endl;
	{
		ClapTrap bot("Glass");
		bot.takeDamage(9999);
		std::cout << "HP: " << bot.getHp() << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== Mixed energy drain (attack + repair) ===" << RESET << std::endl;
	{
		ClapTrap bot("Mixed");
		for (int i = 0; i < 5; i++)
			bot.attack("Target");
		for (int i = 0; i < 5; i++)
			bot.beRepaired(1);
		std::cout << "EP after 5 attacks + 5 repairs: " << bot.getEp() << std::endl;
		bot.attack("Target");
		bot.beRepaired(1);
	}
}

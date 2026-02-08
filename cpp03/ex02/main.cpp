#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

int main(void)
{
	std::cout << YELLOW << "=== FragTrap Orthodox Canonical Form ===" << RESET << std::endl;
	{
		FragTrap a;
		FragTrap b("Bravo");
		FragTrap c(b);
		FragTrap d;
		d = b;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== FragTrap stats check (100/100/30) ===" << RESET << std::endl;
	{
		FragTrap ft("Frag");
		std::cout << "HP: " << ft.getHp()
			<< " EP: " << ft.getEp()
			<< " DMG: " << ft.getDamage() << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== ScavTrap stats check (100/50/20) ===" << RESET << std::endl;
	{
		ScavTrap sv("Scav");
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
		ScavTrap sv("ScavBot");
		std::cout << YELLOW << "-- Creating FragTrap --" << RESET << std::endl;
		FragTrap ft("FragBot");
		std::cout << YELLOW << "-- Leaving scope --" << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== Special abilities ===" << RESET << std::endl;
	{
		ScavTrap guard("Guardian");
		guard.guardGate();
		FragTrap buddy("Buddy");
		buddy.highFiveGuys();
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== FragTrap combat ===" << RESET << std::endl;
	{
		FragTrap ft("Warrior");
		ft.attack("Enemy");
		ft.takeDamage(40);
		std::cout << "HP after 40 dmg: " << ft.getHp() << std::endl;
		ft.beRepaired(20);
		std::cout << "HP after repair 20: " << ft.getHp() << std::endl;
		ft.takeDamage(100);
		std::cout << "HP: " << ft.getHp() << std::endl;
		ft.attack("Ghost");
		ft.beRepaired(1);
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== FragTrap energy depletion (100 EP) ===" << RESET << std::endl;
	{
		FragTrap bot("Marathon");
		for (int i = 0; i < 100; i++)
			bot.attack("Target");
		std::cout << "EP after 100 attacks: " << bot.getEp() << std::endl;
		bot.attack("Target");
		bot.beRepaired(1);
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== ScavTrap vs FragTrap side by side ===" << RESET << std::endl;
	{
		ScavTrap sv("Alpha");
		FragTrap ft("Beta");
		sv.attack("Beta");
		ft.attack("Alpha");
		sv.takeDamage(30);
		ft.takeDamage(20);
		std::cout << "ScavTrap HP: " << sv.getHp()
			<< " FragTrap HP: " << ft.getHp() << std::endl;
	}
}

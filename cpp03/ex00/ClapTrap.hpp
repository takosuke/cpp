#pragma once
#include <string>

class ClapTrap
{
	private:
		std::string _name;
		unsigned int _hp;
		unsigned int _ep;
		unsigned int _damage;
	
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& ct);
		ClapTrap &operator=(const ClapTrap& ct);
		~ClapTrap();

		std::string getName(void) const;
		int getHp(void) const;
		int getEp(void) const;
		int getDamage(void) const;
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

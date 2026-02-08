#include "ScavTrap.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"

ScavTrap::ScavTrap(void) : ClapTrap("Default", 100, 50, 20)
{
	std::cout << GREEN << "ScavTrap created with default constructor" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << GREEN << "ScavTrap created with parametrized constructor" << RESET << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& st): ClapTrap(st)
{
	std::cout << GREEN << "ScavTrap " << st._name << " copy constructor called" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& st)
{
	std::cout << GREEN << "Used assigned operator to copy " << st.getName() << RESET << std::endl;
	if (this != &st)
	{
		this->_name = st.getName();
		this->_hp = st.getHp();
		this->_ep = st.getEp();
		this->_damage = st.getDamage();
	}
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << RED << "Destructor used on " << _name << RESET << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hp <= 0)
		std::cout << CYAN << _name << " can't attack because it's out of hit points" << RESET << std::endl;
	else if (_ep <= 0)
		std::cout << CYAN << _name << " can't attack because it's out of energy points" << RESET << std::endl;
	else
	{
		std::cout << CYAN << "ScavTrap " << _name << " attacks " << target << " inflicting "
			<< _damage << " points of damage" << RESET << std::endl;
		_ep--;
	}
}

void ScavTrap::guardGate()
{
	std::cout << _name << " is now in gatekeeper mode" << std::endl;
}

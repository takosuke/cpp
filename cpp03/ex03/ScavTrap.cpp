#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap("Default", 100, 50, 20) 
{
	std::cout << "ScavTrap created with default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) 
{
	std::cout << "ScavTrap created with parametrized constructor" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& st): ClapTrap(st)
{
	std::cout << "ScavTrap " << st._name << " copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& st)
{
	std::cout << "Used assigned operator to copy " << st.getName() << std::endl;
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
	std::cout << "Destructor used on " << _name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hp <= 0)
		std::cout << _name << " can't attack because it's out of hit points" << std::endl;
	else if (_ep <= 0)
		std::cout << _name << " can't attack because it's out of energy points" << std::endl;
	else
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << " inflicting "
			<< _damage << " points of damage" << std::endl;
		_ep--;
	}
}

void ScavTrap::guardGate()
{
	std::cout << _name << " is now in gatekeeper mode" << std::endl;
}

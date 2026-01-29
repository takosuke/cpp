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

void ScavTrap::guardGate()
{
	std::cout << _name << " is now in gatekeeper mode" << std::endl;
}

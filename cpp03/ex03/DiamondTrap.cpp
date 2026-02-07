#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void) : ClapTrap("Default_clap_name", 100, 50, 30), ScavTrap(), FragTrap(), _name("Default")
{
	std::cout << "DiamondTrap created with default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name", 100, 50, 30), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << "DiamondTrap created with parametrized constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& dt) : ClapTrap(dt), ScavTrap(dt), FragTrap(dt), _name(dt._name)
{
	std::cout << "DiamondTrap " << _name << " copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& dt)
{
	std::cout << "Used assigned operator to copy " << dt._name << std::endl;
	if (this != &dt)
	{
		ClapTrap::operator=(dt);
		this->_name = dt._name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor used on " << _name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

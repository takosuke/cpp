#include "DiamondTrap.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

DiamondTrap::DiamondTrap(void) : ClapTrap("Default_clap_name", 100, 50, 30), ScavTrap(), FragTrap(), _name("Default")
{
	std::cout << GREEN << "DiamondTrap created with default constructor" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name", 100, 50, 30), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << GREEN << "DiamondTrap created with parametrized constructor" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& dt) : ClapTrap(dt), ScavTrap(dt), FragTrap(dt), _name(dt._name)
{
	std::cout << GREEN << "DiamondTrap " << _name << " copy constructor called" << RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& dt)
{
	std::cout << GREEN << "Used assigned operator to copy " << dt._name << RESET << std::endl;
	if (this != &dt)
	{
		ClapTrap::operator=(dt);
		this->_name = dt._name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << RED << "DiamondTrap destructor used on " << _name << RESET << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap("Default", 100, 100, 30)
{
	std::cout << "FragTrap created with default constructor" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap created with parametrized constructor" << std::endl;
}

FragTrap::FragTrap( const FragTrap& st): ClapTrap(st)
{
	std::cout << "FragTrap " << st._name << " copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& st)
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

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor used on " << _name << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (_hp <= 0)
		std::cout << _name << " can't attack because it's out of hit points" << std::endl;
	else if (_ep <= 0)
		std::cout << _name << " can't attack because it's out of energy points" << std::endl;
	else
	{
		std::cout << "FragTrap " << _name << " attacks " << target << " inflicting "
			<< _damage << " points of damage" << std::endl;
		_ep--;
	}
}

void FragTrap::highFiveGuys()
{
	std::string answer;
	std::cout << _name << " is requesting a high five (Y/n)" << std::endl;
	std::getline(std::cin, answer);
	if (answer == "Y")
		std::cout << "CHOCA ESOS CINCO COLEGA" << std::endl;
	else
		std::cout << _name << " is disappointed" << std::endl;
}

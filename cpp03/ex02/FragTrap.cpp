#include "FragTrap.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"

FragTrap::FragTrap(void) : ClapTrap("Default", 100, 100, 30)
{
	std::cout << GREEN << "FragTrap created with default constructor" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << GREEN << "FragTrap created with parametrized constructor" << RESET << std::endl;
}

FragTrap::FragTrap( const FragTrap& st): ClapTrap(st)
{
	std::cout << GREEN << "FragTrap " << st._name << " copy constructor called" << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& st)
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

FragTrap::~FragTrap(void)
{
	std::cout << RED << "Destructor used on " << _name << RESET << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (_hp <= 0)
		std::cout << CYAN << _name << " can't attack because it's out of hit points" << RESET << std::endl;
	else if (_ep <= 0)
		std::cout << CYAN << _name << " can't attack because it's out of energy points" << RESET << std::endl;
	else
	{
		std::cout << CYAN << "FragTrap " << _name << " attacks " << target << " inflicting "
			<< _damage << " points of damage" << RESET << std::endl;
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

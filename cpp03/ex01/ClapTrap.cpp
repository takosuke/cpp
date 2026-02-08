#include "ClapTrap.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define BLUE    "\033[34m"

ClapTrap::ClapTrap(void) : _name("Unnamed"), _hp(10), _ep(10), _damage(0)
{
	std::cout << GREEN << "Constructed ClapTrap (default constructor) " << _name << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int damage) : _name(name), _hp(hp), _ep(ep), _damage(damage)
{
	std::cout << GREEN << "Constructed ClapTrap " << _name << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ct) : _name(ct._name), _hp(ct._hp), _ep(ct._ep), _damage(ct._damage)
{
	std::cout << GREEN << "Copy Constructed ClapTrap " << _name << RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& ct)
{
	std::cout << GREEN << "Used assigned operator to copy " << ct.getName() << RESET << std::endl;
	this->_name = ct.getName();
	this->_hp = ct.getHp();
	this->_ep = ct.getEp();
	this->_damage = ct.getDamage();
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "Destructed ClapTrap " << _name << RESET << std::endl;
}

std::string ClapTrap::getName(void) const { return _name; }
int ClapTrap::getHp(void) const { return _hp; }
int ClapTrap::getEp(void) const { return _ep; }
int ClapTrap::getDamage(void) const { return _damage; }

void ClapTrap::attack(const std::string& target)
{
	if (_hp <= 0)
		std::cout << CYAN << _name << " can't attack because it's out of hit points" << RESET << std::endl;
	else if (_ep <= 0)
		std::cout << CYAN << _name << " can't attack because it's out of energy points" << RESET << std::endl;
	else
	{
		std::cout << CYAN << _name << " attacks ClapTrap " << target << " inflicting "
			<< _damage << " points of damage" << RESET << std::endl;
		_ep--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp > 0)
	{
		std::cout << MAGENTA << _name << " takes " << amount << " points of damage" << RESET << std::endl;
		if (amount >= _hp)
		{
			std::cout << MAGENTA << _name << " died." << RESET << std::endl;
			_hp = 0;
		}
		else
		{
		_hp -= amount;
		}
	}
	else
		std::cout << MAGENTA << _name << " is dead and can't take any more damage" << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp <= 0)
		std::cout << BLUE << _name << " can't repair itself because it's dead" << RESET << std::endl;
	else if (_ep <= 0)
		std::cout << BLUE << _name << " can't repair itself because it's out of energy points" << RESET << std::endl;
	else
	{
		std::cout << BLUE << _name << " was repaired and recovered " << amount << " hit points!" << RESET << std::endl;
		_hp += amount;
		_ep --;
	}
}

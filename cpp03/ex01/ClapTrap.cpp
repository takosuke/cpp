#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : _name("Unnamed"), _hp(10), _ep(10), _damage(0)
{
	std::cout << "Constructed ClapTrap (default constructor) " << _name << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int damage) : _name(name), _hp(hp), _ep(ep), _damage(damage)
{
	std::cout << "Constructed ClapTrap " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ct) : _name(ct._name), _hp(ct._hp), _ep(ct._ep), _damage(ct._damage) 
{
	std::cout << "Copy Constructed ClapTrap " << _name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& ct)
{
	std::cout << "Used assigned operator to copy " << ct.getName() << std::endl;
	this->_name = ct.getName();
	this->_hp = ct.getHp();
	this->_ep = ct.getEp();
	this->_damage = ct.getDamage();
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructed ClapTrap " << _name << std::endl;
}

std::string ClapTrap::getName(void) const { return _name; }
int ClapTrap::getHp(void) const { return _hp; }
int ClapTrap::getEp(void) const { return _ep; }
int ClapTrap::getDamage(void) const { return _damage; }

void ClapTrap::attack(const std::string& target)
{
	if (_hp <= 0)
		std::cout << _name << " can't attack because it's out of hit points" << std::endl;
	else if (_ep <= 0)
		std::cout << _name << " can't attack because it's out of energy points" << std::endl;
	else
	{
		std::cout << _name << " attacks ClapTrap " << target << " inflicting " 
			<< _damage << " points of damage" << std::endl;
		_ep--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp > 0)
	{
		std::cout << _name << " takes " << amount << " points of damage" << std::endl;
		if (amount >= _hp)
		{
			std::cout << _name << " died." << std::endl;
			_hp = 0;
		}
		else
		{
		_hp -= amount;
		}
	}
	else
		std::cout << _name << " is dead and can't take any more damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp <= 0)
		std::cout << _name << " can't repair itself because it's dead" << std::endl;
	else if (_ep <= 0)
		std::cout << _name << " can't repair itself because it's out of energy points" << std::endl;
	else
	{
		std::cout << _name << " was repaired and recovered " << amount << " hit points!" << std::endl;
		_hp += amount;
		_ep --;
	}
}

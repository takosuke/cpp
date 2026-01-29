#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : _name(name)
{
}
Zombie::~Zombie() {}

void	Zombie::announce() const
{
	std::cout << "<" << _name << ">: BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	_name = name;
}

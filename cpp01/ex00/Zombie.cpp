#include "Zombie.hpp"

Zombie::Zombie(std::string _name) : name(_name) {}

Zombie::~Zombie() {}

void	Zombie::announce(void) const
{
	std::cout << "<" << name << ">: BraiiiiiiinnnzzzZ..." << std::endl;
}

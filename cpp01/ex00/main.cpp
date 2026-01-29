#include "Zombie.hpp"

int	main(void)
{
	randomChump("Zombie Express");
	Zombie *myZombie = newZombie("Poopy Heap Zombie");
	myZombie->announce();
	delete myZombie;
	return (0);
}

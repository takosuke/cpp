#include "Zombie.hpp"

int	main(void)
{
	randomChump("randomZombieExpress");
	Zombie *myZombie = newZombie("poopyHeapZombie");
	myZombie->announce();
	delete myZombie;
	return (0);
}

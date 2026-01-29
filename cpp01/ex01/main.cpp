#include "Zombie.hpp"

int	main(void)
{
	int n = 10;
	Zombie* myZombieHorde = zombieHorde(n, "Poop Zombie");
	for (int i = 0; i < n; i++) {
		myZombieHorde[i].announce();
	}
	delete[] myZombieHorde;
	return (0);
}
	

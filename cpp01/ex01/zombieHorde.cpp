#include "Zombie.hpp"

Zombie* zombieHorde( int n, std::string name )
{
	if (n < 1)
	{
		std::cout << "Need at least one zombie" << std::endl;
		return (NULL);
	}
	Zombie* zombies = new Zombie[n];
	if (zombies == NULL)
		return (NULL);
	for (int i = 0; i < n; i++) {
		zombies[i].setName(name);
	}
	return zombies;
}

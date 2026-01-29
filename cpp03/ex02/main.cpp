#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap nobody;
	FragTrap kuro("Kuro");
	FragTrap kuroneko(kuro);
	FragTrap shiro("Shiro");

	nobody = shiro;
	kuro.highFiveGuys();
	kuro.attack("the Clouds");
	kuro.beRepaired(3);
	kuro.takeDamage(2);
	kuro.takeDamage(15);
	shiro.takeDamage(100);
	kuroneko.takeDamage(2);

}

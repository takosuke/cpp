#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap nobody;
	ScavTrap kuro("Kuro");
	ScavTrap kuroneko(kuro);
	ScavTrap shiro("Shiro");

	nobody = shiro;
	kuro.guardGate();
	kuro.attack("the Clouds");
	kuro.beRepaired(3);
	kuro.takeDamage(2);
	kuro.takeDamage(15);
	shiro.takeDamage(100);
	kuroneko.takeDamage(2);

}

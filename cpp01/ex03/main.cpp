#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int	main()
{
	Weapon tomahawk("Tomahawk with dangling bells");
	HumanA crash("Crash Bandicoot", tomahawk);
	crash.attack();
	tomahawk.setType("Bag of teeth stolen from the tooth fairy");
	std::cout << "Crash new weapon is :" << tomahawk.getType() << std::endl;
	crash.attack();
	HumanB shinchan("Crayon Shin Chan");
	shinchan.attack();
	Weapon hammer("Inflatable hammer");
	shinchan.setWeapon(hammer);
	shinchan.attack();
	hammer.setType("Giant buttplug");
	shinchan.attack();
	return (0);
}



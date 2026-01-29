#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	Cat tzar;
	tzar.makeSound();
	Dog snoopy;
	snoopy.makeSound();
	Animal poop;
	poop.makeSound();
	WrongCat hobbes;
	hobbes.makeSound();
	return 0;
}

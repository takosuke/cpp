#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main(void)
{
	std::cout << "=== TEST 1: Basic construction ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;
	std::cout << "dog type: " << dog->getType() << std::endl;
	std::cout << "cat type: " << cat->getType() << std::endl;
	std::cout << "meta type: " << meta->getType() << std::endl;

	std::cout << std::endl;
	std::cout << "=== TEST 2: Polymorphic sounds (via Animal*) ===" << std::endl;
	dog->makeSound();
	cat->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	std::cout << "=== TEST 3: WrongAnimal - no polymorphism ===" << std::endl;
	WrongAnimal wrongMeta;
	WrongCat wrongCat;

	std::cout << std::endl;
	std::cout << "wrongCat type: " << wrongCat.getType() << std::endl;
	std::cout << "wrongMeta type: " << wrongMeta.getType() << std::endl;
	std::cout << std::endl;
	const WrongAnimal& wrongRef = wrongCat;
	std::cout << "Through WrongAnimal& (no virtual = no override):" << std::endl;
	wrongRef.makeSound();
	wrongMeta.makeSound();
	std::cout << std::endl;
	std::cout << "Directly on WrongCat object:" << std::endl;
	wrongCat.makeSound();

	std::cout << std::endl;
	std::cout << "=== TEST 4: Copy constructor ===" << std::endl;
	Cat originalCat;
	Cat copiedCat(originalCat);
	std::cout << "original type: " << originalCat.getType() << std::endl;
	std::cout << "copied type: " << copiedCat.getType() << std::endl;
	copiedCat.makeSound();

	std::cout << std::endl;
	std::cout << "=== TEST 5: Assignment operator ===" << std::endl;
	Dog dog1;
	Dog dog2;
	dog2 = dog1;
	std::cout << "dog1 type: " << dog1.getType() << std::endl;
	std::cout << "dog2 type: " << dog2.getType() << std::endl;
	dog2.makeSound();

	std::cout << std::endl;
	std::cout << "=== CLEANUP ===" << std::endl;
	delete meta;
	delete dog;
	delete cat;

	std::cout << std::endl;
	return 0;
}

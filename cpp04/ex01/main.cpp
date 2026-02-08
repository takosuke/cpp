#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	// --- TEST 1: Array of Animals with proper destructor order ---
	std::cout << "=== TEST 1: Array of Animals ===" << std::endl;
	const int count = 4;
	Animal* animals[count];

	for (int i = 0; i < count; i++)
	{
		if (i < count / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << std::endl;
	std::cout << "Checking sounds:" << std::endl;
	for (int i = 0; i < count; i++)
		animals[i]->makeSound();

	std::cout << std::endl;
	std::cout << "Deleting animals (check destructor order):" << std::endl;
	for (int i = 0; i < count; i++)
		delete animals[i];

	std::cout << std::endl;

	// --- TEST 2: Deep copy with copy constructor ---
	std::cout << "=== TEST 2: Deep Copy (copy constructor) ===" << std::endl;
	Dog original;
	original.getBrain()->ideas[0] = "Original idea 0";
	original.getBrain()->ideas[1] = "Original idea 1";

	Dog copy(original);
	std::cout << "Original brain addr: " << original.getBrain() << std::endl;
	std::cout << "Copy brain addr:     " << copy.getBrain() << std::endl;
	std::cout << "Original idea[0]: " << original.getBrain()->ideas[0] << std::endl;
	std::cout << "Copy idea[0]:     " << copy.getBrain()->ideas[0] << std::endl;

	copy.getBrain()->ideas[0] = "Modified in copy";
	std::cout << "After modifying copy:" << std::endl;
	std::cout << "Original idea[0]: " << original.getBrain()->ideas[0] << std::endl;
	std::cout << "Copy idea[0]:     " << copy.getBrain()->ideas[0] << std::endl;

	std::cout << std::endl;

	// --- TEST 3: Deep copy with assignment operator ---
	std::cout << "=== TEST 3: Deep Copy (assignment operator) ===" << std::endl;
	Cat cat1;
	cat1.getBrain()->ideas[0] = "Cat1 original idea";

	Cat cat2;
	cat2 = cat1;
	std::cout << "Cat1 brain addr: " << cat1.getBrain() << std::endl;
	std::cout << "Cat2 brain addr: " << cat2.getBrain() << std::endl;
	std::cout << "Cat1 idea[0]: " << cat1.getBrain()->ideas[0] << std::endl;
	std::cout << "Cat2 idea[0]: " << cat2.getBrain()->ideas[0] << std::endl;

	cat2.getBrain()->ideas[0] = "Cat2 modified idea";
	std::cout << "After modifying cat2:" << std::endl;
	std::cout << "Cat1 idea[0]: " << cat1.getBrain()->ideas[0] << std::endl;
	std::cout << "Cat2 idea[0]: " << cat2.getBrain()->ideas[0] << std::endl;

	std::cout << std::endl;

	// --- TEST 4: Deep copy survives scope ---
	std::cout << "=== TEST 4: Deep Copy survives scope ===" << std::endl;
	Dog dog1;
	dog1.getBrain()->ideas[0] = "Survive the scope";
	{
		Dog tmp;
		tmp = dog1;
		std::cout << "tmp idea[0]: " << tmp.getBrain()->ideas[0] << std::endl;
	}
	std::cout << "dog1 still alive after tmp destroyed:" << std::endl;
	std::cout << "dog1 idea[0]: " << dog1.getBrain()->ideas[0] << std::endl;
	dog1.makeSound();

	std::cout << std::endl;

	// --- TEST 5: Self-assignment ---
	std::cout << "=== TEST 5: Self-assignment guard ===" << std::endl;
	Cat selfCat;
	selfCat.getBrain()->ideas[0] = "Don't lose me";
	selfCat = selfCat;
	std::cout << "After self-assignment: " << selfCat.getBrain()->ideas[0] << std::endl;

	std::cout << std::endl;
	std::cout << "=== CLEANUP ===" << std::endl;
	return 0;
}

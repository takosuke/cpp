#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    // --- TEST 1: POLYMORPHISM & VIRTUAL DESTRUCTOR ---
    std::cout << "--- TEST 1: Array of Animals ---" << std::endl;
    const int count = 4;
    Animal* animals[count];

    for (int i = 0; i < count; i++) {
	if (i < count / 2)
	    animals[i] = new Dog();
	else
	    animals[i] = new Cat();
    }

    std::cout << "\nChecking sounds:" << std::endl;
    for (int i = 0; i < count; i++) {
	animals[i]->makeSound();
    }

    std::cout << "\nDeleting animals (Check destructor order in logs):" << std::endl;
    for (int i = 0; i < count; i++) {
	delete animals[i]; // This MUST call Dog/Cat destructors!
    }

    std::cout << "\n----------------------------------\n" << std::endl;

    // --- TEST 2: DEEP COPY (Assignment Operator) ---
    std::cout << "--- TEST 2: Deep Copy with Assignment ---" << std::endl;
    Dog dog1;
    // Assume we have a way to set an idea, e.g., dog1.getBrain()->setIdea(0, "I love bones");
    
    {
	Dog tmp;
	tmp = dog1; // Assignment operator called
	std::cout << "Tmp dog created and assigned from Dog1." << std::endl;
    } // tmp goes out of scope here! 
    // If it was a SHALLOW copy, dog1's brain would be deleted here.
    
    std::cout << "Dog1 is still alive. Let's see if its brain still exists:" << std::endl;
    dog1.makeSound(); 
    // If the program doesn't crash here, your deep copy worked.

    std::cout << "\n----------------------------------\n" << std::endl;

    // --- TEST 3: SELF-ASSIGNMENT ---
    std::cout << "--- TEST 3: Self-Assignment Guard ---" << std::endl;
    Cat selfCat;
    selfCat = selfCat; // Should not crash or delete its own brain
    Dog selfDog;
    selfDog = selfDog; // Should not crash or delete its own brain
    std::cout << "Self-assignment complete without crashing." << std::endl;

    std::cout << "\n----------------------------------\n" << std::endl;

    return 0;
}

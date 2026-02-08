#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== TEST 1: Basic equip and use ===" << std::endl;
	Character bob("bob");
	Character jim("jim");

	AMateria* ice = new Ice();
	AMateria* cure = new Cure();

	bob.equip(ice);
	bob.equip(cure);

	bob.use(0, jim);
	bob.use(1, jim);

	std::cout << std::endl;

	// --- TEST 2: Unequip (should NOT delete the materia) ---
	std::cout << "=== TEST 2: Unequip ===" << std::endl;
	bob.unequip(0);
	bob.use(0, jim);
	std::cout << "Ice was unequipped, slot 0 should do nothing." << std::endl;

	std::cout << std::endl;

	// --- TEST 3: Deep copy ---
	std::cout << "=== TEST 3: Deep copy ===" << std::endl;
	Character bob2(bob);
	bob2.use(1, jim);
	std::cout << "bob2 (copy of bob) uses slot 1 (cure)." << std::endl;

	std::cout << std::endl;

	// --- TEST 4: Assignment operator ---
	std::cout << "=== TEST 4: Assignment operator ===" << std::endl;
	Character eve("eve");
	eve = bob;
	eve.use(1, jim);
	std::cout << "eve (assigned from bob) uses slot 1 (cure)." << std::endl;

	std::cout << std::endl;

	// --- TEST 5: Equip more than 4 ---
	std::cout << "=== TEST 5: Equip overflow ===" << std::endl;
	Character max("max");
	AMateria* m0 = new Ice();
	AMateria* m1 = new Cure();
	AMateria* m2 = new Ice();
	AMateria* m3 = new Cure();
	AMateria* m4 = new Ice();

	max.equip(m0);
	max.equip(m1);
	max.equip(m2);
	max.equip(m3);
	max.equip(m4);
	std::cout << "5th equip should be ignored (only 4 slots)." << std::endl;
	delete m4;

	std::cout << std::endl;

	// --- TEST 6: Use invalid index ---
	std::cout << "=== TEST 6: Invalid index ===" << std::endl;
	max.use(-1, jim);
	max.use(4, jim);
	std::cout << "Invalid indices should do nothing." << std::endl;

	std::cout << std::endl;
	std::cout << "=== CLEANUP ===" << std::endl;
	return 0;
}

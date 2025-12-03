#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "\n========== MATERIA TESTS ==========" << std::endl;

	std::cout << "\n--- Creating MateriaSource ---" << std::endl;
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Create characters
	ICharacter *bob = new Character("Bob");
	ICharacter *alice = new Character("Alice");

	std::cout << "\n--- Test 1: Create Materias from Source ---" << std::endl;
	AMateria *ice1 = src->createMateria("ice");
	AMateria *cure1 = src->createMateria("cure");
	bob->equip(ice1);
	bob->equip(cure1);
	bob->use(0, *alice);
	bob->use(1, *alice);

	std::cout << "\n--- Test 2: Create Unknown Type ---" << std::endl;
	AMateria *unknown = src->createMateria("fire");
	if (unknown == NULL)
		std::cout << "Fail to create, returns NULL" << std::endl;

	std::cout << "\n--- Test 3: Full Inventory (4 slots) ---" << std::endl;
	bob->equip(src->createMateria("ice"));
	bob->equip(src->createMateria("cure"));
	AMateria *extra = src->createMateria("ice");
	bob->equip(extra); // Should fail - inventory full
	delete extra;	 // Must delete since not equipped

	std::cout << "\n--- Test 4: Unequip and Re-use Slot ---" << std::endl;
	bob->use(0, *alice);
	bob->unequip(0); // Drop ice
	bob->use(0, *alice); // Should do nothing (slot empty)
	bob->equip(src->createMateria("cure")); // Fill slot 0 again
	bob->use(0, *alice); // Should work now

	std::cout << "\n--- Test 5: Invalid Operations ---" << std::endl;
	alice->use(0, *bob); // Empty slot
	alice->use(-1, *bob); // Invalid index
	alice->unequip(0);	 // Empty slot
	alice->equip(NULL);	 // NULL materia

	std::cout << "\n--- Test 6: MateriaSource Full (4 templates) ---" << std::endl;
	IMateriaSource *src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	src2->learnMateria(new Ice()); // Should fail

	std::cout << "\n--- Test 7: Copy Constructor (Deep Copy Proof) ---" << std::endl;
	Character *maria = new Character("Maria");
	maria->equip(src->createMateria("ice"));
	maria->equip(src->createMateria("cure"));

	std::cout << "Creating copy of Maria..." << std::endl;
	Character mariaCopy(*maria);

	std::cout << "\n[Before modifications]" << std::endl;
	std::cout << "Original Maria slot 0: ";
	maria->use(0, *bob);
	std::cout << "Copy slot 0: ";
	mariaCopy.use(0, *bob);

	std::cout << "\n[Modifying original - unequipping slot 0]" << std::endl;
	maria->unequip(0);
	std::cout << "Original Maria slot 0 (should be empty): ";
	maria->use(0, *bob);
	std::cout << "Copy slot 0 (should STILL work - deep copy!): ";
	mariaCopy.use(0, *bob);

	std::cout << "\n[Modifying copy - unequipping slot 1]" << std::endl;
	mariaCopy.unequip(1);

	std::cout << "Original Maria slot 1 (should STILL work - deep copy!): ";
	maria->use(1, *bob);
	std::cout << "Copy slot 1 (should be empty): ";
	mariaCopy.use(1, *bob);

	std::cout << "\n--- Test 8: Multiple Creations from Source ---" << std::endl;
	Character dave("Dave");
	for (int i = 0; i < 4; i++)
	{
		dave.equip(src->createMateria(i % 2 == 0 ? "ice" : "cure"));
	}
	dave.use(0, *bob);
	dave.use(1, *bob);
	dave.use(2, *bob);
	dave.use(3, *bob);

	std::cout << "\n--- Cleanup ---" << std::endl;
	delete src;
	delete src2;
	delete bob;
	delete alice;

	std::cout << "\n========== ALL TESTS COMPLETED ==========" << std::endl;

	return 0;
}

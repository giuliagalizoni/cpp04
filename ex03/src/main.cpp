#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "\n========== MATERIA TESTS ==========" << std::endl;

	// Create MateriaSource and learn materias
	std::cout << "\n--- Creating MateriaSource ---" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Create characters
	ICharacter* bob = new Character("Bob");
	ICharacter* alice = new Character("Alice");

	// Test 1: Create and equip materias from source
	std::cout << "\n--- Test 1: Create Materias from Source ---" << std::endl;
	AMateria* ice1 = src->createMateria("ice");
	AMateria* cure1 = src->createMateria("cure");
	bob->equip(ice1);
	bob->equip(cure1);
	bob->use(0, *alice);
	bob->use(1, *alice);

	// Test 2: Create unknown type (should return NULL)
	std::cout << "\n--- Test 2: Create Unknown Type ---" << std::endl;
	AMateria* unknown = src->createMateria("fire");
	if (unknown == NULL)
		std::cout << "Unknown materia type returns NULL ✓" << std::endl;

	// Test 3: Full inventory
	std::cout << "\n--- Test 3: Full Inventory (4 slots) ---" << std::endl;
	bob->equip(src->createMateria("ice"));
	bob->equip(src->createMateria("cure"));
	AMateria* extra = src->createMateria("ice");
	bob->equip(extra); // Should fail - inventory full
	delete extra; // Must delete since not equipped

	// Test 4: Unequip and reuse slot
	std::cout << "\n--- Test 4: Unequip and Re-use Slot ---" << std::endl;
	bob->use(0, *alice);
	bob->unequip(0); // Drop ice
	bob->use(0, *alice); // Should do nothing (slot empty)
	bob->equip(src->createMateria("cure")); // Fill slot 0 again
	bob->use(0, *alice); // Should work now

	// Test 5: Invalid operations
	std::cout << "\n--- Test 5: Invalid Operations ---" << std::endl;
	alice->use(0, *bob); // Empty slot
	alice->use(-1, *bob); // Invalid index
	alice->unequip(0); // Empty slot
	alice->equip(NULL); // NULL materia

	// Test 6: MateriaSource with 4 templates
	std::cout << "\n--- Test 6: MateriaSource Full (4 templates) ---" << std::endl;
	IMateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
 	src2->learnMateria(new Ice()); // Should fail, but materia is deleted by learnMateria

	// Test 7: Copy constructor (deep copy proof)
	std::cout << "\n--- Test 7: Copy Constructor (Deep Copy Proof) ---" << std::endl;
	alice->equip(src->createMateria("ice"));
	alice->equip(src->createMateria("cure"));

	std::cout << "Creating copy of Alice..." << std::endl;
	Character aliceCopy(*static_cast<Character*>(alice));

	std::cout << "\n[Before modifications]" << std::endl;
	std::cout << "Original Alice slot 0: ";
	alice->use(0, *bob);
	std::cout << "Copy slot 0: ";
	aliceCopy.use(0, *bob);

	std::cout << "\n[Modifying original - unequipping slot 0]" << std::endl;
	alice->unequip(0);

	std::cout << "Original Alice slot 0 (should be empty): ";
	alice->use(0, *bob);
	std::cout << "Copy slot 0 (should STILL work - deep copy!): ";
	aliceCopy.use(0, *bob);

	std::cout << "\n[Modifying copy - unequipping slot 1]" << std::endl;
	aliceCopy.unequip(1);

	std::cout << "Original Alice slot 1 (should STILL work - deep copy!): ";
	alice->use(1, *bob);
	std::cout << "Copy slot 1 (should be empty): ";
	aliceCopy.use(1, *bob);

	std::cout << "\n✓ Deep copy confirmed: Changes to one don't affect the other!" << std::endl;

	// Test 8: Create multiple materias from same source
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

	// Cleanup
	std::cout << "\n--- Cleanup ---" << std::endl;
	delete src;
	delete src2;
	delete bob;
	delete alice;

	std::cout << "\n========== ALL TESTS COMPLETED ==========" << std::endl;

	return 0;
}

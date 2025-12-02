#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

void basicTests()
{
	std::cout << "\n========== BASIC TESTS ==========" << std::endl;
	Animal *animals[10];

	std::cout << "Creating animals..." << std::endl;
	for (int i = 0; i < 10; i++)
		(i % 2 == 0) ? animals[i] = new Dog() : animals[i] = new Cat();

	std::cout << "\nTesting sounds..." << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Animal[" << i << "] (" << animals[i]->getType() << "): ";
		animals[i]->makeSound();
	}

	std::cout << "\nDeleting animals..." << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];
}

void deepCopyTestDog()
{
	std::cout << "\n========== DEEP COPY TEST - DOG ==========" << std::endl;

	std::cout << "\n--- Creating original Dog ---" << std::endl;
	Dog *originalDog = new Dog();

	std::cout << "\n--- Setting ideas in original Dog's brain ---" << std::endl;
	originalDog->getBrain()->setIdea(0, "I love bones");
	originalDog->getBrain()->setIdea(1, "Chase the cat");
	originalDog->getBrain()->setIdea(2, "Bark at mailman");

	std::cout << "\nOriginal Dog's ideas:" << std::endl;
	std::cout << "  Idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "  Idea 1: " << originalDog->getBrain()->getIdea(1) << std::endl;
	std::cout << "  Idea 2: " << originalDog->getBrain()->getIdea(2) << std::endl;

	std::cout << "\n--- Creating copy using copy constructor ---" << std::endl;
	Dog *copiedDog = new Dog(*originalDog);

	std::cout << "\nCopied Dog's ideas (should be same):" << std::endl;
	std::cout << "  Idea 0: " << copiedDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "  Idea 1: " << copiedDog->getBrain()->getIdea(1) << std::endl;
	std::cout << "  Idea 2: " << copiedDog->getBrain()->getIdea(2) << std::endl;

	std::cout << "\n--- Modifying copied Dog's brain (PROOF OF DEEP COPY) ---" << std::endl;
	copiedDog->getBrain()->setIdea(0, "I love treats instead");
	copiedDog->getBrain()->setIdea(1, "Sleep all day");

	std::cout << "\nOriginal Dog's ideas (should be UNCHANGED):" << std::endl;
	std::cout << "  Idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "  Idea 1: " << originalDog->getBrain()->getIdea(1) << std::endl;
	std::cout << "  Idea 2: " << originalDog->getBrain()->getIdea(2) << std::endl;

	std::cout << "\nCopied Dog's ideas (should be DIFFERENT):" << std::endl;
	std::cout << "  Idea 0: " << copiedDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "  Idea 1: " << copiedDog->getBrain()->getIdea(1) << std::endl;
	std::cout << "  Idea 2: " << copiedDog->getBrain()->getIdea(2) << std::endl;

	std::cout << "\n--- Comparing Brain pointers (should be DIFFERENT) ---" << std::endl;
	std::cout << "Original Brain address: " << originalDog->getBrain() << std::endl;
	std::cout << "Copied Brain address:   " << copiedDog->getBrain() << std::endl;

	if (originalDog->getBrain() != copiedDog->getBrain())
		std::cout << "✓ SUCCESS: Brain pointers are different (deep copy confirmed)" << std::endl;
	else
		std::cout << "✗ FAIL: Brain pointers are the same (shallow copy!)" << std::endl;

	std::cout << "\n--- Deleting dogs ---" << std::endl;
	delete originalDog;
	delete copiedDog;
}

void deepCopyTestCat()
{
	std::cout << "\n========== DEEP COPY TEST - CAT ==========" << std::endl;

	std::cout << "\n--- Creating original Cat ---" << std::endl;
	Cat originalCat;

	std::cout << "\n--- Setting ideas in original Cat's brain ---" << std::endl;
	originalCat.getBrain()->setIdea(0, "Meow for food");
	originalCat.getBrain()->setIdea(1, "Knock things off table");
	originalCat.getBrain()->setIdea(2, "Ignore humans");

	std::cout << "\nOriginal Cat's ideas:" << std::endl;
	std::cout << "  Idea 0: " << originalCat.getBrain()->getIdea(0) << std::endl;
	std::cout << "  Idea 1: " << originalCat.getBrain()->getIdea(1) << std::endl;
	std::cout << "  Idea 2: " << originalCat.getBrain()->getIdea(2) << std::endl;

	std::cout << "\n--- Creating copy using copy constructor ---" << std::endl;
	Cat copiedCat(originalCat);

	std::cout << "\nCopied Cat's ideas (should be same):" << std::endl;
	std::cout << "  Idea 0: " << copiedCat.getBrain()->getIdea(0) << std::endl;
	std::cout << "  Idea 1: " << copiedCat.getBrain()->getIdea(1) << std::endl;
	std::cout << "  Idea 2: " << copiedCat.getBrain()->getIdea(2) << std::endl;

	std::cout << "\n--- Modifying copied Cat's brain (PROOF OF DEEP COPY) ---" << std::endl;
	copiedCat.getBrain()->setIdea(0, "Actually love humans");
	copiedCat.getBrain()->setIdea(1, "Purr loudly");

	std::cout << "\nOriginal Cat's ideas (should be UNCHANGED):" << std::endl;
	std::cout << "  Idea 0: " << originalCat.getBrain()->getIdea(0) << std::endl;
	std::cout << "  Idea 1: " << originalCat.getBrain()->getIdea(1) << std::endl;
	std::cout << "  Idea 2: " << originalCat.getBrain()->getIdea(2) << std::endl;

	std::cout << "\nCopied Cat's ideas (should be DIFFERENT):" << std::endl;
	std::cout << "  Idea 0: " << copiedCat.getBrain()->getIdea(0) << std::endl;
	std::cout << "  Idea 1: " << copiedCat.getBrain()->getIdea(1) << std::endl;
	std::cout << "  Idea 2: " << copiedCat.getBrain()->getIdea(2) << std::endl;

	std::cout << "\n--- Comparing Brain pointers (should be DIFFERENT) ---" << std::endl;
	std::cout << "Original Brain address: " << originalCat.getBrain() << std::endl;
	std::cout << "Copied Brain address:   " << copiedCat.getBrain() << std::endl;

	std::cout << "\n--- Destructors ---" << std::endl;
}

void assignmentOperatorDeepCopyTest()
{
	std::cout << "\n========== ASSIGNMENT OPERATOR DEEP COPY TEST ==========" << std::endl;

	std::cout << "\n--- Creating two Dogs ---" << std::endl;
	Dog dog1;
	Dog dog2;

	std::cout << "\n--- Setting ideas in dog1's brain ---" << std::endl;
	dog1.getBrain()->setIdea(0, "Original idea 1");
	dog1.getBrain()->setIdea(1, "Original idea 2");

	std::cout << "\n--- Setting different ideas in dog2's brain ---" << std::endl;
	dog2.getBrain()->setIdea(0, "Different idea 1");
	dog2.getBrain()->setIdea(1, "Different idea 2");

	std::cout << "\nDog1's ideas before assignment:" << std::endl;
	std::cout << "  Idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "  Idea 1: " << dog1.getBrain()->getIdea(1) << std::endl;

	std::cout << "\nDog2's ideas before assignment:" << std::endl;
	std::cout << "  Idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << "  Idea 1: " << dog2.getBrain()->getIdea(1) << std::endl;

	std::cout << "\n--- Assigning dog1 to dog2 (dog2 = dog1) ---" << std::endl;
	dog2 = dog1;

	std::cout << "\nDog2's ideas after assignment (should match dog1):" << std::endl;
	std::cout << "  Idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << "  Idea 1: " << dog2.getBrain()->getIdea(1) << std::endl;

	std::cout << "\n--- Modifying dog2's brain (PROOF OF DEEP COPY) ---" << std::endl;
	dog2.getBrain()->setIdea(0, "Modified after assignment");

	std::cout << "\nDog1's ideas (should be UNCHANGED):" << std::endl;
	std::cout << "  Idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "  Idea 1: " << dog1.getBrain()->getIdea(1) << std::endl;

	std::cout << "\nDog2's ideas (should be DIFFERENT):" << std::endl;
	std::cout << "  Idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << "  Idea 1: " << dog2.getBrain()->getIdea(1) << std::endl;

	std::cout << "\n--- Comparing Brain pointers (should be DIFFERENT) ---" << std::endl;
	std::cout << "Dog1 Brain address: " << dog1.getBrain() << std::endl;
	std::cout << "Dog2 Brain address: " << dog2.getBrain() << std::endl;

	std::cout << "\n--- Destructors ---" << std::endl;
}

int main()
{
	basicTests();
	deepCopyTestDog();
	deepCopyTestCat();
	assignmentOperatorDeepCopyTest();
	return 0;
}

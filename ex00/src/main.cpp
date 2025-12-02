#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

void subjectTests()
{
	std::cout << "\n========== SUBJECT TESTS ==========" << std::endl;
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;
}

void wrongAnimalTests()
{
	std::cout << "\n========== WRONG ANIMAL TESTS ==========" << std::endl;
	const WrongAnimal *meta = new WrongAnimal();
	const Animal *j = new Dog();
	const WrongAnimal *i = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will NOT output the cat sound (no virtual)
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;
}

void constructorTests()
{
	std::cout << "\n========== CONSTRUCTOR TESTS ==========" << std::endl;

	std::cout << "\n--- Creating Animal on stack ---" << std::endl;
	Animal animal1;

	std::cout << "\n--- Creating Dog on stack ---" << std::endl;
	Dog dog1;

	std::cout << "\n--- Creating Cat on stack ---" << std::endl;
	Cat cat1;

	std::cout << "\n--- Testing copy constructor (Dog) ---" << std::endl;
	Dog dog2(dog1);

	std::cout << "\n--- Testing copy constructor (Cat) ---" << std::endl;
	Cat cat2(cat1);

	std::cout << "\n--- End of scope (destructors will be called) ---" << std::endl;
}

void assignmentOperatorTests()
{
	std::cout << "\n========== ASSIGNMENT OPERATOR TESTS ==========" << std::endl;

	Dog dog1;
	Dog dog2;

	std::cout << "\n--- Testing assignment operator ---" << std::endl;
	dog2 = dog1;

	Cat cat1;
	Cat cat2;

	std::cout << "\n--- Testing assignment operator (Cat) ---" << std::endl;
	cat2 = cat1;

	std::cout << "\n--- End of scope ---" << std::endl;
}

void polymorphismTests()
{
	std::cout << "\n========== POLYMORPHISM TESTS ==========" << std::endl;

	std::cout << "\n--- Creating array of Animal pointers ---" << std::endl;
	const Animal *animals[4];
	animals[0] = new Animal();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Dog();

	std::cout << "\n--- Testing polymorphic behavior ---" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "\nAnimal[" << i << "] type: " << animals[i]->getType() << std::endl;
		std::cout << "Sound: ";
		animals[i]->makeSound();
	}

	std::cout << "\n--- Cleaning up ---" << std::endl;
	for (int i = 0; i < 4; i++)
		delete animals[i];
}

void getTypeTests()
{
	std::cout << "\n========== GET TYPE TESTS ==========" << std::endl;

	Animal *animal = new Animal();
	Dog *dog = new Dog();
	Cat *cat = new Cat();

	std::cout << "Animal type: " << animal->getType() << std::endl;
	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;

	std::cout << "\n--- Testing getType through base pointer ---" << std::endl;
	Animal *polymorphicDog = new Dog();
	Animal *polymorphicCat = new Cat();

	std::cout << "Polymorphic Dog type: " << polymorphicDog->getType() << std::endl;
	std::cout << "Polymorphic Cat type: " << polymorphicCat->getType() << std::endl;

	delete animal;
	delete dog;
	delete cat;
	delete polymorphicDog;
	delete polymorphicCat;
}

void wrongAnimalPolymorphismTests()
{
	std::cout << "\n========== WRONG ANIMAL POLYMORPHISM TESTS ==========" << std::endl;
	std::cout << "Demonstrating the difference between virtual and non-virtual methods\n"
			  << std::endl;

	std::cout << "--- Correct polymorphism (Animal with virtual) ---" << std::endl;
	Animal *correctCat = new Cat();
	std::cout << "Type: " << correctCat->getType() << " - Sound: ";
	correctCat->makeSound();

	std::cout << "\n--- Incorrect polymorphism (WrongAnimal without virtual) ---" << std::endl;
	WrongAnimal *wrongCat = new WrongCat();
	std::cout << "Type: " << wrongCat->getType() << " - Sound: ";
	wrongCat->makeSound();

	std::cout << "\nNotice: WrongCat makes WrongAnimal sound (not polymorphic)" << std::endl;

	delete correctCat;
	delete wrongCat;
}

int main()
{
	subjectTests();
	wrongAnimalTests();
	constructorTests();
	assignmentOperatorTests();
	polymorphismTests();
	getTypeTests();
	wrongAnimalPolymorphismTests();

	std::cout << "\n========== ALL TESTS COMPLETED ==========" << std::endl;
	return 0;
}

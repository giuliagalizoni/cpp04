#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"


int main()
{
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

	std::cout << "Deleting animals..." << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];

	return 0;
}

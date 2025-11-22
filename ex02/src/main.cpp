#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main()
{
	// Animal cannot be instanciated - Does not compile tests:
	// Animal animal;
	// Animal *animal = new Animal();

	Animal *dog = new Dog;
	dog->makeSound();
	delete dog;

	return 0;
}

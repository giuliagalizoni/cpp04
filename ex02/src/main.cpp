#include "../includes/AAnimal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main()
{
	//AAnimal cannot be instanciated - Does not compile tests:
	// AAnimal animal;
	// AAnimal *animal = new AAnimal();

	AAnimal *dog = new Dog;
	dog->makeSound();
	delete dog;

	return 0;
}

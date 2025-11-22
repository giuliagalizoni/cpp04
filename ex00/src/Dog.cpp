#include "../includes/Dog.hpp"

// Default constructor
Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << type << " default constructor called" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

// Copy assignment operator
Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

// Destructor
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

// Public methods implementation
void Dog::makeSound() const
{
	std::cout << "au au" << std::endl;
}

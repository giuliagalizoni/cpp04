#include "../includes/Animal.hpp"

// Default constructor
Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

// Destructor
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

// Public methods implementation
void Animal::makeSound() const
{
	std::cout << "[inaudible]" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

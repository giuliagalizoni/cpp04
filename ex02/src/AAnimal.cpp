#include "../includes/AAnimal.hpp"

// Default constructor
AAnimal::AAnimal()
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

// Copy constructor
AAnimal::AAnimal(const AAnimal& other)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

// Destructor
AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

// Public methods implementation
std::string AAnimal::getType() const
{
	return type;
}

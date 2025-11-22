#include "../includes/WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

// Public methods implementation
void	WrongAnimal::makeSound() const
{
	std::cout << "[inaudible]" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}

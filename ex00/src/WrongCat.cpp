#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat() : WrongAnimal()
{
	type = "Cat";
	std::cout << type << " default constructor called" << std::endl;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

// Copy assignment operator
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

// Public methods implementation
void WrongCat::makeSound() const
{
	std::cout << "miau" << std::endl;
}



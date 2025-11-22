#include "../includes/Cat.hpp"

// Default constructor
Cat::Cat() : Animal()
{
	type = "Cat";
	_brain = new Brain();
	std::cout << type << " default constructor called" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat& other) : Animal(other)
{
	_brain = new Brain();
	std::cout << "Cat copy constructor called" << std::endl;
}

// Copy assignment operator
Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

// Destructor
Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

// Public methods implementation
void Cat::makeSound() const
{
	std::cout << "miau" << std::endl;
}



#include "Ice.hpp"
#include "ICharacter.hpp"

// Default constructor
Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

// Copy constructor
Ice::Ice(const Ice& other) : AMateria(other)
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Ice& Ice::operator=(const Ice& other)
{
	std::cout << "Ice copy assignment operator called" << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

// Destructor
Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

// Public methods implementation

AMateria* Ice::clone() const
{
	std::cout << "Ice clone function called" << std::endl;
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

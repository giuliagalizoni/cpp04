#include "../includes/Cure.hpp"
#include "ICharacter.hpp"

// Default constructor
Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

// Copy constructor
Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Cure &Cure::operator=(const Cure &other)
{
	std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

// Destructor
Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

// Public methods implementation

AMateria *Cure::clone() const
{
	std::cout << "Cure clone function called" << std::endl;
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

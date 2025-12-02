#include "AMateria.hpp"
#include "ICharacter.hpp"

// Default constructor
AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "AMateria type constructor called" << std::endl;
}

// Copy constructor
AMateria::AMateria(const AMateria &other) : type(other.type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

// Copy assignment operator
AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << "AMateria copy assignment operator called" << std::endl;
	(void)other;
	return *this;
}

// Destructor
AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

// Public methods implementation

std::string const &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "AMateria " << type << " used on " << target.getName() << std::endl;
}

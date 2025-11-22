#include "Brain.hpp"

// Default constructor
Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

// Copy constructor
Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

// Destructor
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

// Public methods implementation

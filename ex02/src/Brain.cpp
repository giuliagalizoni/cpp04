#include "../includes/Brain.hpp"

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
void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return ideas[index];
	std::cerr << "Error: Brain index out of bounds (" << index << ")" << std::endl;
	return "";
}

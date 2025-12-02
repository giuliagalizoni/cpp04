#include "Character.hpp"

// Default constructor
Character::Character() : _droppedItems(NULL)
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string const &name) : _name(name), _droppedItems(NULL)
{
	std::cout << "Character constructor called for " << _name << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}
// Copy constructor
Character::Character(const Character &other) : _name(other._name), _droppedItems(NULL)
{
	std::cout << "Character copy constructor called for " << _name << std::endl;
	// Deep copy
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

// Copy assignment operator
Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;

		// Cleanup existing inventory
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
		}

		// Cleanup dropped items
		while (_droppedItems)
		{
			Node *temp = _droppedItems;
			_droppedItems = _droppedItems->next;
			delete temp->item;
			delete temp;
		}

		// Deep copy new inventory
		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	std::cout << "Character copy assignment operator called for " << _name << std::endl;

	return *this;
}

// Destructor
Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;

	// Cleanup inventory
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}

	// Cleanup dropped items
	while (_droppedItems)
	{
		Node *temp = _droppedItems;
		_droppedItems = _droppedItems->next;
		delete temp->item;
		delete temp;
	}
}

// Public methods implementation
std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << m->getType() << " equipped to " << _name << std::endl;
			return;
		}
	}
	std::cout << "Inventory full, cannot equip " << m->getType() << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
	{
		std::cout << "Item not found on " << _name << "'s inventory. Cannot equip " << std::endl;
		return;
	}

	if (_inventory[idx])
	{
		// keep dropped item
		Node *floor = new Node;
		floor->item = _inventory[idx];
		floor->next = _droppedItems;
		_droppedItems = floor;

		// unequip
		std::cout << _inventory[idx]->getType() << " was removed from " << _name << "'s inventory" << std::endl;
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}

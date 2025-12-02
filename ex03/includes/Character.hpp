#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "../includes/ICharacter.hpp"
#include "../includes/AMateria.hpp"

struct Node
{
	AMateria *item;
	Node *next;
};

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria *_inventory[4];
	Node *_droppedItems;

public:
	Character();
	Character(std::string const &name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character();

	// Public methods
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

	// Getters and setters
	std::string const &getName() const;
};

#endif

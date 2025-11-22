#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
	private:

	protected:
		std::string type;

	public:

		AAnimal();
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);
		virtual ~AAnimal();

		// Public methods
		virtual void	makeSound() const = 0;

		// Getters and setters
		std::string getType() const;
};

#endif

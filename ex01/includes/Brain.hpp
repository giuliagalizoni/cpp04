#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:

	protected:
	std::string ideas[100];

	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		// Public methods
		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;
};

#endif

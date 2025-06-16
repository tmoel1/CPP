#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& rhs);
		~Brain();

		void			setIdea(int idx, const std::string& idea);
		std::string		getIdea(int idx) const;

	private:
		std::string ideasArray[100];
};

#endif
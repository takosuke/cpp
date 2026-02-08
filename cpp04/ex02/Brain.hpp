#pragma once
#include <string>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain& b);
		Brain& operator=(const Brain& b);
		~Brain(void);
		std::string ideas[100];
};

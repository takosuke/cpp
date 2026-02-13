#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
	std::srand(std::time(NULL));
	Intern intern;
	Bureaucrat boss("Boss", 1);

	std::cout << "--- Intern creates presidential pardon ---" << std::endl;
	AForm* pardon = intern.makeForm("presidential pardon", "Mussolini");
	if (pardon)
	{
		boss.signForm(*pardon);
		boss.executeForm(*pardon);
		delete pardon;
	}

	std::cout << "--- Intern creates robotomy request ---" << std::endl;
	AForm* robo = intern.makeForm("robotomy request", "Bender");
	if (robo)
	{
		boss.signForm(*robo);
		boss.executeForm(*robo);
		boss.executeForm(*robo);
		delete robo;
	}

	std::cout << "--- Intern creates shrubbery creation ---" << std::endl;
	AForm* shrub = intern.makeForm("shrubbery creation", "Garden");
	if (shrub)
	{
		boss.signForm(*shrub);
		boss.executeForm(*shrub);
		delete shrub;
	}

	std::cout << "--- Intern tries unknown form ---" << std::endl;
	AForm* unknown = intern.makeForm("coffee request", "Kitchen");
	if (unknown)
		delete unknown;
	else
		std::cout << "Form not created (NULL)" << std::endl;
}

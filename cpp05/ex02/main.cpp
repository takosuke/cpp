#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
//#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	Bureaucrat honecker("Honecker", 2);
	PresidentialPardonForm pardon_form("Mussolini");
	Bureaucrat greenparty("The Green Party", 23);
	ShrubberyCreationForm shrub_form("Tempelhof");
	greenparty.signForm(shrub_form);
	greenparty.executeForm(shrub_form);
	greenparty.signForm(pardon_form);
	greenparty.executeForm(pardon_form);
	honecker.signForm(pardon_form);
	honecker.executeForm(pardon_form);
	RobotomyRequestForm roboform("Mario");
	honecker.signForm(roboform);
	honecker.executeForm(roboform);
	honecker.executeForm(roboform);
	honecker.executeForm(roboform);
	honecker.executeForm(roboform);
}

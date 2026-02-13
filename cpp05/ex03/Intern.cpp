#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern&) {}
Intern& Intern::operator=(const Intern&) {
	return *this;
}

Intern::~Intern(){}

AForm* makePresidentialPardonForm(std::string target) 
{
	return new PresidentialPardonForm(target);
}

AForm* makeRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* makeShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm* (*forms[])(const std::string target) = {&makePresidentialPardonForm, &makeRobotomyRequestForm, &makeShrubberyCreationForm};
	std::string form_names[] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < 3; i++)
	{
		if (name == form_names[i])
		{
			std::cout << "Intern creates: " << name << std::endl;
			return (forms[i])(target);
		}
	}
	std::cout << "Intern cannot create form: " << name << std::endl;
	return NULL;
}

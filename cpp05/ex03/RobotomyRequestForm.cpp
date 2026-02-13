#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy Request Form", 72, 45)
{
	_target = "Default target";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request Form", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form)
	: AForm(form)
{
	_target = form._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& form)
{
	if (this != &form)
	{
		AForm::operator=(form);
		this->_target = form._target;
	}
	return *this;
	
}
RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::action() const
{
	std::cout << "** Makes some drilling noises **" << std::endl;
	if (std::rand() % 2)
		std::cout << "** Performs Robotomy on " << _target << " **" << std::endl;
	else
		std::cout << "** Robotomy failed on " << _target << " **" << std::endl;
}

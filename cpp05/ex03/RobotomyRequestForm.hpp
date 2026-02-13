#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		virtual void action() const;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& form);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& form);
		~RobotomyRequestForm();

};

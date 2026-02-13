#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
		virtual void action() const;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& form);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& form);
		~PresidentialPardonForm();

};

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon Form", 25, 5)
{
	_target = "Default target";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon Form", 25, 5)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& form)
	: AForm(form)
{
	_target = form._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& form)
{
	if (this != &form)
	{
		AForm::operator=(form);
		this->_target = form._target;
	}
	return *this;
	
}
PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::action() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <ostream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation Form", 145, 137)
{
	_target = "Default target";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation Form", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form)
	: AForm(form)
{
	_target = form._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form)
{
	if (this != &form)
	{
		AForm::operator=(form);
		this->_target = form._target;
	}
	return *this;
	
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action() const
{
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
		return;
	}
	file << TREE << std::endl;
	file.close();
}

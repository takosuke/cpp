#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"

const std::string TREE = 
"       ###\n"
"      #o###\n"
"    #####o#\n"
"   #o#\\#|#/##\n"
"    ###\\|/#o#\n"
"     # }|{  #\n"
"       }|{\n";

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		virtual void action() const;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& form);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& form);
		~ShrubberyCreationForm();

};

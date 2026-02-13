#include "AForm.hpp"
#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream & out, const AForm& form)
{
	out << form.getName() 
		<< " - required grade to sign: " 
		<< form.getSigningGrade() 
		<< " - required grade to execute: " 
		<< form.getExecGrade()
		<< " - signed: "
		<< (form.getIsSigned() ? "true" : "false");
	return out;
}

AForm::AForm() : _name("Default AForm"), _is_signed(false), _grade_to_sign(150), _grade_to_exec(150)
{}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_exec) : 
	_name(name),
	_is_signed(false),
	_grade_to_sign(validateGrade(grade_to_sign)),
	_grade_to_exec(validateGrade(grade_to_exec))
{
}
AForm::AForm(const AForm& form) : 
	_name(form._name),
	_grade_to_sign(form._grade_to_sign),
	_grade_to_exec(form._grade_to_exec)
{
}
AForm& AForm::operator=(const AForm& form)
{
	if (this != &form)
		_is_signed = form._is_signed;
	return *this;
}

AForm::~AForm() {}

int AForm::validateGrade(int grade)
{
	if (grade < _max_grade)
		throw AForm::GradeTooHighException("Maximum grade is 1");
	if (grade > _min_grade)
		throw AForm::GradeTooLowException("Minimum grade is 150");
	return grade;
}

std::string AForm::getName() const
{
	return _name;
}

int AForm::getSigningGrade() const
{
	return _grade_to_sign;
}

int AForm::getExecGrade() const
{
	return _grade_to_exec;
}

bool AForm::getIsSigned() const
{
	return _is_signed;
}

void AForm::execute(const Bureaucrat& burro) const
{
	if (_is_signed == false)
		throw FormNotSignedException("form is not signed");
	if (burro.getGrade() > _grade_to_exec)
		throw GradeTooLowException("grade is too low");
	action();
}

void AForm::beSigned(const Bureaucrat& burro)
{
	if (burro.getGrade() > _grade_to_sign)
		throw GradeTooLowException("grade is too low");
	_is_signed = true;
}

AForm::GradeTooHighException::GradeTooHighException(const std::string& msg) : message(msg) {}
AForm::GradeTooHighException::~GradeTooHighException() throw() {}
const char* AForm::GradeTooHighException::what() const throw() 
{
	return message.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(const std::string& msg) : message(msg) {}
AForm::GradeTooLowException::~GradeTooLowException() throw() {}
const char* AForm::GradeTooLowException::what() const throw() 
{
	return message.c_str();
}

AForm::FormNotSignedException::FormNotSignedException(const std::string& msg) : message(msg) {}
AForm::FormNotSignedException::~FormNotSignedException() throw() {}
const char* AForm::FormNotSignedException::what() const throw() 
{
	return message.c_str();
}

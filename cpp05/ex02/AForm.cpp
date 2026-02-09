#include "Form.hpp"
#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream & out, const Form& form)
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

Form::Form() : _name("Default Form"), _is_signed(false), _grade_to_sign(150), _grade_to_exec(150)
{}

Form::Form(std::string name, int grade_to_sign, int grade_to_exec) : 
	_name(name),
	_is_signed(false),
	_grade_to_sign(validateGrade(grade_to_sign)),
	_grade_to_exec(validateGrade(grade_to_exec))
{
}
Form::Form(const Form& form) : 
	_name(form._name),
	_grade_to_sign(form._grade_to_sign),
	_grade_to_exec(form._grade_to_exec)
{
}
Form& Form::operator=(const Form& form)
{
	if (this != &form)
		_is_signed = form._is_signed;
	return *this;
}

Form::~Form() {}

int Form::validateGrade(int grade)
{
	if (grade < _max_grade)
		throw Form::GradeTooHighException("Maximum grade is 1");
	if (grade > _min_grade)
		throw Form::GradeTooLowException("Minimum grade is 150");
	return grade;
}

std::string Form::getName() const
{
	return _name;
}

int Form::getSigningGrade() const
{
	return _grade_to_sign;
}

int Form::getExecGrade() const
{
	return _grade_to_exec;
}

bool Form::getIsSigned() const
{
	return _is_signed;
}

void Form::beSigned(const Bureaucrat& burro)
{
	if (burro.getGrade() > _grade_to_sign)
		throw GradeTooLowException("grade is too low");
	_is_signed = true;
}

Form::GradeTooHighException::GradeTooHighException(const std::string& msg) : message(msg) {}
Form::GradeTooHighException::~GradeTooHighException() throw() {}
const char* Form::GradeTooHighException::what() const throw() 
{
	return message.c_str();
}

Form::GradeTooLowException::GradeTooLowException(const std::string& msg) : message(msg) {}
Form::GradeTooLowException::~GradeTooLowException() throw() {}
const char* Form::GradeTooLowException::what() const throw() 
{
	return message.c_str();
}

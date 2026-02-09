#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream & out, const Bureaucrat& burro)
{
	out << burro.getName()
		<< ", bureaucrat grade "
		<< burro.getGrade()
		<< ".";
	return out;
}

Bureaucrat::Bureaucrat() : _name("Default Bureaucrat"), _grade(150)
{}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(validateGrade(grade))
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& burro): 
	_name(burro._name),
	_grade(burro._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& burro)
{
	if (this != &burro)
		_grade = burro._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

int Bureaucrat::validateGrade(int grade)
{
	if (grade < _max_grade)
		throw Bureaucrat::GradeTooHighException("Maximum grade is 1");
	if (grade > _min_grade)
		throw Bureaucrat::GradeTooLowException("Minimum grade is 150");
	return grade;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::inc_grade()
{
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException("Grade already at maximum");
	_grade--;
}

void Bureaucrat::dec_grade()
{
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException("Grade already at minimum");
	_grade++;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& msg) : message(msg) {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}
const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
	return message.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& msg) : message(msg) {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
	return message.c_str();
}

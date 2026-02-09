#pragma once
#include "Bureaucrat.hpp"
#include <exception>
#include <string>
#include <ostream>

class Bureaucrat;

class Form
{
	private:
		const static int _max_grade = 1;
		const static int _min_grade = 150;
		const std::string _name;
		bool _is_signed;
		const int _grade_to_sign;
		const int _grade_to_exec;
		static int validateGrade(int grade);

	public:
		Form();
		Form(std::string name, int grade_to_sign, int grade_to_exec);
		Form(const Form& form);
		Form& operator=(const Form& form);
		~Form();

		std::string getName() const;
		int getSigningGrade() const;
		int getExecGrade() const;
		bool getIsSigned() const;
		void beSigned(const Bureaucrat& burro);

		class GradeTooHighException : public std::exception
		{
			private:
				std::string message;

			public:
				explicit GradeTooHighException(const std::string& msg);
				virtual ~GradeTooHighException() throw();
				const char* what() const throw();

		};
		class GradeTooLowException : public std::exception
		{
			private:
				std::string message;

			public:
				explicit GradeTooLowException(const std::string& msg);
				virtual ~GradeTooLowException() throw();
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream& out, const Form& form);

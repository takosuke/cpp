#pragma once
#include <exception>
#include <ostream>
#include <string>

class Bureaucrat
{
	private:
		std::string _name;
		int _grade;
		const static int _min_grade = 150;
		const static int _max_grade = 1;
		static unsigned int validateGrade(unsigned int grade);
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& burro);
		Bureaucrat& operator=(const Bureaucrat& burro);
		~Bureaucrat();

		std::string getName();
		int getGrade();
		void inc_grade();
		void dec_grade();

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

std::ostream &operator<<(std::ostream& out, const Bureaucrat& burro);

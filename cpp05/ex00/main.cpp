#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main()
{
	try {
		Bureaucrat jobcenter("Job Center", 200);
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat ksk("KSK employee", -1);
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	Bureaucrat pedago("Pedago", 149);
	pedago.dec_grade();
	std::cout << pedago << " is at level " << pedago.getGrade() << std::endl;
	try {
		pedago.dec_grade();
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << pedago << " is at level " << pedago.getGrade() << std::endl;
	Bureaucrat finanzamt("Finanzamt", 3);
	finanzamt.inc_grade();
	std::cout << finanzamt << " is at level " << finanzamt.getGrade() << std::endl;
	finanzamt.inc_grade();
	std::cout << finanzamt << " is at level " << finanzamt.getGrade() << std::endl;
	try {
		finanzamt.inc_grade();
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << finanzamt << " is at level " << finanzamt.getGrade() << std::endl;
}

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main()
{
	std::cout << "--- Grade too low (200) ---" << std::endl;
	try {
		Bureaucrat jobcenter("Job Center", 200);
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << "--- Grade too high (-1) ---" << std::endl;
	try {
		Bureaucrat ksk("KSK employee", -1);
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << "--- Grade too high (0) ---" << std::endl;
	try {
		Bureaucrat zero("Zero", 0);
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << "--- Decrement to bottom ---" << std::endl;
	Bureaucrat pedago("Pedago", 149);
	std::cout << pedago << std::endl;
	pedago.dec_grade();
	std::cout << pedago << std::endl;
	try {
		pedago.dec_grade();
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << "--- Increment to top ---" << std::endl;
	Bureaucrat finanzamt("Finanzamt", 3);
	std::cout << finanzamt << std::endl;
	finanzamt.inc_grade();
	std::cout << finanzamt << std::endl;
	finanzamt.inc_grade();
	std::cout << finanzamt << std::endl;
	try {
		finanzamt.inc_grade();
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << "--- Copy ---" << std::endl;
	Bureaucrat copy(finanzamt);
	std::cout << copy << std::endl;
}

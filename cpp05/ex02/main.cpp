#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

int main()
{
	std::cout << "--- Invalid form grade ---" << std::endl;
	try {
		Form eur("Einnahmenueberschussrechnung", 9000, 9000);
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "--- Form info via operator<< ---" << std::endl;
	Form ausgaben("Ausgaben", 2, 40);
	std::cout << ausgaben << std::endl;

	std::cout << "--- Sign success (grade 1) ---" << std::endl;
	Bureaucrat boss("Boss", 1);
	boss.signForm(ausgaben);
	std::cout << ausgaben << std::endl;

	std::cout << "--- Sign failure (grade too low) ---" << std::endl;
	Form geheim("Geheim", 5, 5);
	Bureaucrat pedago("Pedago", 150);
	pedago.signForm(geheim);

	std::cout << "--- Bureaucrat output ---" << std::endl;
	std::cout << boss << std::endl;
	std::cout << pedago << std::endl;
}

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
		Bureaucrat jobcenter("Job Center", 200);
	catch (const std::exception& e)
		std::cout << "Caught exception: " << e.what() << std::endl;
	Bureaucrat pedago("Pedago", 149);
	pedago.dec_grade();
	try
		pedago.dec_grade();
	catch (const std::exception& e)



}

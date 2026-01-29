#include "Harl.hpp"
#include <iostream>

int	main()
{
	Harl harl;

	std::cout << "Debug level" << std::endl;
	harl.complain("DEBUG");
	std::cout << "Info level" << std::endl;
	harl.complain("INFO");
	std::cout << "Warning level" << std::endl;
	harl.complain("WARNING");
	std::cout << "Error level" << std::endl;
	harl.complain("ERROR");
	std::cout << "Invalid level" << std::endl;
	harl.complain("BULLSHIT");
	return 0;
}

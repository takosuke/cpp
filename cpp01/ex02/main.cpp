#include <string>
#include <iostream>

int	main(void)
{
	std::string s = "Free poopoo for everyone";
	std::string* stringPTR = &s;
	std::string& stringREF = s;
	std::cout << "Memory address of variable s: " << &s << std::endl;
	std::cout << "Memory address of pointer stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address of reference stringREF: " << &stringREF << std::endl;
	std::cout << "Value of variable s: " << s << std::endl;
	std::cout << "Value pointed to by pointer stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by reference stringREF: " << stringREF << std::endl;

	return (0);
}
	

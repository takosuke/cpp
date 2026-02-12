#include <string>
#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
	if (argc == 2)
	{
		
		std::string num = argv[1];
		ScalarConverter::convert(num);
	}
	
	return 0;
}

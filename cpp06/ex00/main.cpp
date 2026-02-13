#include <string>
#include <iostream>
#include "ScalarConverter.hpp"
#define COLOR_CYAN    "\033[36m"
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"

int main(int argc, char** argv)
{
	if (argc == 2)
	{
		
		std::string num = argv[1];
		ScalarConverter::convert(num);
	}
	else
	{
		std::cout << COLOR_CYAN << "Test: Input chars" << COLOR_RESET << std::endl;
		std::cout << "A" << std::endl;
		ScalarConverter::convert("A");
		std::cout << "%" << std::endl;
		ScalarConverter::convert("%");
		std::cout << "=" << std::endl;
		ScalarConverter::convert("=");
		std::cout << "z" << std::endl;
		ScalarConverter::convert("z");

		std::cout << COLOR_CYAN << "Test: Input ints" << COLOR_RESET <<  std::endl;
		std::cout << "0" << std::endl;
		ScalarConverter::convert("0");
		std::cout << "-12345" << std::endl;
		ScalarConverter::convert("-12345");
		std::cout << "+98237491" << std::endl;
		ScalarConverter::convert("+98237491");
		std::cout << "9999999" << std::endl;
		ScalarConverter::convert("9999999");
		std::cout << "-1" << std::endl;
		ScalarConverter::convert("-1");

		std::cout << COLOR_CYAN << "Test: Input doubles" << COLOR_RESET << std::endl;
		std::cout << "19284782391849287374893128102918827982892192839787348" << std::endl;
		ScalarConverter::convert("19284782391849287374893128102918827982892192839787348");
		std::cout << "-3.334231214" << std::endl;
		ScalarConverter::convert("-3.334231214");
		std::cout << "0.12" << std::endl;
		ScalarConverter::convert("0.12");
		std::cout << "-0.66666666666666666666661" << std::endl;
		ScalarConverter::convert("-0.66666666666666666666661");
		std::cout << "9999999999999999999999999999.0" << std::endl;
		ScalarConverter::convert("9999999999999999999999999999.0");

		std::cout << COLOR_CYAN << "Test: Input floats" << COLOR_RESET << std::endl;
		std::cout << "123456f" << std::endl;
		ScalarConverter::convert("123456f");
		std::cout << "-3.334231214f" << std::endl;
		ScalarConverter::convert("-3.334231214f");
		std::cout << "0.12f" << std::endl;
		ScalarConverter::convert("0.12f");
		std::cout << "-0.66666666666666666666661f" << std::endl;
		ScalarConverter::convert("-0.66666666666666666666661f");
		std::cout << "666666.0f" << std::endl;
		ScalarConverter::convert("666666.0f");
		std::cout << COLOR_CYAN << "Test: Input special" << COLOR_RESET << std::endl;
		std::cout << "inf" << std::endl;
		ScalarConverter::convert("inf");
		std::cout << "-inf" << std::endl;
		ScalarConverter::convert("-inf");
		std::cout << "+inf" << std::endl;
		ScalarConverter::convert("+inf");
		std::cout << "inff" << std::endl;
		ScalarConverter::convert("inff");
		std::cout << "-inff" << std::endl;
		ScalarConverter::convert("-inff");
		std::cout << "+inff" << std::endl;
		ScalarConverter::convert("+inff");
		std::cout << "nan" << std::endl;
		ScalarConverter::convert("nan");
		std::cout << COLOR_CYAN << "Test: Input not valid" << COLOR_RESET << std::endl;
		std::cout << "Poopoo" << std::endl;
		ScalarConverter::convert("Poopoo");
		std::cout << "--2344.23.11" << std::endl;
		ScalarConverter::convert("--2344.23.11");
		std::cout << "5a" << std::endl;
		ScalarConverter::convert("5a");
		std::cout << "00df" << std::endl;
		ScalarConverter::convert("00df");
	}
	
	return 0;
}

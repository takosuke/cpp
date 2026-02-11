#include <string>
#include <iostream>
#include <cstdlib>
#include "ScalarConverter.hpp"

/*
struct NumType 
{ 
	enum Value { Int, Double, Float, Char, None };
};

bool isInt(std::string num)
{
	for (std::size_t i = 0; i < num.size(); i++)
	{
		if (!std::isdigit(num[i]))
		{
			if (i == 0 && (num[i] == '-' || num[i] == '+') && num.length() > 1)
				continue ;
			else
				return false;
		}
	}
	return true;
}

NumType::Value checkType(std::string num)
{
	char *end;
	long n = std::strtol(num.c_str(), &end, 10);
	if (num.length() == 1 && std::isprint(num[0]))
		return NumType::Char;
	if (*end == '\0' && n <= INT_MAX && n >= INT_MIN)
		return NumType::Int;
	if (*end == '.')
	{
		std::strtod(num.c_str(), &end);
		if (*end == '\0')
			return NumType::Double;
		if (*end == 'f' && *(end + 1) == '\0')
			return NumType::Float;
	}
	return NumType::None;
}

void printInt(char *num)
{
	int x = std::atoi(num);
	char c = static_cast<char>(x);
	double d = static_cast<double>(x);
	float f = static_cast<float>(x);
	if (x >= 32 && x <= 127)
		std::cout << "Char: " << c << std::endl;
	else
		std::cout << "Char: non displayable" << std::endl;
	std::cout << "Int: " << x << std::endl;
	std::cout << "Double: " << d << std::endl;
	std::cout << "Float: " << f << std::endl;
}

void printChar(char num)
{
	int x = static_cast<int>(num);
	double d = static_cast<double>(num);
	float f = static_cast<float>(num);
	std::cout << "Int: " << x << std::endl;
	std::cout << "Double: " << d << std::endl;
	std::cout << "Float: " << f << std::endl;
}
*/
int main(int argc, char** argv)
{

	if (argc == 2)
	{
		
		std::string num = argv[1];
		ScalarConverter::convert(num);
		/*
		char *pos;
		double d = std::strtod("nan", &pos);
		int a = std::atoi("nan");
		std::cout << "A: " << a << std::endl;

		std::cout << "D: " << d << std::endl;
		NumType::Value type = checkType(num);
		if (type == NumType::Int)
			printInt(argv[1]);
		else if (type == NumType::Char)
			printChar(argv[1][0]);
			*/
	}
	
	return 0;
}

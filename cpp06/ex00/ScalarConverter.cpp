#include <iomanip>
#include <memory>
#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <limits>
#include <cmath>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

/*
void ScalarConverter::printAll(char c, int i, double d, float f)
{
	if (c >= 32 && c < 127)
		std::cout << "Char: " << c << std::endl;
	else
		std::cout << "Char: non displayable" << std::endl;
	std::cout << "Int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Double: " << d << std::endl;
	std::cout << "Float: " << f << "f" << std::endl;
}
*/

void ScalarConverter::printSpecial(std::string num)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible." << std::endl;
	std::cout << "float: " << num << "f" << std::endl;
	std::cout << "double: " << num << std::endl;

}

void ScalarConverter::printDoubleFloat(std::string num)
{
	int x = std::atoi(num.c_str());
	double d = static_cast<double>(x);
	float f = static_cast<float>(x);
	if (x >= 32 && x <= 127)
		std::cout << "Char: " << x << std::endl;
	else
		std::cout << "Char: non displayable" << std::endl;
	std::cout << "int: " << x << std::endl;
	std::cout << "double: " << d << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
}

void ScalarConverter::printInt(std::string num)
{
	int x = std::atoi(num.c_str());
	char c = static_cast<char>(x);
	double d = static_cast<double>(x);
	float f = static_cast<float>(x);
	if (x >= 32 && x <= 127)
		std::cout << "Char: " << c << std::endl;
	else
		std::cout << "Char: non displayable" << std::endl;
	std::cout << "Int: " << x << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Double: " << d << std::endl;
	std::cout << "Float: " << f << "f" << std::endl;
}

void ScalarConverter::printChar(char num)
{
	int x = static_cast<int>(num);
	std::cout << "we are here: " << x << std::endl;
	double d = static_cast<double>(num);
	float f = static_cast<float>(num);
	if (x >= 32 && x < 127)
		std::cout << "Char: " << num << std::endl;
	else
		std::cout << "Char: non displayable" << std::endl;
	std::cout << "int: " << x << std::endl;
	std::cout << "double: " << d << std::endl;
	std::cout << "float: " << f << std::endl;
}

NumType::Value ScalarConverter::checkType(std::string num)
{
	char *end;
	long n = std::strtol(num.c_str(), &end, 10);
	if (num.length() == 1 && std::isprint(num[0]))
	{
		std::cout << "so its a char" << std::endl;
		return NumType::Char;
	}
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

void ScalarConverter::convert(std::string num)

{
	std::string special[] = {"nanf", "inff", "-inff", "nan", "-inf", "inf"};
	for (int i = 0; i < 6; i++)
		if (num == special[i])
			printSpecial(num);
	NumType::Value type = checkType(num);
	if (type == NumType::Int || type == NumType::Char)
		printInt(num);
	/*
	else if (type == NumType::Char)
		printChar(num[0]);
		*/
	else if (type == NumType::Double || type == NumType::Float)
		printDoubleFloat(num);
	else
		std::cout << "whatever you input was definitely not a number" << std::endl;

}

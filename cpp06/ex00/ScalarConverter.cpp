#include <cctype>
#include <iomanip>
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

void ScalarConverter::printSpecial(std::string num)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << num << "f" << std::endl;
	std::cout << "double: " << num << std::endl;
}

NumType::Value ScalarConverter::checkType(std::string num)
{
	char *end;
	long n = std::strtol(num.c_str(), &end, 10);
	if (num.length() == 1 && std::isprint(num[0]) && !std::isdigit(num[0]))
	{
		return NumType::Char;
	}
	if (*end == '\0' && n <= INT_MAX && n >= INT_MIN)
		return NumType::Int;
	if (*end == '\0')
		return NumType::Double;
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

void ScalarConverter::printNum(double d)
{
	if (d >= CHAR_MIN && d <= CHAR_MAX)
	{
		char c = static_cast<char>(d);
		if (std::isprint(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: non displayable" << std::endl;
	} else
		std::cout << "char: impossible" << std::endl;
	if (d >= INT_MIN && d <= INT_MAX)
	{
		int x = static_cast<int>(d);
		std::cout << "int: " << x << std::endl;
	} else 
		std::cout << "int: impossible" << std::endl;
	float f = static_cast<float>(d);
	if (d == std::floor(d))
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << d << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout.unsetf(std::ios::fixed);
	std::cout << std::setprecision(6);
}

double ScalarConverter::parseNum(std::string num, NumType::Value type)
{
	if (type == NumType::Char)
		return static_cast<double>(num[0]);
	if (type == NumType::Double || type == NumType::Float || type == NumType::Int)
		return std::strtod(num.c_str(), NULL);
	return 0;
}

void ScalarConverter::convert(std::string num)
{
	std::string special_d[] = {"nan", "-inf", "+inf", "inf"};
	std::string special_f[] = {"nanf", "-inff", "+inff", "inff"};
	for (int i = 0; i < 4; i++)
		if (num == special_d[i] || num == special_f[i]) {
			printSpecial(special_d[i]);
			return ; 
		}
	NumType::Value type = checkType(num);
	if (type == NumType::None)
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	double d = parseNum(num, type);
	printNum(d);
}

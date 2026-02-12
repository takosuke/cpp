#include <cctype>
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

void ScalarConverter::printSpecial(std::string num)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << num << "f" << std::endl;
	std::cout << "double: " << num << std::endl;
}

/*
void ScalarConverter::printFloat(std::string num)
{
	double f = std::strtof(num.c_str(), NULL);
	int x = static_cast<int>(f);
	char c = static_cast<char>(x);
	float d = static_cast<float>(f);
	if (x >= 32 && x <= 127)
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	std::cout << "int: " << x << std::endl;
	std::cout << "double: " << d << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
}

void ScalarConverter::printDouble(std::string num)
{
	double d = std::strtod(num.c_str(), NULL);
	int x = static_cast<int>(d);
	char c = static_cast<char>(x);
	float f = static_cast<float>(d);
	if (x >= 32 && x <= 127)
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
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
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	std::cout << "int: " << x << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << d << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
}

void ScalarConverter::printChar(char num)
{
	int x = static_cast<int>(num);
	double d = static_cast<double>(num);
	float f = static_cast<float>(num);
	if (x >= 32 && x < 127)
		std::cout << "char: " << num << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	std::cout << "int: " << x << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << d << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
}
*/


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
	/*
	if (type == NumType::Int)
		printInt(num);
	else if (type == NumType::Char)
		printChar(num[0]);
	else if (type == NumType::Double)
		printDouble(num);
	else if (type == NumType::Float)
		printFloat(num);
	else
		std::cout << "Invalid input" << std::endl;
		*/
}

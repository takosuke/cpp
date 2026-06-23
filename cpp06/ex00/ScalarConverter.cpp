#include <cctype>
#include <iomanip>
#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
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

static void printChar(char c)
{
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
}

static void printFloat(float f)
{
	if (f == std::floor(f))
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	std::cout.unsetf(std::ios::fixed);
	std::cout << std::setprecision(6);
}

static void printDouble(double d)
{
	if (d == std::floor(d))
		std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
	else
		std::cout << "double: " << d << std::endl;
	std::cout.unsetf(std::ios::fixed);
	std::cout << std::setprecision(6);
}

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
	if (num.empty())
		return NumType::None;
	if (num.length() == 1 && std::isprint(num[0]) && !std::isdigit(num[0]))
		return NumType::Char;
	if (*end == '\0' && n <= INT_MAX && n >= INT_MIN)
		return NumType::Int;
	if (*end == '\0')
		return NumType::Double;
	std::strtod(num.c_str(), &end);
	if (*end == '\0')
		return NumType::Double;
	if (*end == 'f' && *(end + 1) == '\0')
		return NumType::Float;
	return NumType::None;
}

void ScalarConverter::printFromChar(char c)
{
	printChar(c);
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void ScalarConverter::printFromInt(int n)
{
	if (n >= CHAR_MIN && n <= CHAR_MAX)
		printChar(static_cast<char>(n));
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << n << std::endl;
	printFloat(static_cast<float>(n));
	printDouble(static_cast<double>(n));
}

void ScalarConverter::printFromFloat(float f)
{
	if (f >= CHAR_MIN && f <= CHAR_MAX)
		printChar(static_cast<char>(f));
	else
		std::cout << "char: impossible" << std::endl;
	if (static_cast<double>(f) >= INT_MIN && static_cast<double>(f) <= INT_MAX)
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	printFloat(f);
	printDouble(static_cast<double>(f));
}

void ScalarConverter::printFromDouble(double d)
{
	if (d >= CHAR_MIN && d <= CHAR_MAX)
		printChar(static_cast<char>(d));
	else
		std::cout << "char: impossible" << std::endl;
	if (d >= INT_MIN && d <= INT_MAX)
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	printFloat(static_cast<float>(d));
	printDouble(d);
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
	if (type == NumType::Char)
		printFromChar(num[0]);
	else if (type == NumType::Int)
		printFromInt(static_cast<int>(std::strtol(num.c_str(), NULL, 10)));
	else if (type == NumType::Float)
		printFromFloat(std::strtof(num.c_str(), NULL));
	else if (type == NumType::Double)
		printFromDouble(std::strtod(num.c_str(), NULL));
	else
		std::cout << "Invalid input" << std::endl;
}

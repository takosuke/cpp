#pragma once
#include <string>

struct NumType 
{ 
	enum Value { Int, Double, Float, Char, None };
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

		static NumType::Value checkType(std::string num);
		static void printSpecial(std::string num);
		static void printFromChar(char c);
		static void printFromInt(int n);
		static void printFromFloat(float f);
		static void printFromDouble(double d);

	public:
		static void convert(std::string num);
};

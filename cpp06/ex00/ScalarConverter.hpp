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
//		static void printAll(char c, int i, double d, float f);
		static void printSpecial(std::string num);
		static void printInt(std::string num);
		static void printChar(char num);
		static void printDoubleFloat(std::string num);
		static NumType::Value checkType(std::string num);

	public:
		static void convert(std::string num);
};

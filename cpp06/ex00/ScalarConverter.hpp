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
		static double parseNum(std::string num, NumType::Value type);
		static void printSpecial(std::string num);
		static void printNum(double d);
		/*
		static void printInt(std::string num);
		static void printChar(char num);
		static void printDouble(std::string num);
		static void printFloat(std::string num);
		*/

	public:
		static void convert(std::string num);
};

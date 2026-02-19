#include <iostream>
#include "Array.hpp"

int main()
{
	Array<double> b;
	std::cout << b.size() << std::endl;

	Array<int> a(3);
	std::cout << a.size() << std::endl;
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i * 3;
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;
	Array<int> c(a);
	std::cout << c.size() << std::endl;
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << c[i] << std::endl;
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i * 5 + 2;
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << c[i] << std::endl;
	c = a;
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << c[i] << std::endl;
	


	//
//	std::cout << a[0] << std::endl;
	/*
	Array<int> a(42);
	Array<std::string> b("cat");

	Array<int> c(a);
	Array<int> d;
	d = a;
	Array<

	std::cout << a.getValue() << std::endl;
	std::cout << b.getValue() << std::endl;
	std::cout << c.getValue() << std::endl;
	std::cout << d.getValue() << std::endl;
	*/
}

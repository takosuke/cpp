#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <vector>
#include <list>

int main()
{
	// TODO flesh out tests
	std::list<int> v;
	v.push_back(1);
	v.push_back(4);
	v.push_back(9);
	v.push_back(1234);
	v.push_back(42);
	for (std::list<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << std::endl;
	try {
		std::list<int>::iterator x = easyfind(v, 42);
		std::cout << "Found x: " << *x << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Didn't find " << e.what() << std::endl;
	}
	
}

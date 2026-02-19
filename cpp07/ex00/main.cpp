#include "whatever.hpp"
#include <iostream>

int main()
{
	std::cout << "Max of 3 and 5: " << max(3, 5) << std::endl;
	std::cout << "Max of calamari and octopus: " << max("calamari", "octopus") << std::endl;
	int a = 35;
	int b = 12;
	std::cout << "Min of a(35) and b(12): " << min(a, b) << std::endl;

	swap(&a, &b);
	std::cout << "a is now: " << a << " and b is now " << b << std::endl;
}

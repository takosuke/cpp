#include "Span.hpp"
#include <iostream>

int main()
{
	Span spoon(1000000);
	spoon.randomFill();	
	spoon.printVector();
	std::cout << "Shortest span: " << spoon.shortestSpan() << std::endl;
	std::cout << "Longest span: " << spoon.longestSpan() << std::endl;
}

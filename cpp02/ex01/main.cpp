#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	std::cout << "=== Subject tests ===" << std::endl;
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << std::endl << "=== Additional tests ===" << std::endl;

	std::cout << std::endl << "--- Negative numbers ---" << std::endl;
	Fixed neg1(-42);
	Fixed neg2(-3.14f);
	std::cout << "neg1 (int -42): " << neg1 << " -> toInt: " << neg1.toInt() << std::endl;
	std::cout << "neg2 (float -3.14): " << neg2 << " -> toInt: " << neg2.toInt() << std::endl;

	std::cout << std::endl << "--- Zero ---" << std::endl;
	Fixed zero1(0);
	Fixed zero2(0.0f);
	std::cout << "zero1 (int 0): " << zero1 << std::endl;
	std::cout << "zero2 (float 0.0): " << zero2 << std::endl;

	std::cout << std::endl << "--- Small fractional values ---" << std::endl;
	Fixed small1(0.5f);
	Fixed small2(0.25f);
	Fixed small3(0.125f);
	Fixed small4(0.00390625f);
	std::cout << "0.5f: " << small1 << std::endl;
	std::cout << "0.25f: " << small2 << std::endl;
	std::cout << "0.125f: " << small3 << std::endl;
	std::cout << "0.00390625f (1/256, smallest): " << small4 << std::endl;

	std::cout << std::endl << "--- getRawBits / setRawBits ---" << std::endl;
	Fixed raw;
	raw.setRawBits(256);
	std::cout << "After setRawBits(256): " << raw << " (should be 1)" << std::endl;
	std::cout << "getRawBits: " << raw.getRawBits() << " (should be 256)" << std::endl;

	std::cout << std::endl << "--- Copy assignment to self ---" << std::endl;
	Fixed self(5);
	self = self;
	std::cout << "After self-assignment: " << self << std::endl;

	return 0;
}

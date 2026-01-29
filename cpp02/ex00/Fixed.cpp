#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): _x(0) {
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& fp)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fp;

}
Fixed &Fixed::operator=(const Fixed& fp) 
{
	std::cout << "Copy assignment operator called" << std::endl;
	_x = fp.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return _x;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_x = raw;
}

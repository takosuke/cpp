#include "Fixed.hpp"
#include <iostream>
#include <cmath>

std::ostream &operator<<(std::ostream & out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}

Fixed::Fixed(): _x(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int x) : _x(x << _bits) 
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float x) : _x((int)roundf(x * (1 << _bits))) 
{
	std::cout << "Int constructor called" << std::endl;
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

float Fixed::toFloat(void) const
{
	return ((float)_x / (1 << _bits));
}

int Fixed::toInt(void) const
{
	return (_x >> _bits);
}

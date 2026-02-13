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
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fp) : _x(fp._x)
{
	std::cout << "Copy constructor called" << std::endl;
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

// overloaded comparison  operators

bool Fixed::operator>(const Fixed& fp) const
{
	return this->_x > fp._x;
}

bool Fixed::operator<(const Fixed& fp) const
{
	return this->_x < fp._x;
}

bool Fixed::operator>=(const Fixed& fp) const
{
	return this->getRawBits() >= fp.getRawBits();
}

bool Fixed::operator<=(const Fixed& fp) const
{
	return this->getRawBits() <= fp.getRawBits();
}

bool Fixed::operator==(const Fixed& fp) const
{
	return this->getRawBits() == fp.getRawBits();
}

bool Fixed::operator!=(const Fixed& fp) const
{
	return this->getRawBits() != fp.getRawBits();
}

// overloaded arithmetic operators

Fixed Fixed::operator+(const Fixed& fp) const
{
	Fixed result;
	result.setRawBits(this->_x + fp._x);
	return result;
}

Fixed Fixed::operator-(const Fixed& fp) const
{
	Fixed result;
	result.setRawBits(this->_x - fp._x);
	return result;
}

Fixed Fixed::operator*(const Fixed& fp) const
{
	Fixed result;
	long long tmp = (long long)this->getRawBits() * (long long)fp.getRawBits();
	result.setRawBits((int)(tmp >> _bits));
	return result;
}

Fixed Fixed::operator/(const Fixed& fp) const
{
	if (fp.getRawBits() == 0)
	{
		std::cout << "Division by 0 is not allowed" << std::endl;
		return Fixed();
	}
	Fixed result;
	long long tmp = (long long)this->getRawBits() << _bits;
	result.setRawBits((int)tmp / fp.getRawBits());
	return result;
}

// overloaded increment operators

Fixed &Fixed::operator++(void)
{
	this->_x++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_x++;
	return tmp;
}

Fixed &Fixed::operator--(void)
{
	this->_x--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_x--;
	return tmp;
}

// static member fns

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
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

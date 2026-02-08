#pragma once
#include <ostream>


class Fixed
{
	private:
		int	_x;
		static const int _bits = 8;
public:
	// Canonical class functions
	Fixed(void);
	Fixed(const int x);
	Fixed(const float x);
	Fixed(const Fixed& fp);
	Fixed &operator=(const Fixed& fp);
	~Fixed(void);

	// overloaded comparison operators
	bool operator>(const Fixed& fp) const;	
	bool operator<(const Fixed& fp) const;	
	bool operator>=(const Fixed& fp) const;	
	bool operator<=(const Fixed& fp) const;	
	bool operator==(const Fixed& fp) const;	
	bool operator!=(const Fixed& fp) const;	

	// overloaded arithmetic operators
	Fixed operator+(const Fixed& fp) const;
	Fixed operator-(const Fixed& fp) const;
	Fixed operator*(const Fixed& fp) const;
	Fixed operator/(const Fixed& fp) const;
	
	// overloaded increment operators
	Fixed  &operator++(void);
	Fixed operator++(int);
	Fixed  &operator--(void);
	Fixed operator--(int);

	// static member fns
	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);

	// member fns
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream& out, const Fixed& fixed);

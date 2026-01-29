#pragma once
#include <ostream>


class Fixed
{
	private:
		int	_x;
		static const int _bits = 8;
public:
	Fixed(void);
	Fixed(const int x);
	Fixed(const float x);
	Fixed(const Fixed& fp);
	Fixed &operator=(const Fixed& fp);
	~Fixed(void);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream& out, const Fixed& fixed);

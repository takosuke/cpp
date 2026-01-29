#pragma once

class Fixed
{
	private:
		int	_x;
		static const int _bits = 8;
public:
	Fixed(void);
	Fixed(const Fixed& fp);
	Fixed &operator=(const Fixed& fp);
	~Fixed(void);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

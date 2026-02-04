#include "Fixed.hpp"
#include <iostream>


int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << std::endl << "--- Addition/Subtraction tests ---" << std::endl;
    // These tests would fail with the old broken implementation
    // Old impl: return Fixed(this->getRawBits() + fp.getRawBits())
    // This passed raw bits to int constructor, which shifted them again!
    // e.g., 2.5 + 1.5: raw bits are 640 + 384 = 1024
    //       Old impl would do Fixed(1024) = 1024 << 8 = 262144 raw = 1024.0!
    //       Correct result should be 4.0

    Fixed x(2.5f);
    Fixed y(1.5f);
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "x + y = " << x + y << " (expected: 4)" << std::endl;
    std::cout << "x - y = " << x - y << " (expected: 1)" << std::endl;

    Fixed c(10);
    Fixed d(3);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "c + d = " << c + d << " (expected: 13)" << std::endl;
    std::cout << "c - d = " << c - d << " (expected: 7)" << std::endl;

    std::cout << std::endl << "--- Multiplication/Division tests ---" << std::endl;
    Fixed e(6.0f);
    Fixed f(2.0f);
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "e * f = " << e * f << " (expected: 12)" << std::endl;
    std::cout << "e / f = " << e / f << " (expected: 3)" << std::endl;
    std::cout << "e * 0.5 = " << e * Fixed(0.5f) << " (expected: 3)" << std::endl;
    std::cout << "10 / 4 = " << Fixed(10) / Fixed(4) << " (expected: 2.5)" << std::endl;

    std::cout << std::endl << "--- Division by zero test ---" << std::endl;
    Fixed zero(0);
    std::cout << "5 / 0 = " << Fixed(5) / zero << std::endl;

    std::cout << std::endl << "--- Comparison operators tests ---" << std::endl;
    Fixed g(5.5f);
    Fixed h(5.5f);
    Fixed i(3.0f);
    std::cout << "g = " << g << ", h = " << h << ", i = " << i << std::endl;
    std::cout << "g > i: " << (g > i ? "true" : "false") << " (expected: true)" << std::endl;
    std::cout << "g < i: " << (g < i ? "true" : "false") << " (expected: false)" << std::endl;
    std::cout << "g >= h: " << (g >= h ? "true" : "false") << " (expected: true)" << std::endl;
    std::cout << "g <= h: " << (g <= h ? "true" : "false") << " (expected: true)" << std::endl;
    std::cout << "g == h: " << (g == h ? "true" : "false") << " (expected: true)" << std::endl;
    std::cout << "g != i: " << (g != i ? "true" : "false") << " (expected: true)" << std::endl;
    std::cout << "g != h: " << (g != h ? "true" : "false") << " (expected: false)" << std::endl;

    std::cout << std::endl << "--- Increment/Decrement tests ---" << std::endl;
    Fixed j(0);
    std::cout << "j = " << j << std::endl;
    std::cout << "++j = " << ++j << " (smallest increment: 1/256)" << std::endl;
    std::cout << "j++ = " << j++ << std::endl;
    std::cout << "j = " << j << std::endl;
    std::cout << "--j = " << --j << std::endl;
    std::cout << "j-- = " << j-- << std::endl;
    std::cout << "j = " << j << std::endl;

    std::cout << std::endl << "--- Min/Max tests ---" << std::endl;
    Fixed k(42.42f);
    Fixed l(42.41f);
    std::cout << "k = " << k << ", l = " << l << std::endl;
    std::cout << "min(k, l) = " << Fixed::min(k, l) << " (expected: ~42.41)" << std::endl;
    std::cout << "max(k, l) = " << Fixed::max(k, l) << " (expected: ~42.42)" << std::endl;

    const Fixed m(100.0f);
    const Fixed n(50.0f);
    std::cout << "const m = " << m << ", const n = " << n << std::endl;
    std::cout << "min(m, n) = " << Fixed::min(m, n) << " (expected: 50)" << std::endl;
    std::cout << "max(m, n) = " << Fixed::max(m, n) << " (expected: 100)" << std::endl;

    std::cout << std::endl << "--- Negative numbers tests ---" << std::endl;
    Fixed neg(-5.5f);
    Fixed pos(3.0f);
    std::cout << "neg = " << neg << ", pos = " << pos << std::endl;
    std::cout << "neg + pos = " << neg + pos << " (expected: -2.5)" << std::endl;
    std::cout << "neg - pos = " << neg - pos << " (expected: -8.5)" << std::endl;
    std::cout << "neg * pos = " << neg * pos << " (expected: -16.5)" << std::endl;
    std::cout << "neg / pos = " << neg / pos << " (expected: ~-1.83)" << std::endl;
    std::cout << "neg < pos: " << (neg < pos ? "true" : "false") << " (expected: true)" << std::endl;

    std::cout << std::endl << "--- toInt tests ---" << std::endl;
    Fixed pi(3.14159f);
    Fixed big(1234.5678f);
    std::cout << "pi = " << pi << ", toInt = " << pi.toInt() << " (expected: 3)" << std::endl;
    std::cout << "big = " << big << ", toInt = " << big.toInt() << " (expected: 1234)" << std::endl;

    std::cout << std::endl << "--- Chained operations test ---" << std::endl;
    Fixed result = (Fixed(10) + Fixed(5)) * Fixed(2) - Fixed(3);
    std::cout << "(10 + 5) * 2 - 3 = " << result << " (expected: 27)" << std::endl;

    return 0;
}

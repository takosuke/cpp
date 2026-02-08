#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main(void)
{
	// Triangle vertices: A(0,0), B(10,0), C(5,10)
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);

	std::cout << "Triangle: A(0,0), B(10,0), C(5,10)" << std::endl;
	std::cout << std::endl;

	// Test points
	std::cout << "--- Point inside triangle ---" << std::endl;
	Point p1(5.0f, 5.0f);
	std::cout << "Point (5,5): " << (bsp(a, b, c, p1) ? "inside" : "outside") << std::endl;

	Point p2(5.0f, 2.0f);
	std::cout << "Point (5,2): " << (bsp(a, b, c, p2) ? "inside" : "outside") << std::endl;

	std::cout << std::endl << "--- Point outside triangle ---" << std::endl;
	Point p3(0.0f, 10.0f);
	std::cout << "Point (0,10): " << (bsp(a, b, c, p3) ? "inside" : "outside") << std::endl;

	Point p4(11.0f, 0.0f);
	std::cout << "Point (11,0): " << (bsp(a, b, c, p4) ? "inside" : "outside") << std::endl;

	Point p5(-1.0f, -1.0f);
	std::cout << "Point (-1,-1): " << (bsp(a, b, c, p5) ? "inside" : "outside") << std::endl;

	std::cout << std::endl << "--- Point on edge (should be outside) ---" << std::endl;
	Point p6(5.0f, 0.0f);
	std::cout << "Point (5,0) on edge AB: " << (bsp(a, b, c, p6) ? "inside" : "outside") << std::endl;

	Point p7(2.5f, 5.0f);
	std::cout << "Point (2.5,5) on edge AC: " << (bsp(a, b, c, p7) ? "inside" : "outside") << std::endl;

	std::cout << std::endl << "--- Point on vertex (should be outside) ---" << std::endl;
	Point p8(0.0f, 0.0f);
	std::cout << "Point (0,0) on vertex A: " << (bsp(a, b, c, p8) ? "inside" : "outside") << std::endl;

	Point p9(10.0f, 0.0f);
	std::cout << "Point (10,0) on vertex B: " << (bsp(a, b, c, p9) ? "inside" : "outside") << std::endl;

	return 0;
}

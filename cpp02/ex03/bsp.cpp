#include "Point.hpp"

/*
** Binary Space Partitioning approach:
** For each edge of the triangle, compute which side the point is on.
** If the point is on the same side of all three edges, it's inside.
**
** We use the cross product (2D equivalent) to determine the side:
** sign = (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x)
**
** If sign > 0: point is on the left side of edge AB
** If sign < 0: point is on the right side of edge AB
** If sign == 0: point is on the edge (considered NOT inside)
*/

static Fixed crossProduct(Point const &a, Point const &b, Point const &p)
{
	return (b.getX() - a.getX()) * (p.getY() - a.getY())
		 - (b.getY() - a.getY()) * (p.getX() - a.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1 = crossProduct(a, b, point);
	Fixed d2 = crossProduct(b, c, point);
	Fixed d3 = crossProduct(c, a, point);

	bool hasNeg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
	bool hasPos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));

	// Point is on edge or vertex if any cross product is zero
	if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0))
		return false;

	// Point is inside only if all cross products have the same sign
	return !(hasNeg && hasPos);
}

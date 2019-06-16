#include "Triangle.h"

Triangle::Triangle(int a, int b, int c):Polygon(3)
{
	setSide(0, a);
	setSide(1, b);
	setSide(2, c);
}

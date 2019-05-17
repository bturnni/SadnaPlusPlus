#include "Rectangle.h"

Rectangle::Rectangle(int a, int b):Polygon(4)
{
	setSide(0, a);
	setSide(1, b);
	setSide(2, a);
	setSide(3, b);
}

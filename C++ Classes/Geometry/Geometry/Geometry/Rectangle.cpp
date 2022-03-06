#include "Rectangle.h"

Rectangle::Rectangle() {
	height = 0;
	width = 0;
}

Rectangle::Rectangle(double h, double w) : height(h), width(w)
{ }

/*

Rectangle::Rectangle(double h, double w) {
height = h;
width = w;
}

*/

Rectangle::Rectangle(Rectangle* r) {
	height = r->height;
	width = r->width;
}

Rectangle::~Rectangle()
{
}

// Methods

double Rectangle::GetArea() {
	return height*width;
}
double Rectangle::GetPerimeter() {
	return 2.0 * height + 2.0 * width;
}
void Rectangle::DisplayDimensions() {
	cout << "Rectangle information :" << endl;
	cout << "Height:" << height << endl;
	cout << "Width:" << width << endl;
}

#include "Circle.h"
#include <cmath>

Circle::Circle() {
	radius = 0;
}

Circle::Circle(double r): radius(r) 
{}

/*
Circle::Circle(double r) {
	radius = r;
}
*/

Circle::~Circle()
{ }


double Circle::GetArea() {
	return radius* radius *M_PI;
}
double Circle::GetPerimeter() {
	return 2.0 *M_PI*this->radius;
	// return 2.0 *M_PI*radius;

}
void Circle::DisplayDimensions() {
	cout << "Circle information :" << endl;
	cout << "Radius:" << radius << endl;
}
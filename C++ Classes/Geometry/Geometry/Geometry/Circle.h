#pragma once
#include "Shape.h"

//#define _USE_MATH_DEFINES
//#include <math.h> // to get the PI constant

// Example to define a constant with #define
# define M_PI           3.14159265358979323846  /* pi */

// "A circle is a kind of shape"

class Circle : public Shape
{
public:
	// Constructor 
	Circle();
	Circle(double r);
	~Circle();

	double GetRadius() const { return radius; }
	void SetRadius(double r) { radius = r; }

	Shape* clone() { return new Circle(); }
	
	// Methods
	double GetArea();
	double GetPerimeter();
	void DisplayDimensions();
	string GetType() { return "Circle"; } // it will display shape because of the parent class
	string GetType1() { return "Circle"; }

private:
	// properties
	double radius; // it is private you can only access it through the body of the methods from the class Circle.
};


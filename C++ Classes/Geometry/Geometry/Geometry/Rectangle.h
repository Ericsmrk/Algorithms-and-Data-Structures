#pragma once
#include "Shape.h"
class Rectangle : public Shape
{
public:
	Rectangle(); // default constructor
	Rectangle(double h, double w); // constructor with parameters
	Rectangle(Rectangle* r); // constructor by copy from a pointer on an object
	~Rectangle();

	// Methods:
	double GetHeight() const { return height; }
	double GetWidth() const { return width; }
	void SetHeight(double h) { height = h; }
	void SetWidth(double w) { width = w; }

	Shape* clone() { return new Rectangle(); }

	double GetArea();
	double GetPerimeter();
	void DisplayDimensions();
	string GetType() { return "Rectangle"; } // it will display shape because of the parent class
	string GetType1() { return "Rectangle"; }

private:
	// properties
	double height, width; // it is private you can only access it through the body of the methods from the class Circle.

};


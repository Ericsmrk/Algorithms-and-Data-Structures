// CSci115 - Algorithms & Data Structures
// Reminder about Classes in C++
// How to start in a clean way

using namespace std;
#include <iostream>

#include "Shape.h" // class parent of circle and rectangle
#include "ShapeFactory.h" // special class to create a circle or rectangle dynamically
#include "Circle.h" 
#include "Rectangle.h"

// By copy -  DO NOT DO
void f1(Circle c)
{
	cout << "Display dimensions" << endl;
	c.DisplayDimensions();
}

// By pointer
void f2(Circle* c)  // Is c pointing on something? on something valid?
{
	cout << "Display dimensions" << endl;
	if (c!=nullptr)
		c->DisplayDimensions();
}

// By reference (you can modify c! warining - use const keyword appropriately)
void f2(Circle &c)
{
	cout << "Display dimensions" << endl;
	c.DisplayDimensions();
}


int main()
{
	// Shape* s = new Shape(); -> Error cannot instantiate an abstract class

	/* Definition:
	An abstract class is a class that is designed to be specifically used as a base class. 
	An abstract class contains at least one pure virtual function. 
	You declare a pure virtual function by using a pure specifier ( = 0 ) 
	in the declaration of a virtual member function in the class declaration.
	*/

	// Regular way
	Circle c1(10);
	c1.DisplayDimensions();

	// Pointers
	Circle* c = new Circle(10);
	c->DisplayDimensions();

	Rectangle* r = new Rectangle(5, 7);
	r->DisplayDimensions();

	Rectangle* r1 = new Rectangle(r);
	r1->DisplayDimensions();

	delete c; // for each new you have a delete !
 	delete r; // for each new you have a delete !

	Shape* s; 
	int type = 1;
	// pointer to a shape, at this stage there is NO creation of object from the class Shape.
	// It is not possible anyways because it is an abstract class.
	s = ShapeFactory::makeShape(type); // 1 = Circle
	cout << "Area:" << s->GetArea() << endl;
	cout << "Type:" << s->GetType() << endl; // call of a non virtual function 
	cout << "Type1:" << s->GetType1() << endl; // call of a virtual function

    return 0;
}


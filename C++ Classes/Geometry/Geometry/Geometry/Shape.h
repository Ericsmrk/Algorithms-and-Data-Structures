#pragma once

using namespace std;
#include <iostream>
#include <string>
#include <typeinfo>
#include <initializer_list>

// It is the parent class, it has two children: circle and rectangle
class Shape
{
public:
	Shape();
	~Shape();

	string GetColor() { return color; }
	void SetColor(string c) { color = c; }

	// Methods

	/* Definition: 
	A virtual function a member function which is declared within base class, and it is redefined by a derived class. 
	When you refer to a derived class object using a pointer or a reference to the base class, 
	you can call a virtual function for that object and execute the derived class’s version of the function.*/

	// Non-virtual functions: resolved statically at Compile time, 
	// Virtual functions: resolved dynamically at Run time.

	virtual Shape* clone() = 0;

	virtual double GetArea() { return 0;  }
	virtual double GetPerimeter() { return 0; }
	virtual void DisplayDimensions() {}
	string GetType() { return string("Shape");  } // it will return shape because it is not virtual
	virtual string GetType1() { return ""; } // it will return what is implemented in the children classes

protected:
	/* Definition: 
	A protected member variable or function is quite similar to a private member,
	but it provided one additional benefit that they can be accessed in child classes which are called derived classes.*/

	int tmp; // tmp can be directly accessed in Circle and Rectangle

private:
	string color; // color canNOT be accessed in Circle and Rectangle

};


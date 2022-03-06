#include "ShapeFactory.h"

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

Shape* ShapeFactory::mShapeTypes[] = { 	new Rectangle, new Circle };

Shape* ShapeFactory::makeShape(int choice)
{
	return mShapeTypes[choice]->clone();
}

// for_each op ()
struct Destruct
{
	void operator()(Shape *a) const {
		delete a;
	}
};
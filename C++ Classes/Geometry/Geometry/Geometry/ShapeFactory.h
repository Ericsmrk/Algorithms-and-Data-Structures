#pragma once
#include "Shape.h"
const int N = 2; // number of shapes

class ShapeFactory
{
public:
	ShapeFactory() {}
	~ShapeFactory() {}
	static Shape* makeShape(int choice);
private:
	static Shape* mShapeTypes[N];
};



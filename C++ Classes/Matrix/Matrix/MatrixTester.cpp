#include <iostream>
#include "Matrix.h"
using namespace std;

//testing some functions
void test1();

int main(){

	////test1();
	Matrix* myIMatrix = new Matrix(15, 15, 5);
	myIMatrix->SetVal(12, 14, 1);
	myIMatrix->DisplayIntMatrixWithLabels();
	myIMatrix->GetMin();
	myIMatrix->DisplayMin();
}

//test for first set of funcionality
void test1(){

	Matrix* myCMap = new Matrix(15, 15);
	myCMap->DisplayCharMatrixWithLabels();
	myCMap->DisplayIntMatrixWithLabels();
	myCMap->~Matrix();

	Matrix* myCMatrix2 = new Matrix(15, 15, 'L');
	Matrix* myIMatrix = new Matrix(15, 15, 5);
	myCMatrix2->DisplayCharMatrixWithLabels();
	myIMatrix->DisplayIntMatrixWithLabels();
	myCMatrix2->~Matrix();
	myIMatrix->~Matrix();

	Matrix* myCMatrix3 = new Matrix(5, 5, '#');
	myCMatrix3->DisplayCharMatrix();
	myCMatrix3->~Matrix();

	Matrix* myCMatrix4 = new Matrix(5, 5, 3);
	myCMatrix4->DisplayIntMatrix();
	myCMatrix4->~Matrix();

	//TESTED ALL DISPLAY AND CONSTRUCTORS
	Matrix* level1 = new Matrix(5, 5, '#');
	level1->DisplayCharMatrix();
	cout << "Terrain at 2,3: " << level1->GetChar(2, 3) << endl;
	level1->SetChar(2, 3, 'F');
	level1->DisplayCharMatrix();
	cout << "Terrain at 2,3: " << level1->GetChar(2, 3) << endl;
}

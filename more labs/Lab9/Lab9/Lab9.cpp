//Lab 9 CSCI 115 Spring 2021
//Eric Smrkovsky
#include "GraphAM.h"
#include <iostream>
using namespace std;

void testGetMin();
void xandersGraphTest();//can't work because it is a directed graph..

int main(){
	//testGetMin();
	//xandersGraphTest();
	GraphAM* ITAExampleGraph = new GraphAM(9);
	cout << "\n\n  Graph from page 632 in ITA 3rd\n\n";
	ITAExampleGraph->SetUndirectedEdge(0, 1, 4);
	ITAExampleGraph->SetUndirectedEdge(0, 7, 8);
	ITAExampleGraph->SetUndirectedEdge(1, 7, 11);
	ITAExampleGraph->SetUndirectedEdge(1, 2, 8);
	ITAExampleGraph->SetUndirectedEdge(7, 8, 7);
	ITAExampleGraph->SetUndirectedEdge(8, 2, 2);
	ITAExampleGraph->SetUndirectedEdge(8, 6, 6);
	ITAExampleGraph->SetUndirectedEdge(7, 6, 1);
	ITAExampleGraph->SetUndirectedEdge(6, 5, 2);
	ITAExampleGraph->SetUndirectedEdge(5, 4, 10);
	ITAExampleGraph->SetUndirectedEdge(3, 5, 14);
	ITAExampleGraph->SetUndirectedEdge(3, 4, 9);
	ITAExampleGraph->SetUndirectedEdge(2, 3, 7);
	ITAExampleGraph->SetUndirectedEdge(2, 5, 4);
	ITAExampleGraph->DisplayConvertToChar();
	ITAExampleGraph->MSTKruskal(0);//change to 1 to see too much debugging
	ITAExampleGraph->DisplayConvertToChar();
}

void xandersGraphTest() {
	
	GraphAM* XandersGraph = new GraphAM(6);
	cout << "\n\n	Xanders Graph\n\n";
	XandersGraph->SetDirectedEdge(0, 2, 4);
	XandersGraph->SetDirectedEdge(0, 1, 3);
	XandersGraph->SetUndirectedEdge(1, 2, 5);
	XandersGraph->SetDirectedEdge(1, 3, 9);
	XandersGraph->SetDirectedEdge(2, 3, 3);
	XandersGraph->SetDirectedEdge(2, 4, 6);
	XandersGraph->SetDirectedEdge(4, 2, 2);
	XandersGraph->SetDirectedEdge(5, 3, 1);
	XandersGraph->SetUndirectedEdge(4, 5, 7);
	XandersGraph->DisplayConvertToChar();
	XandersGraph->MSTKruskal(0);
	XandersGraph->DisplayConvertToChar();
}

//tests the get min function which stores data in private member variables
void testGetMin(){

	Matrix* myIMatrix = new Matrix(15, 15, 5);
	myIMatrix->SetVal(12, 14, 1);
	myIMatrix->DisplayIntMatrixWithLabels();
	myIMatrix->GetMin();
	myIMatrix->DisplayMin();
	
}

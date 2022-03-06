//Lab 8/9 CSCI 115 Spring 2021
//Eric Smrkovsky
#include <iostream>
#include <fstream>
#include "GraphAM.h"
using namespace std;

//Prototypes
void test1();//graph class testing function 1
void DFStest1();//DFS test 1 
void DFStest2();//This is the example from page 605 in ITA 3rd edition...

//This BFSTest 1 runs the BFS alforithm twice, once showing all output
//and one that finds the shortest path between to vertices and returns the
//results in a queue
void BFSTest1();//This is the example from slide 13 in slideshow 24 from class

int main(){
	//test1();
	//DFStest1();
	//DFStest2();
	BFSTest1();
	
}


//This testing code was used prior to lab when I was making this class for
//the project (MazeGame)
void test1() {
	GraphAM* myGraph = new GraphAM(6);
	cout << "\n\n\n\n\n";
	cout << "numV: " << myGraph->GetNumberVertices() << endl;
	cout << "EdgeIndex: " << myGraph->EdgeIndex(0, 1) << endl;
	cout << "setU 0->1 = 1: ";
	myGraph->SetUndirectedEdge(0, 1);
	cout << "\nsetU: 1->5 = 50: ";
	myGraph->SetUndirectedEdge(1, 5, 50);
	cout << "\nIsUndir: " << myGraph->IsUndirected() << endl;
	cout << "\nDispUndirEdges:";
	myGraph->DisplayUndirectedEdges();
	cout << "setU 0->2 = 1: ";
	myGraph->SetDirectedEdge(0, 2);
	cout << "\nsetU: 1->4 = 40: ";
	myGraph->SetDirectedEdge(1, 4, 40);
	cout << "\nIsUndir: " << myGraph->IsUndirected() << endl;
	cout << "HasSelfLoops: " << myGraph->HasSelfLoops() << endl;
	myGraph->Display();
	cout << "RemoveDirEdge 5->1 ";
	myGraph->RemoveDirectedEdge(5, 1);
	myGraph->SetUndirectedEdge(5, 5);
	cout << "HasSelfLoops: " << myGraph->HasSelfLoops() << endl;
	myGraph->Display();
	cout << "\nWhat is out degree of node 1? " << myGraph->GetDegree(1);
	cout << "\nDispUndirEdges:";
	myGraph->DisplayUndirectedEdges();
	cout << "\nDispDirEdges:";
	myGraph->DisplayDirectedEdges();
	delete myGraph;
}

//Tests DFS algorithm with simple graph
void DFStest1(){
	GraphAM* myGraph = new GraphAM(5);
	myGraph->SetDirectedEdge(0, 1);
	myGraph->SetDirectedEdge(0, 2);
	myGraph->SetDirectedEdge(0, 3);
	myGraph->SetDirectedEdge(1, 2);
	myGraph->SetDirectedEdge(2, 4);
	cout << "\n\nGraph Adjacency Matrix...\n";
	myGraph->Display();
	cout << "\n\nThese are all of the directed edges possible...";
	myGraph->DisplayDirectedEdges();
	myGraph->DepthFirstSearch();
}

//This is the example from page 605 in ITA 3rd edition...
void DFStest2(){
	GraphAM* myGraph = new GraphAM(6);
	myGraph->SetDirectedEdge(0, 1);
	myGraph->SetDirectedEdge(0, 3);
	myGraph->SetDirectedEdge(1, 4);
	myGraph->SetDirectedEdge(4, 3);
	myGraph->SetDirectedEdge(3, 1);
	myGraph->SetDirectedEdge(2, 4);
	myGraph->SetDirectedEdge(2, 5);
	myGraph->SetDirectedEdge(5, 5);

	cout << "\n\nGraph Adjacency Matrix...\n";
	myGraph->Display();
	cout << "\n\nThese are all of the directed edges possible...";
	myGraph->DisplayDirectedEdges();
	cout << "\n\nNOTE: This is the example from page 605 in ITA 3rd edition...\n Vertices: 0==u , 1==v, 2==w, 3==x, 4==y, 5==z";
	myGraph->DepthFirstSearch();
}

//This is the example from slide 13 in slideshow 24 from...
void BFSTest1(){
	GraphAM* myGraph = new GraphAM(8);
	myGraph->SetDirectedEdge(0, 1);
	myGraph->SetDirectedEdge(7, 0);
	myGraph->SetDirectedEdge(7, 1);
	myGraph->SetDirectedEdge(6, 7);
	myGraph->SetDirectedEdge(4, 6);
	myGraph->SetDirectedEdge(6, 3);
	myGraph->SetDirectedEdge(3, 4);
	myGraph->SetDirectedEdge(3, 5);
	myGraph->SetDirectedEdge(3, 2);
	myGraph->SetDirectedEdge(5, 2);
	cout << "\n\nGraph Adjacency Matrix...\n";
	myGraph->Display();
	cout << "\n\nThese are all of the directed edges possible...";
	myGraph->DisplayDirectedEdges();
	cout << "\n\nNOTE: This is the example from slide 13 in slideshow 24 from";
	cout << " class\n Vertices: 0==a , 1==b, 2==c ...";
	myGraph->BreadthFirstSearch(3);//starts at verterx 3==d

	cout << "\n\nShortest path between 3 and 1 is shown below in a queue.\n";
	myGraph->FindShortestPathBFS(3, 1);//starts at 3 goes to 1

	//no bueno
	//myGraph->FindShortestPathBFS(1, 3);//starts at 3 goes to 1
}

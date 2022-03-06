//Lab 8 CSCI 115 Spring 2021
//Eric Smrkovsky
#include "GraphAM.h"
#include "Queue.h"
#include <iostream>
using namespace std;

//Simple display array function for double type
void GraphAM::ShowArray(double arr[], int size){
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

//Simple display array function for integer type
void GraphAM::ShowArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

//Sets the current pointer to -1 showing that it hasn't been accessed yet
void GraphAM::SetCurrentVertex(int u){
	current[u] = -1;
}

//Returns true if there is an adjacent vertex
//Also changes the value of current for u to the vertex found or sets to -1 
bool GraphAM::GetNextAdjacent(int u, int& vout){
	int v = current[u] + 1;
	vout = -1;
	bool found = false;
	while (!found && v < numVertices) {
		if (ExistEdge(u, v)) {
			found = true;
			vout = v;//changes the v value found outside the scope of this func
		}
		v++;
	}
	current[u] = vout;
	return found;
}

//Calls the FSP_BFS algorithm to find the shortest path between start and goal
void GraphAM::FindShortestPathBFS(int startV, int goalV) {
	ColorNode* color = nullptr;
	int* distance = nullptr;
	int* pi = nullptr;
	FSP_BFS(startV, goalV, color, distance, pi);
	delete[] color;
	delete[] distance;
	delete[] pi;
}

//This is an altered version of BFS algorithm found on page 595 in ITA
//It puts the shortest path between start and goal into a queue 
void GraphAM::FSP_BFS(int startV, int goalV, ColorNode*& color, 
												int*& distance,	int*& pi){
	if (!(startV >= 0 && startV < numVertices))
		cout << "\nError: Start vertex does not exist in graph...\n";
	else {
		Queue* Q = new Queue(numVertices);
		color = new ColorNode[numVertices];
		distance = new int[numVertices];
		pi = new int[numVertices];
		for (int u = 0; u < numVertices; u++) {
			color[u] = setColor(0);//sets to unvisited
			distance[u] = 0;
			pi[u] = 0;
		}
		color[startV] = setColor(1);//sets to visited
		distance[startV] = 0;
		pi[startV] = -1;
		Q->Enqueue(startV);
		while (!Q->IsEmpty()) {
			int u = Q->Dequeue();
			for (int v = 0; v < numVertices; v++) {
				if (ExistEdge(u, v) && color[v] == setColor(0)) {
					color[v] = setColor(1);
					distance[v] = distance[u] + 1;
					pi[v] = u;
					Q->Enqueue(v);
				}
			}
			color[u] = setColor(2);
		}
		delete Q;
		//cout << endl;
		int d = distance[goalV]; //get distance of goal state
		//cout << "\nD: " << distance[goalV];
		pathQ = new Queue(d+1);
		int backTracker = pi[goalV]; //log the goal vertex
		pathQ->Enqueue(goalV);		//insert goal vertex

		//Traverse graph backwards from goal state to start state logging PI's
		for (int i = 0; i <= distance[goalV]; i++) {
			pathQ->Enqueue(backTracker);
			backTracker = pi[backTracker];
		}

		//show results 
		pathQ->DisplayQueue();
	}
}

//Calls the BFS algorithm and prints the results
void GraphAM::BreadthFirstSearch(int start) {
	cout << "\n\nNow running Breadth First Search (start is V=";
	cout << start << ")...\n\n";
	ColorNode* color = nullptr;
	int* distance = nullptr;
	int* pi = nullptr;
	BFS(start, color, distance, pi);
	cout << "Start: V#  ,  End: V#  ,  Distance from start to end  ,  ";
	cout << "\nPI: End vertex found from PI vertex";
	cout << "\n---------------------SHORTEST PATHS-------------------------\n";
	for (int u = 0; u < numVertices; u++) {
		cout << "      Start: " << start << "  ,  End: " << u << "  ,";
		cout << "  Distance: " << distance[u] << "  PI: " << pi[u] << endl;
	}
	delete[] color;
	delete[] distance;
	delete[] pi;
}

//BFS algorithm follow sudocode on page 595 in ITA closely
void GraphAM::BFS(int start, ColorNode*& color, int*& distance, int*& pi){
	if (!(start >= 0 && start < numVertices))
		cout << "\nError: Start vertex does not exist in graph...\n";
	else {
		Queue* Q = new Queue(numVertices);
		color = new ColorNode[numVertices];
		distance = new int[numVertices];
		pi = new int[numVertices];
		for (int u = 0; u < numVertices; u++){
			color[u] = setColor(0);//sets to unvisited
			distance[u] = 0;
			pi[u] = 0;
		}
		color[start] = setColor(1);//sets to visited
		distance[start] = 0;
		pi[start] = -1;
		Q->Enqueue(start);
		while (!Q->IsEmpty()) {
			int u = Q->Dequeue();
			for (int v = 0; v < numVertices; v++) {
				if (ExistEdge(u, v) && color[v] == setColor(0)) {
					color[v] = setColor(1);
					distance[v] = distance[u] + 1;
					pi[v] = u;
					Q->Enqueue(v);
				}
			}
			color[u] = setColor(2);
		}
		delete Q;
	}
}

//DFS algorithm sudocode on page 604 in ITA
void GraphAM::DFS(ColorNode* &color, int* &discovery, 
							  int* &finished, int* &pi) {
	color = new ColorNode[numVertices];
	discovery = new int[numVertices];
	finished = new int[numVertices];
	pi = new int[numVertices];
	for (int u = 0; u < numVertices; u++) {
		color[u] = setColor(0);
		discovery[u] = 0;
		finished[u] = 0;
		pi[u] = 0;
	}
	for (int u = 0; u < numVertices; u++) {
		if (color[u] == setColor(0))
			DFSVisit(u, color, discovery, finished, pi);
	}
}

//Calls the DFS algorithm and prints the results
void GraphAM::DepthFirstSearch(){
	cout << "\n\nNow running Depth First Search (start is V=0)...\n\n";
	//set all to nullptr
	ColorNode* color = nullptr;
	int* discovery = nullptr;
	int* finished = nullptr;
	int* pi = nullptr;
	DFS(color, discovery, finished, pi);
	cout << "\n\nV: (Discovered, Finished)   PI: Parent of V (node was";
	cout << " discovered after visiting PI)\n------------------------------\n";
	for (int u = 0; u < numVertices; u++)//show data for each vertices
		cout << u << ": (" << discovery[u] << ", " << finished[u] 
						  << ")  PI: " << pi[u] << endl;
	//delete all allocated memory
	delete[] color;
	delete[] discovery;
	delete[] finished;
	delete[] pi;
}

//Recursively visit each node and changes it's colors accordingly
void GraphAM::DFSVisit(int u, ColorNode* color, //sudocode on page 604 in ITA 
							int* discovery, int* finished, int* pi){
	int v;
	color[u] = setColor(1); //set to visited
	cout << "\nNow visiting " << u << " ";
	discovery[u] = ++time;//time is a private variable of the class
	SetCurrentVertex(u);//sets to -1
	while (GetNextAdjacent(u, v)) {
		if (v != -1 && color[v] == setColor(0)) {
			pi[v] = u;
			cout << "Traveling on EDGE " << EdgeIndex(u, v) << " from " << u;
			cout << " to " << v << ".";
			DFSVisit(v, color, discovery, finished, pi);
		}
	}
	color[u] = setColor(2); //set to finished
	finished[u] = ++time;
}

//Sets the color of the verticies 0=unvisited, 1=visited, 2=finished
ColorNode GraphAM::setColor(int num){
	if(num == 0)
		return ColorNode::Unvisited;
	if (num == 1)
		return ColorNode::Visited;
	if (num == 2)
		return ColorNode::Finished;
}

//Constructor for graph object, creates a n * n matrix for edges and array of 
//size n for the graphs vertices // numVertices == n
GraphAM::GraphAM(int n) { 
	numVertices = n;
	int Msize = numVertices * numVertices;
	edgeWeights = new double[Msize];//create array dynamically 
	for (int i = 0; i < Msize; i++)//initialize all edges to zero
		edgeWeights[i] = 0;
	current = new int[numVertices];//create array dynamically 
	for (int i = 0; i < numVertices; i++)//initialize all elements to zero
		current[i] = 0;
	//Show for debugging purposes
	/*cout << "edgeWeights: ";
	ShowArray(edgeWeights, Msize);
	cout << "current: ";
	ShowArray(current, numVertices);*/
}

//Basic destructor
GraphAM::~GraphAM(){
	cout << "destructor";
	delete[] edgeWeights;
	delete[] current;
}

//Returns the out degree of a vertex (number of paths out of a vertex)
int GraphAM::GetDegree(int u){
	int numPaths = 0;
	for (int v = 0; v < numVertices; v++)
		if (ExistEdge(u, v))
			numPaths++;
	return numPaths;
}

//Returns the index of the edge travelled on when going from source to dest
int GraphAM::EdgeIndex(int u, int v){ //source == u, dest == v
	return u * numVertices + v;
}

//Returns true if the edge exists in the graph
bool GraphAM::ExistEdge(int u, int v){
	double weight = EdgeWeight(u, v);
	return (weight == 0 ? 0 : 1);
}

//Returns the weight (or cost) of going from u to v on the graph
double GraphAM::EdgeWeight(int u, int v){
	int index = EdgeIndex(u, v);
	return edgeWeights[index];
}

//Set the weight of an edge that can only go from u to v to the value w
void GraphAM::SetDirectedEdge(int u, int v, double w){
	edgeWeights[EdgeIndex(u, v)] = w;
}

//Set the weight of an edge that can only go from u to v to the value 1
void GraphAM::SetDirectedEdge(int u, int v){
	edgeWeights[EdgeIndex(u, v)] = 1;
}

//Set the weight of an edge that go from u to v or v to u //to the value w
void GraphAM::SetUndirectedEdge(int u, int v, double w){
	edgeWeights[EdgeIndex(u, v)] = w;
	edgeWeights[EdgeIndex(v, u)] = w;
}

//Set the weight of an edge that go from u to v or v to u //to the value 1
void GraphAM::SetUndirectedEdge(int u, int v){
	edgeWeights[EdgeIndex(u, v)] = 1;
	edgeWeights[EdgeIndex(v, u)] = 1;
}

//Set the weight of an edge that go from u to v or v to u //to the value 0
void GraphAM::RemoveDirectedEdge(int u, int v){
	edgeWeights[EdgeIndex(u, v)] = 0;
}

//Set the weight of an edge that can only go from u to v to the value 0
void GraphAM::RemoveUndirectedEdge(int u, int v){
	edgeWeights[EdgeIndex(u, v)] = 0;
}

//Returns true if any path fron u to u exists
bool GraphAM::HasSelfLoops(){
	for(int v = 0; v < numVertices; v++)
		if(edgeWeights[EdgeIndex(v, v)] != 0)
			return true;
	return false;
}

//Returns true if ALL edges that go v to u have same w of edge that go u to v
bool GraphAM::IsUndirected(){
	int v = 0;
	for (int u = 0; u < numVertices; u++)
		for (int v = u; v < numVertices; v++)
			if (edgeWeights[EdgeIndex(u, v)] != edgeWeights[EdgeIndex(v, u)])
				return false;
	return !HasSelfLoops();
}

//Displays graph in a nice way
void GraphAM::Display(){
	int k = 0;
	cout << " V->| ";
	for (int v = 0; v < numVertices; v++)
		cout << v << "   ";
	cout << "\n   U|-----------------------------------------\n";
	for (int u = 0; u < numVertices; u++) {
		cout << "   " << u << "| ";
		for (int v = 0; v < numVertices; v++, k++)
				cout << edgeWeights[k] << "   ";
		cout << endl;
	}

}

//Displays all of the undirected edges to the user
void GraphAM::DisplayDirectedEdges(){
	cout << "\nu   v\n------------\n";
	for(int u = 0; u < numVertices; u++)
		for (int v = 0; v < numVertices; v++) {
			if (ExistEdge(u, v))
				cout << u << "-->" << v << " :: " << EdgeWeight(u, v) << endl;
			if (ExistEdge(v, u))
				cout << u << "<--" << v << " :: " << EdgeWeight(u, v) << endl;
		}
}

//Displays all of the undirected edges to the user
void GraphAM::DisplayUndirectedEdges(){
	if (IsUndirected()) {
		cout << "\nu   v\n------------\n";
		for (int u = 0; u < numVertices; u++)
			for (int v = 0; v < numVertices; v++)
				if (ExistEdge(u, v)) {
					cout << u << "<-->" << v << " :: " << EdgeWeight(u, v);
					cout << endl;
				}
	}
	else {
		cout << "Note: Cannot display as undirected graph, graph has\n";
		cout << "directed edges.. call function for directed graph instead.\n";
	}
}

//Lab 8 CSCI 115 Spring 2021
//Eric Smrkovsky
#pragma once
#include "Queue.h"

enum class ColorNode {
	Visited, 
	Unvisited,
	Finished
};

class GraphAM{

public:
	GraphAM() : time(0), numVertices(0), edgeWeights(nullptr), current(nullptr), pathQ(nullptr) {};
	GraphAM(int n);
	~GraphAM();
	int GetNumberVertices() { return numVertices; }
	int GetDegree(int u);//source == u, dest == v, w == weight value 
	int EdgeIndex(int u, int v);
	bool ExistEdge(int u, int v);
	double EdgeWeight(int u, int v);
	void SetDirectedEdge(int u, int v, double w);//sets to w
	void SetDirectedEdge(int u, int v);			 //sets to 1	
	void SetUndirectedEdge(int u, int v, double w); //sets to w
	void SetUndirectedEdge(int u, int v);			//sets to 1	
	void RemoveDirectedEdge(int u, int v);			//sets to zero
	void RemoveUndirectedEdge(int u, int v);		//sets to zero
	bool HasSelfLoops();
	bool IsUndirected();
	void Display();
	void DisplayDirectedEdges();
	void DisplayUndirectedEdges();
	void ShowArray(double Arr[], int size);
	void ShowArray(int Arr[], int size);
	//above functions tested with 'test1()' function in main
	void SetCurrentVertex(int u);
	bool GetNextAdjacent(int u, int &vout);
	ColorNode setColor(int num); //0=unvisited, 1=visited, 2=finished

	void DepthFirstSearch();
	void DFSVisit(int u, ColorNode* color, int* discovery, int* finished, 
														   int* pi);
	void DFS(ColorNode*& color, int*& discovery, int*& finished, int*& pi);

	//BreadthFirstSearch	
	void BreadthFirstSearch(int start);
	void BFS(int start, ColorNode*& color, int*& distance, int*& pi);
	void FindShortestPathBFS(int startV, int GoalV);
	void FSP_BFS(int startV, int goalV, ColorNode*& color, int*& distance,
														   int*& pi);
		
private:
	int numVertices;		//number of vertices
	double* edgeWeights;	//weights of each edge		
	int* current;			//for traversals
	int time;				//keep track of timesteps id DFS algorithm
	Queue* pathQ;	//holds list of vertices to visit for shortest path 
};


//CSCi 115 --Lab 5
//
//Eric Smrkovsky
//2/22/2021
//
//This lab uses arrays to implement a double linked list with the following 
//functionalities: 
//	Insert/Remove at beginning and end of linked list
//  Insert/Remove in a sorted list with a while/for loop and with recursion
//  Display the list with a while/for loop and with recursion
//NOTE: A list is considered sorted if every element is <= to the next element

#pragma once

class doubleLinkedList{
	public:
		struct Node{	//a node data structure
			int data = 0;	//the contents of the node
			Node* prev = nullptr; //pointer to the previous node
			Node* next = nullptr; //pointer to the next node
		};

		doubleLinkedList(); //Default constructor (initializes data to 0)
		~doubleLinkedList();//Default destructor (frees mem allocated to node)
		void insertHead(int);    //Insert an element at beginning list
		void insertTail(int);    //Insert element at the end of list
		void removeHead();       //Remove an element from the beginning of list
		void removeTail();		 //Remove an element from the end of list

		void displayFor();		//Display the list using a FOR loop
		void displayWhile();	//Display the list using a WHILE loop
		void displayRec();		//Display the list using RECURSION
		void displayAll();		//Displays head, tail, value (-1 means nullptr) 
		
		void insertFor(int);  //Insert element into a sorted list w/ FOR loop 
		void insertWhile(int);//Insert element into sorted list w/ WHILE loop 
		void insertRec(int);  //Insert element into a sorted list w/ RECURSION
		void insertRecH(int input, Node*&, Node*&, Node*);


		void removeFor(int);  //Remove element from a sorted list w/ FOR loop 
		void removeWhile(int);//Remove element from sorted list w/ WHILE loop 
		void removeRec(int);  //Remove element from sorted list w/ RECURSION 
		void removeRecH(int input, Node*&, Node*&, Node*);

		bool isSorted();      //returns true if the list is considered sorted
		//List is considered sorted if every element is <= to the next element

	private:
		Node* head; //pointers to start of linked list
		Node* tail;	//pointers to end of linked list
		int size;			//number of nodes in the list	
};


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
#include "doubleLinkedList.h"
#include <iostream>
using namespace std;

//Default constructor (initializes node properties)
doubleLinkedList::doubleLinkedList(){
	
	head = nullptr;			//initialize head pointer to null
	tail = nullptr;			//initialize head pointer to null
	size = 0;				//the 'size' of the list starts at 0
}

//Default destructor (frees mem allocated to node)
doubleLinkedList::~doubleLinkedList(){
	
	Node *temp = head;		//get address of the first node
	Node *next;				//temp node to hold next node address

	for(int i = 0; i < size; i++){//loop deletes mem allocated to nodes
		next = temp->next;		//remember the next node address
		delete temp;			//free memory allocated to 'this' node	
		temp = next;			//set temp to address of the next node in list
	}
}

//Insert an element at the beginning of the list
void doubleLinkedList::insertHead(int input){
	
	Node *current = new Node;		//create a new node object
	current->data = input;	//assign the input value to the nodes data variable
	
	if(size == 0){			//if list empty head/tail ptr points to only node			
		head = current;
		tail = current;
		//current->next = nullptr; //not needed because initialized in struct 
		//current->prev = nullptr;
		size++;				//size increases
	}
	else{//head points to front node and we are adding new front node (current) 
		current->next = head;//the next ptr points to the old front node
		head->prev = current;//the old front node prev ptr points to current
		head = current;		//head now points to the new front node
		//current->prev = nullptr;//this is done when object is instantiaded
		size++;				//size increases
	}
	cout << "InsertHead function inserted " << input << "." << endl;
	cout << "List size is now " << size << "." << endl;
}

//Insert element at the end of list
void doubleLinkedList::insertTail(int input){

	Node* current = new Node;		//create a new node object
	current->data = input;	//assign the input value to the nodes data variable

	if(size == 0){			//if list empty head/tail ptr points to only node			
		head = current;
		tail = current;
		//current->next = nullptr; //not needed because initialized in struct 
		//current->prev = nullptr;
		size++;				//size increases
	} 
	else{//tail points to end node and we are adding new end node (current) 
		current->prev = tail;//the prev ptr points to the old end node
		tail->next = current;//the old end node next ptr points to current
		tail = current;		//tail now points to the new end node
		//current->next = nullptr;//this is done when object is instantiated
		size++;				//size increases
	}
	cout << "InsertTail function inserted " << input << "." << endl;
	cout << "List size is now " << size << "." << endl;
}

//Remove an element from the beginning of list
void doubleLinkedList::removeHead(){

	//if list is empty
	if (size == 0) {		//if list empty head/tail ptr points to only node			
		cout << "\nCan't remove any nodes, the list is empty.\n";
	}
	//if list has only one node 
	else if(size == 1){     
		delete head;		//delete the node that head points too 
		head = nullptr;		//no nodes left so head ptr is null again
		tail = nullptr;		//no nodes left so head ptr is null again
		size--;				//size decreases
	}
	//if list has multiple nodes
	else {
		Node* temp = new Node;	//create a new node object to access head 
		temp = head;			//assign temp to head so can remember node
		head = temp->next;		//head now points to the new front node
		head->prev = nullptr;	//make new front node prev pointer null
		delete temp;			//delete the old front node
		size--;					//size decreases
	}
	cout << "RemoveHead function removed the front node." << endl;
	cout << "List size is now " << size << "." << endl;
}

//Remove an element from the end of list
void doubleLinkedList::removeTail(){

	//if list is empty
	if (size == 0) {		//if list empty head/tail ptr points to only node			
		cout << "\nCan't remove any nodes, the list is empty.\n";
	}
	//if list has only one node 
	else if (size == 1) {
		delete head;		//delete the node that head points too 
		head = nullptr;		//no nodes left so head ptr is null again
		tail = nullptr;		//no nodes left so head ptr is null again
		size--;				//size decreases
	}
	//if list has multiple nodes
	else {
		Node* temp = new Node;	//create a new node object to access tail 
		temp = tail;			//assign temp to tail so can remember node
		tail = temp->prev;		//tail now points to the new end node
		tail->next = nullptr;	//make new end node next pointer null
		delete temp;			//delete the old end node
		size--;					//size decreases
	}
	cout << "RemoveTail function removed the last node." << endl;
	cout << "List size is now " << size << "." << endl;
}

//Display the list using a FOR loop
void doubleLinkedList::displayFor(){
	
	Node *temp = new Node;
	temp = head;
	
	//display the data from each node using a FOR loop
	//size is equivalent to the "number of elements in list"
	for(int i = 0; i < size; i++){ 
		cout << temp->data << " ";
		temp = temp->next;
	}

	if (size == 0)
		cout << "List is empty!";
}

//Display the list using a WHILE loop
void doubleLinkedList::displayWhile(){

	Node* temp = new Node;
	temp = head;
	
	//display the data from each node using a WHILE loop
	while(temp != nullptr){
		cout << temp->data << " ";
		temp = temp->next;
	}

	if (size == 0)
		cout << "List is empty!";

	//another implementaion
	/*int i = 0;
	while (i < size) {
		cout << temp->data << " ";
		temp = temp->next;
		i++;
	}*/
	delete temp;
}

//Display the list using RECURSION
void doubleLinkedList::displayRec(){

	Node* temp = new Node;
	temp = head;

	if (head != nullptr) {
		cout << head->data << " ";
		head = head->next;
		displayRec();
		head = temp;
	}
	if(size == 0)
		cout << "List is empty!";
}

//Displays head, tail, value, null displayed when next/prev is a nullptr)
void doubleLinkedList::displayAll(){

	Node* temp = new Node;
	temp = head;

	if (size != 0)
		cout << "\nSize: " << size << "\nList: ";
	//display the data from each node using a FOR loop
	//size is equivalent to the "number of elements in list"
	for (int i = 0; i < size; i++) {
		
		//displays pointers and data of nodes
		if (temp->prev == nullptr && temp->next == nullptr) {
			cout << "(null," << temp->data << ",null)\n";
		}
		else if(temp->prev == nullptr) {//displays pointers and data of nodes
			cout << "(null," << temp->data << "," << temp->next->data << ")";
		}
		else if (temp->next != nullptr) {
			cout << "(" << temp->prev->data << "," << temp->data;
			cout << "," << temp->next->data << ")";
		}
		else {
			cout << "(" << temp->prev->data << "," << temp->data << ",null)\n";
		}
		temp = temp->next;
	}

	if (size == 0)//if the size of the list is 0 this means the list is empty!
		cout << "Empty list!\n";
}

//Insert element into a sorted list w/ FOR loop 
void doubleLinkedList::insertFor(int input){
	if (!isSorted()) {	//if the list is not sorted throw error
		cout << "\nList is not sorted so insertion is not possible\n";
		return;			//property restriction fails
	}
	
	Node* temp = new Node;	//create a new temp node for traversing the list
	temp = head;			//start traversing the list at the front

	//insert element into a sorted list w / FOR loop
	for (int i = 0; i <= size; i++) { //run while we have nodes to traverse

		if (size == 0) {	//if list empty head/tail ptr points to only node			
			Node* newNode = new Node;//create a new node
			newNode->data = input;	 //assign input to data
			head = newNode;			//head now points to the new node
			tail = newNode;			//tail now points to the new node
			size++;				//size increases
			cout << "InsertFor function inserted " << input;
			cout << " into list.\nList size is now " << size << ".\n";
			return;
		}
		else if (size == 1) {		//case where only one node in list
			 if (input <= head->data) {	//if the input is <= data in only node
				 Node* newNode = new Node;//create a new node
				 newNode->data = input;	 //assign input to data
				 newNode->next = head;	 //make new node point to old head
				 head->prev = newNode;	 //make old head point to new node
				 head = newNode;	     //make new node the new head
				 size++;				 //size increases
				 cout << "InsertFor function inserted " << input;
				 cout << " into list.\nList size is now " << size << ".\n";
				 return;
			 }
			 else {//if the input is > data in only node
				 Node* newNode = new Node;//create a new node
				 newNode->data = input;	 //assign input to data
				 newNode->prev = head;	 //make new node point to head
				 tail->next = newNode;	 //make old tail point to new node
				 tail = newNode;			 //make new node the new tail
				 size++;				 //size increases
				 cout << "InsertFor function inserted " << input;
				 cout << " into list.\nList size is now " << size << ".\n";
				 return;
			 }
		}
		else if (input > temp->data) {	 //if input is > to this nodes data	
			if (temp->next != nullptr)
				temp = temp->next;		//not last node so advance to next node
			else {
				Node* newNode = new Node;//create a new node
				newNode->data = input;	 //assign input to data
				newNode->prev = temp;	 //make new node point to head
				temp->next = newNode;	 //make old tail point to new node
				tail = newNode;			 //make new node the new tail
				size++;					//size increases
				cout << "InsertFor function inserted " << input;
				cout << " into list.\nList size is now " << size << ".\n";
				return;
			}
		}
		else {
			if (temp->prev != nullptr) {	//not at the start so insert
				temp = temp->prev;			//backtrack to prev node for insert
				Node* newNode = new Node;	//create new node
				newNode->data = input;		//assign input to data
				newNode->prev = temp;		//new prev is temp
				newNode->next = temp->next;	//next is what temp next pointed to
				temp->next->prev = newNode; //next node points back correctly
				temp->next = newNode;		//make temp point to new node
				size++;						//size increases
				cout << "InsertFor function inserted " << input;
				cout << " into list.\nList size is now " << size << ".\n";
				return;
			}
			else {
				Node* newNode = new Node;//create a new node
				newNode->data = input;	 //assign input to data
				newNode->next = head;	 //make new node point to old head
				head->prev = newNode;	 //make old head point to new node
				head = newNode;	     //make new node the new head
				size++;				 //size increases
				cout << "InsertFor function inserted " << input;
				cout << " into list.\nList size is now " << size << ".\n";
				return;
			}
		}
	}
}

//Insert element into sorted list w/ WHILE loop
void doubleLinkedList::insertWhile(int input){
	if (!isSorted()) {	//if the list is not sorted throw error
		cout << "\nList is not sorted so insertion is not possible\n";
		return;			//property restriction fails
	}

	Node* temp = new Node;	//create a new temp node for traversing the list
	temp = head;			//start traversing the list at the front
	int i = 0;				//start counter at 0

	//insert element into a sorted list w / WHILE loop
	while (i++ <= size) { //run while we have nodes to traverse

		if (size == 0) {	//if list empty head/tail ptr points to only node			
			Node* newNode = new Node;//create a new node
			newNode->data = input;	 //assign input to data
			head = newNode;			//head now points to the new node
			tail = newNode;			//tail now points to the new node
			size++;				//size increases
			cout << "InsertWhile function inserted " << input;
			cout << " into list.\nList size is now " << size << ".\n";
			return;
		}
		else if (size == 1) {		//case where only one node in list
			if (input <= head->data) {	//if the input is <= data in only node
				Node* newNode = new Node;//create a new node
				newNode->data = input;	 //assign input to data
				newNode->next = head;	 //make new node point to old head
				head->prev = newNode;	 //make old head point to new node
				head = newNode;	     //make new node the new head
				size++;				 //size increases
				cout << "InsertWhile function inserted " << input;
				cout << " into list.\nList size is now " << size << ".\n";
				return;
			}
			else {//if the input is > data in only node
				Node* newNode = new Node;//create a new node
				newNode->data = input;	 //assign input to data
				newNode->prev = head;	 //make new node point to head
				tail->next = newNode;	 //make old tail point to new node
				tail = newNode;			 //make new node the new tail
				size++;				 //size increases
				cout << "InsertWhile function inserted " << input;
				cout << " into list.\nList size is now " << size << ".\n";
				return;
			}
		}
		else if (input > temp->data) {	 //if input is > to this nodes data	
			if (temp->next != nullptr)
				temp = temp->next;		//not last node so advance to next node
			else {
				Node* newNode = new Node;//create a new node
				newNode->data = input;	 //assign input to data
				newNode->prev = temp;	 //make new node point to head
				temp->next = newNode;	 //make old tail point to new node
				tail = newNode;			 //make new node the new tail
				size++;					//size increases
				cout << "InsertWhile function inserted " << input;
				cout << " into list.\nList size is now " << size << ".\n";
				return;
			}
		}
		else {
			if (temp->prev != nullptr) {	//not at the start so insert
				temp = temp->prev;			//backtrack to prev node for insert
				Node* newNode = new Node;	//create new node
				newNode->data = input;		//assign input to data
				newNode->prev = temp;		//new prev is temp
				newNode->next = temp->next;	//next is what temp next pointed to
				temp->next->prev = newNode; //next node points back correctly
				temp->next = newNode;		//make temp point to new node
				size++;						//size increases
				cout << "InsertWhile function inserted " << input;
				cout << " into list.\nList size is now " << size << ".\n";
				return;
			}
			else {
				Node* newNode = new Node;//create a new node
				newNode->data = input;	 //assign input to data
				newNode->next = head;	 //make new node point to old head
				head->prev = newNode;	 //make old head point to new node
				head = newNode;	     //make new node the new head
				size++;				 //size increases
				cout << "InsertWhile function inserted " << input;
				cout << " into list.\nList size is now " << size << ".\n";
				return;
			}
		}
	}
}

//Insert element into a sorted list w/ RECURSION
void doubleLinkedList::insertRec(int input){
	if (!isSorted()) {	//if the list is not sorted throw error
		cout << "\nList is not sorted so insertion is not possible\n";
		return;			//property restriction fails
	}
	//call helper function
	insertRecH(input, head, tail, nullptr); 
}

void doubleLinkedList::insertRecH(int input, Node*& myHead, Node*& myTail, Node* myPrev) {
	
	//case where the list is empty
	if (myHead == nullptr) {//next/prev are nullptr by default
		Node* newNode = new Node;	//create a node
		newNode->data = input;		//assign input to data var
		myHead = newNode;			//head points to node
		myTail = newNode;			//tail points to node
		newNode->prev = myPrev;		//make tail point to the prevnodes prev
		size++;						//increase size
		cout << "InsertRec function inserted " << input << " into list.\n";
		cout << "List size is now " << size << "." << endl;
	}
	//case where the input is less than data in node
	else if (myHead->data > input) {//this case insert at the front of the list
		Node* newNode = new Node;	//create a node
		newNode->data = input;		//assign input to data var
		myHead->prev = newNode;		//old head prev points to new head
		newNode->next = myHead;		//next is old head
		myHead = newNode;			//head points to node
		if (myPrev) {				//if prev is not nullptr
			newNode->prev = myPrev; //link previous node
			myPrev->next = newNode;
		}
		size++;
		cout << "InsertRec function inserted " << input << " into list.\n";
		cout << "List size is now " << size << "." << endl;
	}
	else {//recursive call shortens the list with each iteration
		insertRecH(input, myHead->next, myTail, myHead);
	}
}

//Remove element from a sorted list w/ FOR loop 
void doubleLinkedList::removeFor(int element){
	if (!isSorted()) {	//if the list is not sorted throw error
		cout << "\nList is not sorted so insertion is not possible\n";
		return;			//property restriction fails
	}
	
	if (head == nullptr) //if list is empty display error message
		cout << "\nCan't remove " << element << " from an empty list.\n";
	
	for (Node* temp = head; temp != nullptr; temp = temp->next) {

		if (element == temp->data) {	//if we find a match
			if (head == tail) {		//if there is only one node in the list
				head = nullptr;		//now head points to nothing
				tail = nullptr;		//now tail points to nothing
			}
			else if (temp->prev == nullptr) {	//if removing last node in list
				head = temp->next;				//head now is the next node
				temp->next->prev = nullptr;		//next node previous is null
			}
			else if (temp->next == nullptr) {	//if removing last node in list
				temp->prev->next = nullptr;		//previous node next is null
				tail = temp->prev;				//tail now is previous node
			}
			else {
				temp->prev->next = temp->next;//previos next point to next node
				temp->next->prev = temp->prev;//next previos point to prev node 
			}
			size--;				//decrease size
			cout << "RemoveFor removed " << element << " from the list.\n";
			cout << "List size is now " << size << "." << endl;
		}
		else if(element > temp->data && temp->next == nullptr)
			cout << "\n" << element << " does not exist in this list.\n";
	}
}

//Remove element from sorted list w/ WHILE loop 
void doubleLinkedList::removeWhile(int element){
	if (!isSorted()) {	//if the list is not sorted throw error
		cout << "\nList is not sorted so insertion is not possible\n";
		return;			//property restriction fails
	}

	if (head == nullptr) //if list is empty display error message
		cout << "\nCan't remove " << element << " from an empty list.\n";
	
	Node* temp = head;
	while(temp != nullptr) {

		//if we find a match we have 4 cases to check
		if (element == temp->data) {	//if we find a match
			//1 if there is only one node in the list
			if (head == tail) {	
				head = nullptr;		//now head points to nothing
				tail = nullptr;		//now tail points to nothing
			}
			//2 if removing first node in list
			else if (temp->prev == nullptr) {	
				head = temp->next;				//head now is the next node
				temp->next->prev = nullptr;		//next node previous is null
			}
			//3 if removing last node in list
			else if (temp->next == nullptr) {	//if removing last node in list
				temp->prev->next = nullptr;		//previous node next is null
				tail = temp->prev;				//tail now is previous node
			}
			//4 if we are removing in the middle
			else {
				temp->prev->next = temp->next;//previos next point to next node
				temp->next->prev = temp->prev;//next previos point to prev node 
			}
			size--;				//decrease size
			cout << "RemoveWhile removed " << element << " from the list.\n";
			cout << "List size is now " << size << "." << endl;
		}
		//if element is greater then data we are done, element does not exist
		//in the list. must add an extra restraint in this if else to cause
		//the cout statement to only print once
		else if (element > temp->data && temp->next == nullptr) {
			cout << "\n" << element << " does not exist in this list.\n";
		}
		temp = temp->next;
	}
}

//Remove element from sorted list w/ RECURSION 
void doubleLinkedList::removeRec(int element) {
	if (!isSorted()) {	//if the list is not sorted throw error
		cout << "\nList is not sorted so insertion is not possible\n";
		return;			//property restriction fails
	}
	//call helper function
	removeRecH(element, head, tail, nullptr);
}

void doubleLinkedList::removeRecH(int element, Node*& temp, Node*& myTail, Node* myPrev) {
//AT POINT NEED TO CHANGE RECURSION TO REMOVE RATHER THAN INSERT
	//case where the list is empty
	if (head == nullptr) {//if list is empty display error message
		cout << "\nCan't remove " << element << " from an empty list.\n";
	}
	else if (element > temp->data && temp->next != nullptr) {
		removeRecH(element, temp->next, myTail, temp);
	}
	//if we find a match we have 4 cases to check
	else if (element == temp->data) {	//if we find a match
		//1 if there is only one node in the list
		if (temp == myTail) {
			temp = nullptr;		//now head points to nothing
			myTail = nullptr;		//now tail points to nothing
		}
		//2 if removing first node in list
		else if (temp->prev == nullptr) {
			temp->next->prev = nullptr;		//next node previous is null
			temp = temp->next;				//head now is the next node
			if (temp->next == nullptr)
				myTail = temp;
		}
		//3 if removing last node in list
		else if (temp->next == nullptr) {	//if removing last node in list
			myPrev->next = nullptr;		//previous node next is null
			myTail = myPrev;				//tail now is previous node
		}
		//4 if we are removing in the middle
		else {
			temp->next->prev = temp->prev;//previos next point to next node
			temp->prev->next = temp->next;//next previos point to prev node 
		}
		size--;				//decrease size
		cout << "RemoveRec removed " << element << " from the list.\n";
		cout << "List size is now " << size << "." << endl;
	}
	else
		cout << "\n" << element << " does not exist in this list.\n";
}
//Checks that the linked list has the 'sorted' property
//List is considered sorted if every element is <= to the next element
bool doubleLinkedList::isSorted(){
	
	Node* temp = new Node;	//create a new temp node for traversing the list
	temp = head;			//start traversing the list at the front

	if (size < 2)			//if the size of the list is 0 or 1 list is sorted
		return true;
	else					//otherwise we check that the property holds
		while (temp != nullptr && temp->next != nullptr) {
			if (temp->data > temp->next->data)//if property restriction fails
				return false;				//we are done, list is NOT sorted	
			temp = temp->next;				//keep traversing the list
		}//if every element is checked and the property holds we are done
		return true;		//list IS sorted	
}
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
int main()
{
	//show title
	cout << "--------------------------------------------------------------\n";
	cout << "-----Implementation-------------------CSCi 115---Lab 5--------\n";
	cout << "---------of a-------------------------Eric Smrkovsky----------\n";
	cout << "--------Double------------------------3/2/2021----------------\n";
	cout << "------Linked List---------------------------------------------\n";
	cout << "--------------------------------------------------------------\n";
	cout << "--------------------------------------------------------------";
	cout << "\n\nThis lab uses C++ to implement a double linked list\n";
	cout << "with the following functionalities:\n";
	cout << "Insert/Remove at beginning and end of linked list.\n";
	cout << "Insert/Remove in a sorted list with a while/for loop";
	cout << " and with recursion.\n";
	cout << "Display the list with a while/for loop and with recursion.\n";
	cout << "All functions are tested with results shown below...\n\n\n";
    
	int n = 5;	//number insertions/deletions will be done in each loop below
	doubleLinkedList list;		//create new list without nodes in it
	doubleLinkedList emptylist;//for test with empty list cases

	//Testing insert head
	cout << "Testing insert head!\n";
	for(int i = 0; i < n; i++)
		list.insertHead(i * 10);

	//Testing display with a FOR loop
	cout << "\nTesting display with a FOR loop!\n";
	list.displayFor();

	//Testing insert tail
	cout << "\n\nTesting insert tail!\n";
	for(int i = 0; i < n; i++)
		list.insertTail(i * 100);

	//Testing display with a WHILE loop
	cout << "\nTesting display with a WHILE loop!\n";
	list.displayWhile();

	//Testing remove head
	cout << "\n\nTesting remove head!\n";
	for (int i = 0; i < n; i++) 
		list.removeHead();

	//Testing display with a RECURSIVE function
	cout << "\nTesting display with a RECURSIVE function!\n";
	list.displayRec();

	//Testing remove tail
	cout << "\n\nTesting remove tail!\n";
	for (int i = 0; i < n; i++)
		list.removeTail();

	list.displayAll();//Displays head, tail, value
	
	cout << "\n\nCreating a sorted list!\n";
	for (int i = 0; i < n; i++)//Create a sorted list
		list.insertTail(i * 10);

	list.displayAll();//Displays head, tail, value

	//testing isSorted function with sorted list 
	cout << "\nTesting isSorted function!\n";
	string answer;
	if (list.isSorted())//if the list is in fact sorted tell user
		answer = "YES!\n\n";
	else 
		answer = "NO!\n\n";
	cout << "\nSorted: " << answer;

	//testing isSorted function with unsorted list 
	list.insertTail(0);
	list.displayAll();//Displays head, tail, value
	if (list.isSorted())//if the list is in fact sorted tell user
		answer = "YES!\n\n";
	else
		answer = "NO!\n\n";
	cout << "\nSorted: " << answer;
	
	//testing isSorted function with unsorted list 
	list.removeTail();
	list.insertHead(999);
	list.displayAll();//Displays head, tail, value
	if (list.isSorted())//if the list is in fact sorted tell user
		answer = "YES!\n\n";
	else
		answer = "NO!\n\n";
	cout << "\nSorted: " << answer;

	//testing insertFor function
	cout << "\nTesting insertFor function!\n";
	list.displayAll();//Displays head, tail, value
	cout << "\n";

	//testing insertFor function
	list.insertFor(25);//this is test where list is not sorted
	list.removeHead();//so delete the head and list is now sorted
	
	//testing insertFor function
	cout << "\nTesting insertFor function!\n";
	list.insertFor(25);//now can insert cause list is sorted 
	list.displayAll();//Displays head, tail, value
	cout << "\n";
	list.removeHead();//remove all nodes
	list.removeHead();
	list.removeHead();
	list.removeHead();
	list.removeHead();
	list.removeHead();

	//testing insertFor function
	list.displayAll();//Displays head, tail, value
	cout << "\n";
	cout << "\nTesting insertFor function!\n";
	list.insertFor(35);//test where the list is empty
	list.displayAll();//Displays head, tail, value
	cout << "\n";

	//testing insertFor function
	cout << "\nTesting insertFor function!\n";
	list.insertFor(25);//test where list has 1 and input is <= node data
	list.displayAll();//Displays head, tail, value
	cout << "\n";
	list.removeHead();//remove what we just inserted for next test

	//testing insertFor function
	cout << "\nTesting insertFor function!\n";
	list.insertFor(45);//test where list has 1 and input is > node data
	list.displayAll();//Displays head, tail, value
	cout << "\n";

	//testing insertFor function
	cout << "\nTesting insertFor function!\n";
	list.insertFor(20);//test where list has 1 and input is > node data
	list.displayAll();//Displays head, tail, value
	cout << "\n";
	list.insertFor(10);
	list.insertFor(40);
	list.insertFor(50);
	list.displayAll();//Displays head, tail, value


	//testing insertWhile function
	list.removeHead();//remove all nodes
	list.removeHead();
	list.removeHead();
	list.removeHead();
	list.removeHead();
	list.removeHead();

	//testing insertWhile function
	list.displayAll();//Displays head, tail, value
	cout << "\n";
	cout << "\nTesting insertWhile function!\n";
	list.insertWhile(35);//test where the list is empty
	list.displayAll();//Displays head, tail, value

	//testing insertWhile function
	cout << "\nTesting insertWhile function!\n";
	list.insertWhile(25);//test where list has 1 and input is <= node data
	list.displayAll();//Displays head, tail, value
	cout << "\n";
	list.removeHead();//remove what we just inserted for next test

	//testing insertWhile function
	cout << "\nTesting insertWhile function!\n";
	list.insertWhile(45);//test where list has 1 and input is > node data
	list.displayAll();//Displays head, tail, value

	//testing insertWhile function
	cout << "\nTesting insertWhile function!\n";
	list.insertFor(20);//test where list has 1 and input is > node data
	list.displayAll();//Displays head, tail, value
	cout << "\n";
	list.insertWhile(10);
	list.insertWhile(40);
	list.insertWhile(50);
	list.displayAll();//Displays head, tail, value

	//testing insertRec function
	cout << "\n";
	list.removeHead();//remove all nodes
	list.removeHead();
	list.removeHead();
	list.removeHead();
	list.removeHead();
	list.removeHead();

	//testing insertRec function
	list.displayAll();//Displays head, tail, value
	cout << "\nTesting insertRec function!\n";
	list.insertRec(10);//test where the list is empty
	list.displayAll();//Displays head, tail, value
	list.insertRec(20);//test where the list has one
	list.displayAll();//Displays head, tail, value
	list.insertRec(30);
	list.displayAll();//Displays head, tail, value
	list.insertRec(15);
	list.displayAll();//Displays head, tail, value
	list.insertRec(25);
	list.displayAll();//Displays head, tail, value

	//testing removeFor function
	cout << "\nTesting removeFor function!\n";
	emptylist.removeFor(10);//test where the list is empty
	emptylist.displayAll();//Displays head, tail, value
	emptylist.insertRec(10);//insert 10 into an empty list
	emptylist.displayAll();//Displays head, tail, value
	emptylist.removeFor(9);//test to delete a low, nonexistant element
	emptylist.displayAll();//Displays head, tail, value
	emptylist.removeFor(11);//test to delete a high, nonexistant element
	emptylist.displayAll();//Displays head, tail, value
	emptylist.removeFor(10);//test to delete element from list of one node
	emptylist.displayAll();//Displays head, tail, value
	list.removeFor(30);
	list.displayAll();//Displays head, tail, value
	list.removeFor(15);
	list.displayAll();//Displays head, tail, value
	list.removeFor(25);
	list.displayAll();//Displays head, tail, value
	list.removeFor(10);
	list.displayAll();//Displays head, tail, value
	list.removeFor(20);
	list.displayAll();//Displays head, tail, value

	//insert 5 numbers into list for testing
	list.insertRec(10);
	list.insertRec(20);
	list.insertRec(30);
	list.insertRec(15);
	list.insertRec(25);
	list.displayAll();//Displays head, tail, value

	//testing removeWhile function
	cout << "\nTesting removeWhile function!\n";
	emptylist.removeWhile(10);//test where the list is empty
	emptylist.displayAll();//Displays head, tail, value
	emptylist.insertWhile(10);//insert 10 into an empty list
	emptylist.displayAll();//Displays head, tail, value
	emptylist.removeWhile(9);//test to delete a low, nonexistant element
	emptylist.displayAll();//Displays head, tail, value
	emptylist.removeWhile(11);//test to delete a high, nonexistant element
	emptylist.displayAll();//Displays head, tail, value
	emptylist.removeWhile(10);//test to delete element from list of one node
	emptylist.displayAll();//Displays head, tail, value
	list.removeWhile(30);
	list.displayAll();//Displays head, tail, value
	list.removeWhile(15);
	list.displayAll();//Displays head, tail, value
	list.removeWhile(25);
	list.displayAll();//Displays head, tail, value
	list.removeWhile(10);
	list.displayAll();//Displays head, tail, value
	list.removeWhile(20);
	list.displayAll();//Displays head, tail, value

	//insert 5 numbers into list for testing
	list.insertRec(10);
	list.insertRec(20);
	list.insertRec(30);
	list.insertRec(15);
	list.insertRec(25);

	//testing removeRec function
	cout << "\nTesting removeRec function!\n";
	emptylist.removeRec(10);//test where the list is empty
	emptylist.displayAll();//Displays head, tail, value
	emptylist.insertWhile(10);//insert 10 into an empty list
	emptylist.displayAll();//Displays head, tail, value
	emptylist.removeRec(9);//test to delete a low, nonexistant element
	emptylist.displayAll();//Displays head, tail, value
	emptylist.removeRec(11);//test to delete a high, nonexistant element
	emptylist.displayAll();//Displays head, tail, value
	emptylist.removeRec(10);//test to delete element from list of one node
	emptylist.displayAll();//Displays head, tail, value
	list.displayAll();//Displays head, tail, value
	list.removeRec(21);
	list.removeRec(20);
	list.removeRec(22);
	list.displayAll();//Displays head, tail, value
	list.removeRec(10);
	list.displayAll();//Displays head, tail, value
	list.removeRec(30);
	list.displayAll();//Displays head, tail, value
	list.removeRec(15);
	list.displayAll();//Displays head, tail, value
	list.removeRec(25);
	list.displayAll();//Displays head, tail, value

	cout << "\n\nThis concludes all testing.\n\n";

	cout << "\n\n\n";
}

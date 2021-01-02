//CSCi 115 --Lab 1.2
//Linked list program
//Eric Smrkovsky
//9/1/2020

//The purpose of this program is to demonstrate a linked list data structure
//This list program supports the insert, delete first node and delete last node operations
# include <iostream>
using namespace std;

//this struct is the bones of this linked list data structure.
//it holds the data value and the pointer to the next node for each node in the list
struct Node{

    int data;
    Node *nextPtr;
};

//create a node to be the head pointer to the list
struct Node *head = NULL;  //head is null because the list starts out empty

//Function definitions
void insertNodeFront(int);//creates a new node, assigns the data value, assigns head and tail pointers
void printList();//traverses each node in the linked list and displays the data values within each node
void deleteFirst();//deletes the first element of the list and calls the print function
void deleteLast();//deletes the last element of the list and calls the print function

int main() {

    //Display name, class, date and small description
    cout << "----------------------------------------------------------------------\n";
    cout << "----------------------------------------------------------------------\n";
    cout << "--------------          A Linked List Program           --------------\n";
    cout << "----------------------------------------------------------------------\n";
    cout << "-------------------------------------------------- Eric Smrkovsky ----\n";
    cout << "--------------------------------------------------    9/1/2020    ----\n";
    cout << "--------------------------------------------------    CSCi 115    ----\n";
    cout << "----------------------------------------------------------------------\n";
    cout << "----------------------------------------------------------------------\n\n\n\n";
    cout << "\n\n";

    cout << "Inserting the nodes with data values of 20, 40, 60 into the linked list...\n";
    insertNodeFront(60);                //insert 60 as the first node
    insertNodeFront(40);                //insert 40 as the first node
    insertNodeFront(20);                //insert 20 as the first node
    cout << "\nItems in the linked list: ";
    printList();                        //print the list
    cout << "\nItems in the linked list after deleting the first element: ";
    deleteFirst();                      //delete the first node in the list and print it
    cout << "\nItems in the linked list after deleting the last element: ";
    deleteLast();                       //delete the last node in the list and print it
    cout << "\n\n\n\n";
}

//creates a new node, assigns the data value, assigns head and tail pointers
void insertNodeFront(int num){

    Node *newNode = new Node;   //allocate memory for the new node
    newNode->data = num;        //assign function input to data variable
    newNode->nextPtr = head;    //Assign head to the pointer for the next node
    head = newNode;             //Reassign the head pointer to the new node
}

//traverses each node in the linked list and displays the data values within each node
void printList(){

    struct Node *temp;           //create a temp to use to traverse the list so I don't lose the original head
    temp = head;

    if(temp == NULL){            //check to make sure that list is not empty
        cout << "Empty.\n";
        return;
    }

    //loop shows every data element to the user
    while(temp != NULL){
        cout << temp->data;
        temp = temp->nextPtr;   //now temp points to the next node
        if(temp != NULL){       //adds commas after all but the last element
            cout << ", ";
        }
    }
    cout << endl;
}

//deletes the first element of the list and calls the print function
void deleteFirst(){
    struct Node *temp;          //create a temp to use to traverse the list so I don't lose the original head
    temp = head;

    if(temp != NULL){           //check to make sure that list is not empty
        head = temp->nextPtr;   //now points to the next node
    }
    else{                       //display an error if the list is empty
        cout << "Error.\nCannot delete the first node of the list because the list is empty.\n";
        return;
    }

    printList();                //lastly print out the list
};

//deletes the last element of the list and calls the print function
void deleteLast(){
    struct Node *temp;          //create a temp to use to traverse the list so I don't lose the original head
    temp = head;

    if(temp == NULL){           //check to make sure that list is not empty
        cout << "Error.\nCannot delete the first node of the list because the list is empty.\n";
        return;
    }

    while(temp->nextPtr == NULL){//check to make sure that the next node in the list is not empty
        temp = temp->nextPtr;   //now points to the next node
        }
    temp->nextPtr = NULL;       //delete the last node by making the next to last node point to null

    printList();                //lastly print out the list
};

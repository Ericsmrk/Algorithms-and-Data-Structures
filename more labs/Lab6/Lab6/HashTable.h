//Header file written by Xandar Winans instructor in CSCi 115
//CSCi 115 --Lab 6
//Eric Smrkovsky
//3/12/2021

//This lab uses arrays and linked lists to implement a Hash Table. 
//The Hash Table is of size 50 and uses an array to store data.
//If the slot in the array is already filled the algorithm    
//will uses separate chaining to deal with collisions.

//This is a simple program that accesses a text file called 'numbers.txt that
//includes 100 power-ball numbers. The program then take the sum of each 
//power-ball number and hashes it into the data structure. Each slot of the 
//array holds a (head) node of a linked list which can lead to a chain of nodes
//if there are multiple collisions that occur when the insertions happens. 

//NOTE: I left some debugging commented out for when I finish this
//planned implementation of other functionalites and more probing techniques

#ifndef HASHING_HASHTABLE_H
#define HASHING_HASHTABLE_H

//Node struct used to forms lists (chains) inside the hash table
struct Node {
    int sum;
    int count = 1;
    Node* next = nullptr;
};

//The hash table class allows quick insertion/access of elements
class HashTable {

    Node* table[50];       //array of 50 Node pointers
public:
    HashTable();           //creates an empty hash table of size 50
    void insert(int sum);  //inserts sum to the hash table, 
                           //if sum already exists increases count
                      //insert uses separate chaining to deal with collisions
    int find(int sum);//finds the count of a sum if sum doesn't exist return 0
                        //otherwise returns the value of count
    void display();     //displays the sums in the array and their count
    int hash(int key);  //uses hash function (% 50) to find index for given key
};

#endif //HASHING_HASHTABLE_H

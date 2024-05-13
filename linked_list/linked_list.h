#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.h"
#include <iostream>

using namespace std;

class Linked_List {
private:
	int length; // the number of nodes contained in the list
	Node* head; // a pointer to the first node in the list
	// anything else you need...
public:

	/**************************************************
 * Name: get_length()
 * Description: returns the length of the linked list
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: returns the length of the current linked array as an int
 ***********************************************/
	int get_length();
	// note: there is no set_length(unsigned int) (the reasoning should be intuitive)
   
   /**************************************************
 * Name: print()
 * Description: prints out a list of all the integers contained within the list
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: returns all the integers contained in the linked list with spacing
 ***********************************************/
	void print(); // output a list of all integers contained within the list

	/**************************************************
 * Name: clear()
 * Description: deletes the entire list (removes all nodes and resets the length to 0) using the pop_front function
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: frees all dynamically allocated memory and correctly gets rid of all nodes
 ***********************************************/
	void clear(); // delete the entire list (remove all nodes and reset length to 0)
   
   /**************************************************
 * Name: push_front()
 * Description: this function inserts a new values at the front of the list
 * Parameters: integer to insert
 * Pre-conditions: none
 * Post-conditions: dynamically inserts a new node with the inputted integer to the front of the list
 ***********************************************/
	void push_front(int); // insert a new value at the front of the list 
	/**************************************************
 * Name: push_back()
 * Description: this function inserts a new value at the front of the list
 * Parameters: integer to insert
 * Pre-conditions: none
 * Post-conditions: dynamically inserts a new node with the inputted integer to the front of the list
 ***********************************************/
	void push_back(int); // insert a new value at the back of the list 

	/**************************************************
 * Name: insert()
 * Description: this function inserts a new values at a specified index in the list
 * Parameters: int - value, int index
 * Pre-conditions: none
 * Post-conditions: dynamically inserts a new node with the inputted integer to the specified index in the list
 ***********************************************/
	void insert(int val, int index); // insert a new value in the list at the specified index 

/**************************************************
 * Name: pop_back()
 * Description: this function removes the node at the back of the list
 * Parameters: none
 * Pre-conditions: there exists at least one node to delete
 * Post-conditions: last node is dynamically freed of memory
 ***********************************************/
	void pop_back(); // remove the node at the back of the list

	/**************************************************
 * Name: pop_front()
 * Description: this function removes the node at the front of the list
 * Parameters: none
 * Pre-conditions: there exists at least one node to delete
 * Post-conditions: first node is dynamically freed of memory
 ***********************************************/
	void pop_front(); // remove the node at the front of the list

	/**************************************************
 * Name: remove()
 * Description: this function removes the node at given index
 * Parameters: int - index
 * Pre-conditions: there exists at least one node to delete
 * Post-conditions: specified node is dynamically freed of memory
 ***********************************************/
	void remove(int index); // remove the node at index of the list

/**************************************************
 * Name: sort_ascending()
 * Description: this function uses merge sort to sort the list from in ascending order
 * Parameters: none
 * Pre-conditions: there exists at least two nodes to sort
 * Post-conditions: list is sorted with no memory leaks/errors
 ***********************************************/
	void sort_ascending(); // sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
	// Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.

/**************************************************
 * Name: merge_ascend()
 * Description: this function takes two halves of a list and compares thier values and pushes them to a resulting list in correct order
 * Parameters: left half node, right half node
 * Pre-conditions: two halves of a total linked list exists
 * Post-conditions: halves are compared and pushed to a total list-- uses recursion without memory errors
 ***********************************************/
	Node* merge_ascend(Node* left, Node* right); // helper function to sort_ascending()

/**************************************************
 * Name: sort_descending()
 * Description: this function uses sort_ascending() then reverses the list to get a descending order
 * Parameters: none
 * Pre-conditions: there exists at least two nodes to sort
 * Post-conditions: list is sorted with no memory leaks/errors
 ***********************************************/
	void sort_descending(); // sort the nodes in descending order

	// you can add extra member variables or functions as desired

/**************************************************
 * Name: Linked_List()
 * Description: constructor for Linked_List objects, initializes head-nullptr and length-0
 * Parameters: none
 * Pre-conditions: Linked list is defined/initialized
 * Post-conditions: none
 ***********************************************/
	Linked_List();

};

#endif

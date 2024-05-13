#include "linked_list.h"

/******************************************************
** Program: linked_list.cpp
** Author: Sunil Jain
** Date: 12/10/2023
** Description: A program that creates various functionalities for a linked list containing integers.
** Input: Nothing, all in the test_linked_list.cpp
** Output: Linked list functionalities like print, get_length, adding nodes, removing, clearing, etc
******************************************************/

int Linked_List::get_length() {
	// note: there is no set_length(unsigned int) (the reasoning should be intuitive)
	// Your code goes here:

	return this->length;
}

void Linked_List::print(){
	// output a list of all integers contained within the list
	// Your code goes here:

	if (head == nullptr) return;

	Node* current = this->head;
	
	//goes through the entire list and prints the values if the list exists
	while (current != nullptr) {
		cout << current->val << " ";
		current = current->next;
	}

	cout << "\n";
	return;
}

void Linked_List::clear(){
	// delete the entire list (remove all nodes and reset length to 0)
	// Your code goes here:

	//goes through each node and removes them
	while (head != nullptr) {
		pop_front();
	}

	return;
}

void Linked_List::push_front(int v){
	// insert a new value at the front of the list 
	// Your code goes here:

	//make new node and fill it
	Node* new_node = new Node();
	new_node->val = v;

	//make this node's next the head
	new_node->next = head;

	//make this node the first in the list
	head = new_node;

	//update length
	length++;

	return;
}

void Linked_List::push_back(int v){
	// insert a new value at the back of the list 
	// Your code goes here:

	//make new node and fill it and make it the ending node
	Node* new_node = new Node();
	new_node->val = v;
	new_node->next = nullptr;

	//if the list is empty then make it the first node
	if (head == nullptr) {
		head = new_node;
	} else { //if not then get the last node in the list and make that node's next this new node
		Node* current = this->head;

		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = new_node;
	}

	//update the length
	length++;

	return;
}

void Linked_List::insert(int val, int index){
	// insert a new value in the list at the specified index 
	// Your code goes here:

	//is length within its limits?
	if (index < 0 || index > length) return;

	//if the index is the front, then push to the front
    if (index == 0) {
        push_front(val);
    } else if (index == length) { //if the index is the back, then push to the back
        push_back(val);
    } else { // if its inbetween:

		//create new node and fill it
        Node* new_node = new Node();
        new_node->val = val;

		//go through the list an indexed amount of times and find that node
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

		//make that node's next the new node
        new_node->next = current->next;
        current->next = new_node;

		//update the length
        length++;
    }

	return;
}

void Linked_List::pop_back(){
	// remove the node at the back of the list
	// Your code goes here:

	//is the list empty?
	if (head == nullptr) return;

	//if the list has one value then delete the front
	if (length == 1) {
		delete head;
		head = nullptr;
	} else { 
		// if more, then look at the last node and delete that
		Node* current = head;	
        Node* previous = nullptr;

		while (current->next != nullptr) {
            previous = current;
            current = current->next;
        }
		delete current;
        previous->next = nullptr;
	}

	//update length
	length--;

	return;
}

void Linked_List::pop_front(){
	// remove the node at the front of the list
	// Your code goes here:

	//is list empty?
	if (head == nullptr) return;

	//if it has at least one node, delete the first (head)
	Node* temp = head;
	
	head = temp->next;
	delete temp;

	//update the length
	length--;

	return;
}

void Linked_List::remove(int index){
	// remove the node at index of the list
	// Your code goes here:

	//is index in scope
	if (index < 0 || index >= length) {
		return;
	}
   
	//if the index is the front remove the front
	if (index == 0) {
        pop_front();
    } else if (index == length - 1) { //if the index is the back remove the back
        pop_back();
    } else { //if inbetween 

		//go through the list an indexed amount of time and get that node
        Node* current = head;
        for (int i = 0; i < index -1; i++) {
            current = current->next;
        }

		//delete that node from above
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;

		//update length
        length--;
    }

	return;
}

Node* Linked_List::merge_ascend(Node* left, Node* right) {
	Node* result = nullptr;

	//if the left or right halves are empty then automatically return the other
	if (left == nullptr) {
		return right;
	} else if (right == nullptr) {
		return left;
	}

	//if the value from the left is greater than the one from the right then return the left
	if (left->val <= right->val) {
		result = left;
		//recursively sort again starting with the left next node
		result->next = merge_ascend(left->next, right);
	} else { //vice versa
		result = right;
		//recursively sort again starting with the left next node
		result->next = merge_ascend(left, right->next);
	}

	//return sorted list
	return result;
}

void Linked_List::sort_ascending(){
	// sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
	// Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.
	// Your code goes here:

	if (head == nullptr || head->next == nullptr) return;

    // Split the list into two halves
    Linked_List left;
    Linked_List right;

	Node* slow = head;
    Node* fast = head->next;

	while (fast != nullptr and fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
    }

	//set the left half to the beginning with half length
	left.head = head;
    left.length = length / 2;

	//set the right halfto the half point with half length
    right.head = slow->next;
    right.length = length / 2;
    
	slow->next = nullptr;

    //Recursively sort the two halves
    left.sort_ascending();
    right.sort_ascending();

    //Merge the sorted halves and update the head of the original list
    head = merge_ascend(left.head, right.head);;

	return;
}

void Linked_List::sort_descending() {
	// sort the nodes in descending order
	// Your code goes here:

	sort_ascending();

	//reverse the sorted list
    Node* prev = nullptr;
    Node* current = head;
    Node* following = nullptr;

	//reverse the pointers and go through the list
    while (current != nullptr) {
        following = current->next;
        current->next = prev;
        prev = current;
        current = following;
    }

	head = prev;

	return;
}

Linked_List::Linked_List() {
	//initialize values
	length = 0;
	head = nullptr;
}
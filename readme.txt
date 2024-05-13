Hello, Stryder Garrett,
This is my README for Assignment 5 for CS162 at Oregon State University (Fall 2023).

Name: Sunil Jain
ONID: 934069526
Section: CS 162-010
Assignment 5, due 12/10/2023

Description:

This is my Assignment 5 homework for CS162 at Oregon State University (Fall 2023).

There are two tasks:
Implementing Fractals using recursion to count the number of ways to climb a staircase with N steps.
Implementing a signly linked list with various functionalities.

Instructions:

1. Compile the program

To compile each part, go into either the recursion or linked list
file and type make into your terminal.

2. Run the program with

Type 'a.out' into your terminal to execute each program.

3. Move through the tests 

Moving through linked list testing: press your enter key when prompted.


Limitations:

There is no makefile that can be run for both recursion and linked list parts at the same time. 
You must go into each folder and run make and their separate executeable.

Everything is hard-coded so there is no accepting input for that.

Complexity Analysis - Linked_List::sort_ascending():

This sorting algorthm uses merge sort -- splitting the lists into halves.
This takes O(N) time, where N is the number of nodes in the list.

Each time this function is run, it recursively calls it twice for each half of the current list.
From there it goes again and splits it again until there is nothing to sort.

From this, the final runtime for this function is: O(NlogN).


Complexity Analysis - Linked_List::sort_descending():

This function first sorts the list using sort_ascending() and then reverses it with a while loop.
Since the reversal does not use any runtime and is simply swapping pointers, the runtime is unchanged.

Funal runtime for this function: O(NlogN)
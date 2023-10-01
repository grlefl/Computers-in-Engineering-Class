//
// Created by Grace Flores on 12/5/22.
//

#ifndef HW8_MYLIST_H
#define HW8_MYLIST_H

// include Node class
#include "Node.h"


// Implement a doubly linked list of sorted (ascending) integers class calledMyList.
// NOTE: The methods that you write for this part of the homework are like those
// discussed in lecture. One important difference is that a pointer to  the  list
// is  not  passed as a  parameter to  the  print, insert, remove, or clear functions.
// A  second difference is that a doubly linked list does not have a start pointer.
// It has a current pointer instead.
class MyList {

// member function definitions
public:


    // define a default constructor (i.e., no inputs) that initializes the list to an
    // empty list. In other words, the current pointer should be initialized to the
    // nullptr.
    MyList();


    // getters and setters
    Node* getCurrentPtr() const;
    void setCurrentPtr(Node* const newPtr);


    // printAscending()method. This method should print the integers stored in the
    // list in ascending order. Print that the list is empty if the list is empty.
    // Pseudocode is provided in the appendix for reference.
    void printAscending();


    // printDescending()method. This method should print the integers stored in the
    // list in descending order. Print that the list is empty if the list is empty.
    void printDescending();


    // insert(int value) method. This method must insert the number into the list in
    // ascending order. This method should use the new command to create a new node
    // and check to make sure the new command successfully created a new Node.
    // Pseudocode is provided in the appendix for reference.
    int insert(int value);


    // remove(int value) method. This method removes a single node from list that
    // matches the input value if it exists. When removing the node from the list,
    // remember to delete it (i.e., to ensure no memory leaks). If list is empty, print
    // that the list was empty and there was nothing to delete. If the value was not
    // found, print a message saying that number was not found in the list.
    // Otherwise, print that the node was deleted.
    void remove(int value);


    // clear() method. This method should remove all elements from the list.
    // Print the value of each node that is deleted.
    void clear();


    // define a destructor that deletes all the nodes from the list. The destructor
    // should print the value of each node that is deleted.
    // Hint: use your clear() method.
    ~MyList();


// member variables
private:
    // one variable that points to the current node in the list
    // This variable should be Node*. This means that MyList should NOT have a
    // startPtr (or equivalent).
    Node* m_currentPtr;
};

#endif //HW8_MYLIST_H

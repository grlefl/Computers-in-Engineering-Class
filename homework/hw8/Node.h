//
// Created by Grace Flores on 12/5/22.
//

#ifndef HW8_NODE_H
#define HW8_NODE_H

class Node {

// member function definitions
public:


    // explicit constructor that initializes all the private member variables.
    // The constructor must provide default values for each member variable.
    // inputs: integer representing value at node
    explicit Node(int data = 0);


    // getters and setters for all private member variables
    int getData() const;
    void setData(int const data);

    Node* getNextPtr() const;
    void setNextPtr( Node* const newPtr);

    Node* getPreviousPtr() const;
    void setPreviousPtr( Node* const newPtr);


    // print() method that prints the integer stored in the node
    void printNodeInt();


// member variables
private:
    int m_data; // integer
    Node* m_nextPtr; // next Node pointer
    Node* m_previousPtr; // previous Node pointer

};

#endif //HW8_NODE_H

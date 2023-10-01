//
// Created by Grace Flores on 12/5/22.
//

#include "Node.h"

// must include this for print function
#include <iostream>


Node::Node(int data) {
    setData(data);
    setNextPtr(nullptr);
    setPreviousPtr(nullptr);
}


int Node::getData() const { return m_data; }
void Node::setData(int const data) { m_data = data; };

Node* Node::getNextPtr() const { return m_nextPtr; }
void Node::setNextPtr(Node* const newPtr) { m_nextPtr = newPtr; }

Node* Node::getPreviousPtr() const { return m_previousPtr; }
void Node::setPreviousPtr(Node* const newPtr) { m_previousPtr = newPtr; }


void Node::printNodeInt() {
    std::cout << getData() << std::endl;
}
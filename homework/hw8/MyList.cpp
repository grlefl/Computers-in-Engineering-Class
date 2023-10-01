//
// Created by Grace Flores on 12/5/22.
//

#include "MyList.h"

// for print statements
#include <iostream>


MyList::MyList() {
    setCurrentPtr(nullptr); // change this to setter
}


Node* MyList::getCurrentPtr() const { return m_currentPtr; }
void MyList::setCurrentPtr(Node* const newPtr) { m_currentPtr = newPtr; }


void MyList::printAscending() {

    if (getCurrentPtr() == nullptr) {

        std::cout << "List is empty." << std::endl;
        return;

/* unnecessary code
    // for single node
    } else if ((getCurrentPtr()->getPreviousPtr() == nullptr)
    and (getCurrentPtr()->getNextPtr() == nullptr)
    and (getCurrentPtr() != nullptr)) {

        getCurrentPtr()->printNodeInt();
*/

    } else {

        // Move the current pointer to the first node of the list
        while (getCurrentPtr()->getPreviousPtr() != nullptr) {
            setCurrentPtr(getCurrentPtr()->getPreviousPtr());
        }

        // Print the int value stored in each node from the first
        // node to the last node in the list
        while (getCurrentPtr()->getNextPtr() != nullptr) {
            getCurrentPtr()->printNodeInt();
            setCurrentPtr(getCurrentPtr()->getNextPtr());
        }
        getCurrentPtr()->printNodeInt();

    }
}


void MyList::printDescending() {

    if (getCurrentPtr() == nullptr) {

        std::cout << "List is empty." << std::endl;
        return;

/* unnecessary code
    // for single node
    } else if ((getCurrentPtr()->getPreviousPtr() == nullptr)
               and (getCurrentPtr()->getNextPtr() == nullptr)
               and (getCurrentPtr() != nullptr)) {

        getCurrentPtr()->printNodeInt();
*/

    } else {

        // Move the current pointer to the last node of the list
        while (getCurrentPtr()->getNextPtr() != nullptr) {
            setCurrentPtr(getCurrentPtr()->getNextPtr());
        }

        // Print the int value stored in each node from the first
        // node to the last node in the list
        while (getCurrentPtr()->getPreviousPtr() != nullptr) {
            getCurrentPtr()->printNodeInt();
            setCurrentPtr(getCurrentPtr()->getPreviousPtr());
        }
        getCurrentPtr()->printNodeInt();
    }
}


// create a node for the passed in parameter, value

// if the list is empty
    // Set currentPtr to point to the new node
// else
    // Find location to insert the new node
    // (may be to the left or the right of the currentPtr)
    // Insert the new node into the list
// endif
int MyList::insert(int value) {


    // create a node for the passed in parameter
    Node* newPtr = new Node(value);
    if (newPtr == nullptr) {
        std::cout << "Error: could not allocate new node" << std::endl;
        return -1;
    }


    // if list is empty
    if (getCurrentPtr() == nullptr) {
        setCurrentPtr(newPtr);
        return 0;

/* unnecessary code
    // insert node into one node list
    } else if ((getCurrentPtr()->getPreviousPtr() == nullptr)
    and (getCurrentPtr()->getNextPtr() == nullptr)
    and (getCurrentPtr() != nullptr)) {

        if (newPtr->getData() < getCurrentPtr()->getData()) {
            newPtr->setNextPtr(getCurrentPtr());
            getCurrentPtr()->setPreviousPtr(newPtr);
        } else if (newPtr->getData() > getCurrentPtr()->getData()) {
            newPtr->setPreviousPtr(getCurrentPtr());
            getCurrentPtr()->setNextPtr(newPtr);
        }
*/

    // insert node into multiple node list
    } else {

        // move pointer to correct spot
        if (newPtr->getData() < getCurrentPtr()->getData()) {
            while (newPtr->getData() < getCurrentPtr()->getData() and getCurrentPtr()->getPreviousPtr() != nullptr) {
                setCurrentPtr(getCurrentPtr()->getPreviousPtr());
            }
        } else if (newPtr->getData() > getCurrentPtr()->getData()) {
            while (newPtr->getData() > getCurrentPtr()->getData() and getCurrentPtr()->getNextPtr() != nullptr) {
                setCurrentPtr(getCurrentPtr()->getNextPtr());
            }
        }

        // insert node
        if (newPtr->getData() < getCurrentPtr()->getData()) {
            if (getCurrentPtr()->getPreviousPtr() == nullptr) {
                newPtr->setNextPtr(getCurrentPtr());
                getCurrentPtr()->setPreviousPtr(newPtr);
                return 0;
            } else {
                newPtr->setPreviousPtr(getCurrentPtr()->getPreviousPtr());
                newPtr->setNextPtr(getCurrentPtr());

                getCurrentPtr()->getPreviousPtr()->setNextPtr(newPtr);
                getCurrentPtr()->setPreviousPtr(newPtr);
                return 0;
            }
        } else if (newPtr->getData() > getCurrentPtr()->getData()) {
            if (getCurrentPtr()->getNextPtr() == nullptr) {
                newPtr->setPreviousPtr(getCurrentPtr());
                getCurrentPtr()->setNextPtr(newPtr);
                return 0;
            } else {
                newPtr->setNextPtr(getCurrentPtr()->getNextPtr());
                newPtr->setPreviousPtr(getCurrentPtr());

                getCurrentPtr()->getNextPtr()->setPreviousPtr(newPtr);
                getCurrentPtr()->setNextPtr(newPtr);
                return 0;
            }
        }
    }
}

// remove (int value) {
    // Code to remove a node from the list if the input value is
    // found
// }
void MyList::remove(int value) {

    // create new pointer
    Node* removePtr = nullptr;

    // if list is empty
    if (getCurrentPtr() == nullptr) {
        std::cout << "List is empty, nothing to remove." << std::endl;

    // single node and multiple node list
    } else {

        // move pointer to correct position
        if (value < getCurrentPtr()->getData()) {
            while (value != getCurrentPtr()->getData() and getCurrentPtr()->getPreviousPtr() != nullptr) {
                setCurrentPtr(getCurrentPtr()->getPreviousPtr());
            }
        } else if (value > getCurrentPtr()->getData()) {
            while (value != getCurrentPtr()->getData() and getCurrentPtr()->getNextPtr() != nullptr) {
                setCurrentPtr(getCurrentPtr()->getNextPtr());
            }
        }

        // beginning
        if (value == getCurrentPtr()->getData() and getCurrentPtr()->getPreviousPtr() == nullptr and getCurrentPtr()->getNextPtr() != nullptr) {
            removePtr = getCurrentPtr();
            getCurrentPtr()->getNextPtr()->setPreviousPtr(nullptr);
            setCurrentPtr(getCurrentPtr()->getNextPtr());
            delete removePtr;

            std::cout << "Node with value " << value << " has been deleted." << std::endl;

        // middle
        } else if (value == getCurrentPtr()->getData() and getCurrentPtr()->getPreviousPtr() != nullptr and getCurrentPtr()->getNextPtr() != nullptr) {
            removePtr = getCurrentPtr();
            getCurrentPtr()->getPreviousPtr()->setNextPtr(getCurrentPtr()->getNextPtr());
            getCurrentPtr()->getNextPtr()->setPreviousPtr(getCurrentPtr()->getPreviousPtr());
            setCurrentPtr(getCurrentPtr()->getPreviousPtr());
            delete removePtr;

            std::cout << "Node with value " << value << " has been deleted." << std::endl;

        // end
        } else if (value == getCurrentPtr()->getData() and getCurrentPtr()->getNextPtr() == nullptr and getCurrentPtr()->getPreviousPtr() != nullptr) {
            removePtr = getCurrentPtr();
            getCurrentPtr()->getPreviousPtr()->setNextPtr(nullptr);
            setCurrentPtr(getCurrentPtr()->getPreviousPtr());
            delete removePtr;

            std::cout << "Node with value " << value << " has been deleted." << std::endl;

        // single node
        } else if (value == getCurrentPtr()->getData() and getCurrentPtr()->getPreviousPtr() == nullptr and getCurrentPtr()->getNextPtr() == nullptr) {
            removePtr = getCurrentPtr();
            setCurrentPtr(nullptr);
            delete removePtr;

            std::cout << "Node with value " << value << " has been deleted." << std::endl;
        } else {

            std::cout << "Value not found in list." << std::endl;
        }
    }
}


void MyList::clear() {
    while (getCurrentPtr() != nullptr) {
        remove(getCurrentPtr()->getData());
    }
}

MyList::~MyList() {
    clear();
}

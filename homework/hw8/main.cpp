// Name: Grace Flores
// Date: December 8, 2022
// Program Description: Implement a doubly linked list class of integers. You will write two new
//                      classes, Node and MyList. These classes must be implemented in their own
//                      files, i.e., Node.cpp, Node.h, MyList.cpp and MyList.h.


#include <iostream>
// include classes
#include "MyList.h"

int main() {


    // TO COMPLETE
    // Write a main program that tests each method of the Node and MyList classes.
    // You should implement a class method, test it,and then check your code into SVN.
    // Repeat until finished with homework.
    std::cout << "\n\n\n" << std::endl;






    // Node constructor, getter, and setter tests
    std::cout << "Node constructor, getter, and setter tests" << std::endl;
    std::cout << std::endl;

    // no input expected output
    std::cout << "no input expected output:\n0\n0x0\n0x0" << std::endl;
    std::cout << std::endl;

    // setup
    Node* nodeTest1 = new Node;

    // no input actual output
    std::cout << "no input actual output:" << std::endl;
    std::cout << nodeTest1->getData() << std::endl;
    std::cout << nodeTest1->getPreviousPtr() << std::endl;
    std::cout << nodeTest1->getNextPtr() << std::endl;
    std::cout << std::endl;

    // input integer expected output
    std::cout << "input integer expected output:\n5\n0x0\n0x0" << std::endl;
    std::cout << std::endl;

    // setup
    Node* nodeTest2 = new Node(5);

    // input integer actual output
    std::cout << "input integer actual output:" << std::endl;
    std::cout << nodeTest2->getData() << std::endl;
    std::cout << nodeTest2->getPreviousPtr() << std::endl;
    std::cout << nodeTest2->getNextPtr() << std::endl;
    std::cout << std::endl;

    // end of test, free pointers
    std::cout << "end of test, free pointers" << std::endl;
    delete nodeTest1;
    delete nodeTest2;
    std::cout << "\n\n\n" << std::endl;








    // Node::printNodeInt() tests
    std::cout << "Node::printNodeInt() tests" << std::endl;
    std::cout << std::endl;

    // setup
    Node* printNodeIntTest1 = new Node;
    Node* printNodeIntTest2 = new Node(7);

    // expected output
    std::cout << "expected Output:\n0\n7" << std::endl;
    std::cout << std::endl;

    // actual output
    std::cout << "actual Output:" << std::endl;
    printNodeIntTest1->printNodeInt();
    printNodeIntTest2->printNodeInt();
    std::cout << std::endl;

    // end of test, free pointers
    std::cout << "end of test, free pointers" << std::endl;
    delete printNodeIntTest1;
    delete printNodeIntTest2;
    std::cout << "\n\n\n" << std::endl;







    // MyList constructor, getter, and setter test
    std::cout << "MyList constructor, getter, and setter test" << std::endl;
    std::cout << std::endl;

    std::cout << "expected output:\n0x0" << std::endl;
    std::cout << std::endl;

    // setup
    MyList* mylistTest = new MyList;

    std::cout << "actual output:" << std::endl;
    std::cout << mylistTest->getCurrentPtr() << std::endl;
    std::cout << std::endl;

    // end of test, free pointers
    std::cout << "end of test, free pointers" << std::endl;
    delete mylistTest;
    std::cout << "\n\n\n" << std::endl;








    // MyList::printAscending() and MyList::printDescending() tests
    std::cout << "MyList::printAscending() and MyList::printDescending() tests" << std::endl;
    std::cout << std::endl;

    // setup
    MyList* printTests = new MyList;

    // empty list expected output, print ascending
    std::cout << "empty list expected output, print ascending:\nList is empty." << std::endl;
    std::cout << std::endl;

    // empty list actual output, print ascending
    std::cout << "empty list actual output, print ascending:" << std::endl;
    printTests->printAscending();
    std::cout << std::endl;

    // empty list expected output, print descending
    std::cout << "empty list expected output, print descending:\nList is empty." << std::endl;
    std::cout << std::endl;

    // empty list actual output, print descending
    std::cout << "empty list actual output, print descending:" << std::endl;
    printTests->printDescending();
    std::cout << std::endl;

    // more setup
    Node* one = new Node(1);
    printTests->setCurrentPtr(one);

    // single node expected output, print ascending
    std::cout << "single node expected output, print ascending:\n1" << std::endl;
    std::cout << std::endl;

    // single node actual output, print ascending
    std::cout << "single node actual output, print ascending:" << std::endl;
    printTests->printAscending();
    std::cout << std::endl;

    // single node expected output, print descending
    std::cout << "single node expected output, print descending:\n1" << std::endl;
    std::cout << std::endl;

    // single node actual output, print descending
    std::cout << "single node actual output, print descending:" << std::endl;
    printTests->printDescending();
    std::cout << std::endl;

    // more setup
    Node* two = new Node(2);
    Node* four = new Node(4);
    Node* thirteen = new Node(13);
    one->setNextPtr(two);
    two->setPreviousPtr(one);
    two->setNextPtr(four);
    four->setPreviousPtr(two);
    four->setNextPtr(thirteen);
    thirteen->setPreviousPtr(four);

    // multiple nodes expected output, print ascending
    std::cout << "multiple nodes expected output, print ascending:\n1\n2\n4\n13" << std::endl;
    std::cout << std::endl;

    // multiple nodes actual output, print ascending
    std::cout << "multiple nodes actual output, print ascending:" << std::endl;
    printTests->printAscending();
    std::cout << std::endl;

    // multiple nodes expected output, print descending
    std::cout << "multiple nodes expected output, print descending:\n13\n4\n2\n1" << std::endl;
    std::cout << std::endl;

    // multiple nodes actual output, print descending
    std::cout << "multiple nodes actual output, print descending:" << std::endl;
    printTests->printDescending();
    std::cout << std::endl;

    // end of test, free pointers
    std::cout << "end of test, free pointers" << std::endl;
    delete printTests;
    std::cout << "\n\n\n" << std::endl;







    // MyList::insert(int value) tests
    std::cout << "MyList::insert(int value) tests, printed ascending and descending" << std::endl;
    std::cout << std::endl;

    // setup
    MyList* insertTest1 = new MyList;

    // insert one node into empty list expected output
    std::cout << "insert one node into empty list expected output:\n5\n5" << std::endl;
    std::cout << std::endl;

    // insert one node into empty list actual output
    std::cout << "insert one node into empty list actual output:" << std::endl;
    insertTest1->insert(5);
    insertTest1->printAscending();
    insertTest1->printDescending();
    std::cout << std::endl;

    // insert lesser value into one node list expected output
    std::cout << "insert lesser value into one node list expected output:\n3\n5\n5\n3" << std::endl;
    std::cout << std::endl;

    // insert lesser value into one node list actual output
    std::cout << "insert lesser value into one node list actual output:" << std::endl;
    insertTest1->insert(3);
    insertTest1->printAscending();
    insertTest1->printDescending();
    std::cout << std::endl;

    // insert higher value into one node list expected output
    std::cout << "insert higher value into one node list expected output:\n5\n6\n6\n5" << std::endl;
    std::cout << std::endl;

    // setup
    MyList* insertTest2 = new MyList;
    insertTest2->insert(5);

    // insert higher value into one node list actual output
    std::cout << "insert higher value into one node list actual output:" << std::endl;
    insertTest2->insert(6);
    insertTest2->printAscending();
    insertTest2->printDescending();
    std::cout << std::endl;

    // insert multiple values into multiple node list expected output
    std::cout << "insert multiple values into multiple node list expected output:\n1\n2\n3\n4\n5\n6\n7\n13\n13\n7\n6\n5\n4\n3\n2\n1" << std::endl;
    std:: cout << std::endl;

    // setup
    insertTest2->insert(2);
    insertTest2->insert(3);
    insertTest2->insert(7);
    insertTest2->insert(13);
    insertTest2->insert(4);
    insertTest2->insert(1);

    // insert multiple values into multiple node list actual output
    std::cout << "insert multiple values into multiple node list actual output:" << std::endl;
    insertTest2->printAscending();
    insertTest2->printDescending();
    std:: cout << std::endl;

    // end of test, free pointers
    std::cout << "end of test, free pointers" << std::endl;
    delete insertTest1;
    delete insertTest2;
    std:: cout << "\n\n\n" << std::endl;







    // MyList::remove(int value) tests
    std::cout << "MyList::remove(int value) tests, printed ascending and descending" << std::endl;
    std::cout << std::endl;

    // empty list expected output
    std::cout << "empty list expected output:\nList is empty, nothing to remove." << std::endl;
    std::cout << std::endl;

    // setup
    MyList* removeTest1 = new MyList;

    // empty list actual output
    std::cout << "empty list actual output:" << std::endl;
    removeTest1->remove(0);
    std::cout << std::endl;

    // remove node from list with single node expected output
    std::cout << "remove node from list with single node expected output:\nNode with value 5 has been deleted.\nList is"
                 " empty.\nList is empty." << std::endl;
    std::cout << std::endl;

    // setup
    removeTest1->insert(5);

    // remove node from list with single node actual output
    std::cout << "remove node from list with single node actual output:" << std::endl;
    removeTest1->remove(5);
    removeTest1->printAscending();
    removeTest1->printDescending();
    std::cout << std::endl;

    // remove invalid node from list with single node expected output
    std::cout << "remove invalid node from list with single node expected output:\nValue not found in list." << std::endl;
    std::cout << std::endl;

    // setup
    removeTest1->insert(5);

    // remove invalid node from list with single node actual output
    std::cout << "remove invalid node from list with single node actual output:" << std::endl;
    removeTest1->remove(6);
    std::cout << std::endl;

    // remove middle node from list expected output
    std::cout << "remove middle node from list expected output:\nNode with value 7 has been deleted.\n1\n2\n3\n4\n5\n6\n13"
                 "\n13\n6\n5\n4\n3\n2\n1" << std::endl;
    std::cout << std::endl;

    // setup
    removeTest1->insert(2);
    removeTest1->insert(13);
    removeTest1->insert(7);
    removeTest1->insert(3);
    removeTest1->insert(6);
    removeTest1->insert(1);
    removeTest1->insert(4);

    // remove middle node from list actual output
    std::cout << "remove middle node from list actual output:" << std::endl;
    removeTest1->remove(7);
    removeTest1->printAscending();
    removeTest1->printDescending();
    std::cout << std::endl;

    // remove beginning node from list expected output
    std::cout << "remove beginning node from list expected output:\nNode with value 1 has been deleted.\n2\n3\n4\n5\n6\n13"
                 "\n13\n6\n5\n4\n3\n2" << std::endl;
    std::cout << std::endl;

    // remove beginning node from list actual output
    std::cout << "remove beginning node from list actual output:" << std::endl;
    removeTest1->remove(1);
    removeTest1->printAscending();
    removeTest1->printDescending();
    std::cout << std::endl;

    // remove end node from list expected output
    std::cout << "remove end node from list expected output:\nNode with value 13 has been deleted.\n2\n3\n4\n5\n6"
                 "\n6\n5\n4\n3\n2" << std::endl;
    std::cout << std::endl;

    // remove end node from list actual output
    std::cout << "remove end node from list actual output:" << std::endl;
    removeTest1->remove(13);
    removeTest1->printAscending();
    removeTest1->printDescending();
    std::cout << std::endl;

    // remove invalid node from multiple node list expected output
    std::cout << "remove invalid node from multiple node list expected output:\nValue not found in list." << std::endl;
    std::cout << std::endl;

    // remove invalid node from multiple node list actual output
    std::cout << "remove invalid node from multiple node list actual output:" << std::endl;
    removeTest1->remove(17);
    std::cout << std::endl;

    // end of test, free pointers
    std::cout << "end of test, free pointers" << std::endl;
    delete removeTest1;
    std::cout << "\n\n\n" << std::endl;







    // MyList::clear() tests
    std::cout << "MyList::clear() tests" << std::endl;
    std::cout << std::endl;

    // clear multiple node list expected output
    std::cout << "clear multiple node list expected output:\nNOTE: A statement for each deleted node should be printed."
                 "\nIn this case, nodes with values 2-6 should be deleted, but the order of their deletion does not matter."
                 "\nDeletion statements will follow with 'List is empty.'" << std::endl;
    std::cout << std::endl;

    // setup
    MyList* clearTest1 = new MyList;
    clearTest1->insert(5);
    clearTest1->insert(2);
    clearTest1->insert(4);
    clearTest1->insert(3);
    clearTest1->insert(6);

    // clear multiple node list actual output
    std::cout << "clear multiple node list actual output:" << std::endl;
    clearTest1->clear();
    clearTest1->printAscending();
    std::cout << std::endl;

    // duplicate test, clear multiple node list expected output
    std::cout << "duplicate test, clear multiple node list expected output:\ndeletion statements for values 7-15"
                 "\n'List is empty'" << std::endl;
    std::cout << std::endl;

    // setup
    MyList* clearTest2 = new MyList;
    clearTest2->insert(7);
    clearTest2->insert(8);
    clearTest2->insert(9);
    clearTest2->insert(10);
    clearTest2->insert(11);
    clearTest2->insert(12);
    clearTest2->insert(13);
    clearTest2->insert(14);
    clearTest2->insert(15);

    // duplicate test, clear multiple node list actual output
    std::cout << "duplicate test, clear multiple node list expected output:" << std::endl;
    clearTest2->clear();
    clearTest2->printAscending();
    std::cout << std::endl;

    // clear single node list expected output
    std::cout << "clear single node list expected output:\nNode with value 5 has been deleted."
                 "\nList is empty." << std::endl;
    std::cout << std::endl;

    // setup
    MyList* clearTest3 = new MyList;
    clearTest3->insert(5);

    // clear single node list actual output
    std::cout << "clear single node list actual output:" << std::endl;
    clearTest3->clear();
    clearTest3->printAscending();
    std::cout << std::endl;

    // clear empty list expected output
    std::cout << "clear empty list expected output:\nList is empty." << std::endl;
    std::cout << std::endl;

    // clear empty list actual output
    std::cout << "clear empty list actual output:" << std::endl;
    clearTest3->clear();
    clearTest3->printAscending();
    std::cout << std::endl;

    // end of test, free pointers
    std::cout << "end of test, free pointers" << std::endl;
    delete clearTest1;
    delete clearTest2;
    delete clearTest3;
    std::cout << "\n\n\n" << std::endl;







    // MyList::~MyList() destructor tests
    std::cout << "MyList::~MyList() destructor tests" << std::endl;
    std::cout << std::endl;

    // destruct empty list expected output
    std::cout << "destruct empty list expected output:\nno output" << std::endl;
    std::cout << std::endl;

    // setup
    MyList* destructorTest1 = new MyList;

    // destruct empty list actual output
    std::cout << "destruct empty list actual output:" << std::endl;
    delete destructorTest1;
    std::cout << std::endl;

    // destruct single node list expected output
    std::cout << "destruct single node list expected output:\nNode with value 5 had been deleted." << std::endl;
    std::cout << std::endl;

    // setup
    MyList* destructorTest2 = new MyList;
    destructorTest2->insert(5);

    // destruct single node list actual output
    std::cout << "destruct single node list actual output:" << std::endl;
    delete destructorTest2;
    std::cout << std::endl;

    // destruct multiple node list expected output
    std::cout << "destruct multiple node list expected output:"
                 "\ndeletion statements for values 1-6" << std::endl;
    std::cout << std::endl;

    // setup
    MyList* destructorTest3 = new MyList;
    destructorTest3->insert(1);
    destructorTest3->insert(4);
    destructorTest3->insert(5);
    destructorTest3->insert(6);
    destructorTest3->insert(3);
    destructorTest3->insert(2);

    // destruct multiple node list actual output
    std::cout << "destruct multiple node list actual output:" << std::endl;
    delete destructorTest3;
    std::cout << "\n\n\n" << std::endl;







    return 0;
}

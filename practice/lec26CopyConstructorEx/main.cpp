#include <iostream>

using namespace std;

class MyClass {
public:
    MyClass(int value = 0); // constructor
    MyClass(const MyClass & obj);

// TODO: Part III. Add the copy assignment operator code

    ~MyClass(); // destructor
    void print() const;
    void setValue(int value);
    int getValue() const;
private:
    int * m_value;
};

// Constructor
MyClass::MyClass(int value){
    m_value = new int;  // Memory Allocated
    *m_value = value;
}

// Destructor
MyClass::~MyClass(){
    delete m_value; // Memory De-allocated
}

void MyClass::print() const{
    cout << "value = " << *m_value << endl;
}

void MyClass::setValue(int value) {
    *m_value = value;
}

int MyClass::getValue() const{
    return *m_value;
}

// Copy constructor
MyClass::MyClass(const MyClass & obj){
    m_value = new int;  // Memory Allocated
    *m_value = obj.getValue();
}

//
// Programmer: Gary E Christensen
// Date: 3/24/2020
// Description: This program provides an example that requires a copy constructor.
//      The original program runs with an error message caused by trying to delete the same
//      dynamically allocated memory twice. Uncommenting the copy constructor fixes the error.
//
//      The reason for the error is that the default constructor assigns the pointer from
//      the object being copied to the new object being created. Thus, both objects share
//      the same pointer address of a single dynamically allocated integer.
//      At the end of the program, the first object deletes the dynamically allocated integer.
//      The error occurs when the second object is destroyed. This is because the
//      pointer of the second object points the the memory were the dynamically allocated integer
//      was already deleted when the first object was destroyed.
//
//      Uncommenting the copy constructor fixes this problem because the second object does a
//      deep copy of the first object. This means that the copy constructor creates a new integer
//      for the second object and assigns the newly created integer is assigned the value from the
//      first object. When the program ends, the default destructor for each object is called.
//      This time, each object has a pointer that points to different memory locations that were
//      allocated dynamically. Thus, each destructor deletes the dynamically allocated integer
//      associated with the object being destroyed so there is no error.
//

int main(){

    MyClass object1(1);
    MyClass object2(object1);

    object1.print();
    object2.print();
    object1.setValue(2);
    object1.print();
    object2.print();

    // TODO: Part II. Uncomment the following code. Notice the bug. Go to Part III.
//    cout << "\n\n" << "Copy assignment operation." << endl;
//    object1.setValue(1);
//    object2 = object1;
//    object1.print();
//    object2.print();
//    object1.setValue(3);
//    object1.print();
//    object2.print();  // Incorrectly prints 3 until copy assignment operation is implemented.

    return 0;  // Error occurs at the end of the program when the copy constructor is commented.
}

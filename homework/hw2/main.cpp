/***************************************************************************************************
 * Name: Grace Flores
 * Date: September 16th, 2022
 * File Name: hw2
 * Description: This program used simple C++ classes to test class methods. A Box class
 *                      can be created to find the volume and surface area of a box.
****************************************************************************************************/

#include <iostream>
using namespace std;

// Principle of Least Privilege:
// using the least set of privileges necessary to complete the job

// create a Box class with public and private areas
class Box {

// private area
private:
    float m_width; // value cannot be negative
    float m_depth; // value cannot be negative
    float m_height; // value cannot be negative

// public area
public:

/***************************************************************************************************
 * Constructor: automatically initializes the values of the Box class;
 *              all values are initialized to 1 unless otherwise specified;
 *              negative values will be initialized to 1
 * Inputs:
 *      width - float - width of box
 *      depth - float - depth of box
 *      height - float - height of box
 * Outputs: no outputs
****************************************************************************************************/
    explicit Box(float width = 1, float depth = 1, float height = 1) {
        setWidth(width);
        setDepth(depth);
        setHeight(height);
    }

    // SETTERS
    // setWidth prevents width from being negative
    // negative values are set to a width of 1
    void setWidth(const float width) {
        if (width<0) { m_width = 1.0; }
        else { m_width = width; }
    }
    // setDepth prevents depth from being negative
    // negative values are set to a depth of 1
    void setDepth(const float depth) {
        if (depth<0) { m_depth = 1.0; }
        else { m_depth = depth; }
    }
    // setHeight prevents height from being negative
    // negative values are set to a height of 1
    void setHeight(const float height) {
        if (height<0) { m_height = 1.0; }
        else { m_height = height; }
    }

    // GETTERS
    // implement getWidth, getDepth, getHeight methods for Box class
    // getWidth method
    float getWidth() const { return m_width; }
    // getDepth method
    float getDepth() const { return m_depth; }
    // getHeight method
    float getHeight() const { return m_height; }

/***************************************************************************************************
 * Method: getVolume calculates the volume of object from Box class
 * Inputs: no inputs
 * Outputs: volume of box - float
****************************************************************************************************/
    float getVolume() const { return (m_width*m_depth*m_height); }

/***************************************************************************************************
 * Method: getSurfaceArea calculates the surface area of object from Box class
 * Inputs: no inputs
 * Outputs: surface area of box - float
****************************************************************************************************/
    float getSurfaceArea() const { return ((m_width*m_depth)+(m_width*m_height)+(m_depth*m_height)); }

};

int main() {

    // constructor tests
    Box box1(3,5,4);
    Box box2;
    Box box3(2,6,3);
    Box box4(5,5,4);

    // setWidth tests
    box1.setWidth(2); // now box1 values should be (width: 2, depth:5, height: 4)
    box2.setWidth(9); // now box2 values should be (width: 9, depth:1, height: 1)
    box3.setWidth(3); // now box3 values should be (width: 3, depth:6, height: 3)
    box4.setWidth(0); // now box4 values should be (width: 0, depth:5, height: 4)

    // setDepth tests
    box1.setDepth(0); // now box1 values should be (width: 2, depth:0, height: 4)
    box2.setDepth(7); // now box2 values should be (width: 9, depth:7, height: 1)
    box3.setDepth(-23); // now box3 values should be (width: 3, depth:1, height: 3)
    box4.setDepth(4); // now box4 values should be (width: 0, depth:4, height: 4)

    // setHeight tests
    box1.setHeight(6); // now box1 values should be (width: 2, depth:0, height: 6)
    box2.setHeight(3); // now box2 values should be (width: 9, depth:7, height: 3)
    box3.setHeight(-2); // now box3 values should be (width: 3, depth:1, height: 1)
    box4.setHeight(0); // now box4 values should be (width: 0, depth:4, height: 0)

    // getWidth tests
    cout << endl << "Expected box1.getWidth() to return 2. Actual value is " << box1.getWidth() << endl;
    cout << "Expected box2.getWidth() to return 9. Actual value is " << box2.getWidth() << endl;
    cout << "Expected box3.getWidth() to return 3. Actual value is " << box3.getWidth() << endl;
    cout << "Expected box4.getWidth() to return 0. Actual value is " << box4.getWidth() << endl;

    // getDepth tests
    cout << endl << "Expected box1.getDepth() to return 0. Actual value is " << box1.getDepth() << endl;
    cout << "Expected box2.getDepth() to return 7. Actual value is " << box2.getDepth() << endl;
    cout << "Expected box3.getDepth() to return 1. Actual value is " << box3.getDepth() << endl;
    cout << "Expected box4.getDepth() to return 4. Actual value is " << box4.getDepth() << endl;

    // getHeight tests
    cout << endl << "Expected box1.getHeight() to return 6. Actual value is " << box1.getHeight() << endl;
    cout << "Expected box2.getHeight() to return 3. Actual value is " << box2.getHeight() << endl;
    cout << "Expected box3.getHeight() to return 1. Actual value is " << box3.getHeight() << endl;
    cout << "Expected box4.getHeight() to return 0. Actual value is " << box4.getHeight() << endl;

    // getVolume tests
    cout << endl << "Expected box1.getVolume() to return 0. Actual value is " << box1.getVolume() << endl;
    cout << "Expected box2.getVolume() to return 189. Actual value is " << box2.getVolume() << endl;
    cout << "Expected box3.getVolume() to return 3. Actual value is " << box3.getVolume() << endl;
    cout << "Expected box4.getVolume() to return 0. Actual value is " << box4.getVolume() << endl;

    // getSurfaceArea tests
    cout << endl << "Expected box1.getVolume() to return 12. Actual value is " << box1.getSurfaceArea() << endl;
    cout << "Expected box2.getVolume() to return 111. Actual value is " << box2.getSurfaceArea() << endl;
    cout << "Expected box3.getVolume() to return 7. Actual value is " << box3.getSurfaceArea() << endl;
    cout << "Expected box4.getVolume() to return 0. Actual value is " << box4.getSurfaceArea() << endl;

    return 0;
}

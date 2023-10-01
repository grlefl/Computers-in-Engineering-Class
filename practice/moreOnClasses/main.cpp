#include <iostream>

using namespace std;

class MyClass {
public:
    // MyClass(): m_x{0}, m_y{0} {} // member initialization; no instructions in the constructor
    explicit MyClass(int x=0, int y=0): m_x{x}, m_y{y} { } // default inputs in parenthesis

    /*
    MyClass() {
        m_x = 0;
        m_y = 0;
    }
    */
    void setX(const int x) { m_x = x; }
    int getX() const { return m_x; }

    void setY(const int y) { m_y = y; }
    int getY() const { return m_y; }

    // print function
    void print() const {
        cout << m_x << " " << m_y << endl;
    }
private:
    int m_x;
    int m_y;
};

int main() {
    const MyClass myClassObject(1,1);
    // objects of 0,1, or 2 inputs can be created
    myClassObject.print();

    cout << myClassObject.getX() << " " << myClassObject.getY() << endl;
    return 0;
}

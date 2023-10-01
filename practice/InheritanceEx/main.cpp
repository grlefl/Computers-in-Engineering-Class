#include <iostream>

using namespace std;

class MyBaseClass {
public:
    void setProtectedInt(int userInt) { m_protectedInt = userInt; }
    void setPrivateInt(int userInt) { m_privateInt = userInt; }

    int getProtectedInt() const { return m_protectedInt; }
    int getPrivateInt() const { return m_privateInt; }

    void print() const;
protected:
    int m_protectedInt;
private:
    int m_privateInt;
};

class MyDerivedClass: public MyBaseClass {
public:
    int getAdditionalPrivateInt() const {
        return m_additionalPrivateInt;
    }

    void setAdditionalPrivateInt(const int mAdditionalPrivateInt) {
        m_additionalPrivateInt = mAdditionalPrivateInt;
    }

    void print() const; // overriding
                        // function has same name in base and derived class
                        // derived class function replaces the base class

private:
    int m_additionalPrivateInt;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

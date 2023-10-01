#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> myNumbers; // create an empty vector of integers

    cout << "initial size of int vector = " << myNumbers.size() << endl; // prints: initial size of int vector = 0

    for (int n=0; n < 10; n++) {
        myNumbers.push_back(n); // add numbers to end of vector (vector automatically resized)
    }

    // print vector: option 1
    for (size_t i=0; i < myNumbers.size(); i++) {
        cout << myNumbers[i] << " ";    // prints: 0 1 2 3 4 5 6 7 8 9
    }
    cout << endl;

    // print vector: option 2
    for (size_t i=0; i < myNumbers.size(); i++) {
        cout << myNumbers.at(i) << " ";    // prints: 0 1 2 3 4 5 6 7 8 9
    }
    cout << endl;

    // modify elements of vector and print result
    for (size_t i=0; i < myNumbers.size(); i+=2) {
        myNumbers[i] = 0;     // sets even numbered elements to zero
    }

    for (auto item : myNumbers) {
        cout << item << " ";    // prints: 0 1 0 3 0 5 0 7 0 9
    }
    cout << endl;
    // remove last element and  prints: size of integer vector after calling pop_back = 9
    myNumbers.pop_back();
    cout << "size of integer vector after calling pop_back = " << myNumbers.size() << endl;

    for (size_t i=0; i < myNumbers.size(); i++) {
        cout << myNumbers[i] << " ";          // prints: 0 1 0 3 0 5 0 7 0
    }
    cout << endl;


    // create vector of strings, with initial size of 3
    vector< string > myStrings(3);
    cout << "initial size of string vector = " << myStrings.size() << endl;

    myStrings.at(0) = "zero";
    myStrings[1] = "one";
    myStrings.at(2) = "two";
    myStrings.push_back("three");

    for (size_t i = 0; i < myStrings.size(); i++)
    {
        cout  << i << ": " << myStrings[i] << " "; // prints: 0: zero 1: one 2: two 3: three
    }
    cout << endl;


//    /* Manual controller for traffic light. From Section 4.12 of CIE zyBooks textbook */
//    enum LightState {
//        LS_RED, LS_GREEN, LS_YELLOW, LS_DONE
//    };
//
//    LightState lightVal;
//    char userCmd;
//
//    lightVal = LS_RED;
//    userCmd = '-';
//
//    cout << "User commands: n (next), r (red), q (quit)." << endl << endl;
//
//    lightVal = LS_RED;
//    while (lightVal != LS_DONE) {
//
//        if (lightVal == LS_GREEN) {
//            cout << "Green light  ";
//            cin >> userCmd;
//            if (userCmd == 'n') { // Next
//                lightVal = LS_YELLOW;
//            }
//        } else if (lightVal == LS_YELLOW) {
//            cout << "Yellow light  ";
//            cin >> userCmd;
//            if (userCmd == 'n') { // Next
//                lightVal = LS_RED;
//            }
//        } else if (lightVal == LS_RED) {
//            cout << "Red light  ";
//            cin >> userCmd;
//            if (userCmd == 'n') { // Next
//                lightVal = LS_GREEN;
//            }
//        }
//
//        if (userCmd == 'r') { // Force immediate red
//            lightVal = LS_RED;
//        } else if (userCmd == 'q') { // Quit
//            lightVal = LS_DONE;
//        }
//    }
//
//    cout << "Quit program." << endl;

    return 0;
}

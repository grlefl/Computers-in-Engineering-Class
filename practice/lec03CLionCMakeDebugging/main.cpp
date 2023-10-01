#include <iostream>
using namespace std;

// define function
double average5( double x1, double x2, double x3, double x4, double x5);

int main() {
    cout << "This program computes the average of five numbers." << endl;
    cout << "Please enter five integers: ";
    int a1, a2, a3, a4, a5;
    cin >> a1 >> a2 >> a3 >> a4 >> a5;

    cout << "avg = " << average5(a1,a2,a3,a4,a5) << endl;
    cout << "avg = " << average5(1,1,1,1,2) << endl;


    return 0;
}

// define function and elaborate
// the inputs are pass-by-value, copied values
double average5( double x1, double x2, double x3, double x4, double x5) {
    return (x1 + x2 + x3 + x4 + x5) / 5.0;
}
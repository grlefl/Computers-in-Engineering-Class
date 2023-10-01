//
// Created by Grace Flores on 9/18/22.
//

#ifndef INC_1_MULTIFILEEXAMPLE_COMPLEXNUMBER_H
#define INC_1_MULTIFILEEXAMPLE_COMPLEXNUMBER_H

class ComplexNumber {
public:
    double getReal() const; // output is not changed
    void setReal(const double newValue); // input is not changed
private:
    double m_real;
    double m_imag;
};

#endif //INC_1_MULTIFILEEXAMPLE_COMPLEXNUMBER_H

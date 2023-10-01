//
// Created by Grace Flores on 9/18/22.
//

#include "ComplexNumber.h"

double ComplexNumber::getReal() const { // must add ComplexNumber namespace
    return m_real;
}
void ComplexNumber::setReal(const double newValue) {
    m_real = newValue;
}
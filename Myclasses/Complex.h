/*
 * Complex.h
 *
 *  Created on: Feb 19, 2017
 *      Author: haytham
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
#include <math.h> // needed for absolute and arc tan functions

using namespace std;

#define PI 3.14159265359

class Complex {

private: // Private Members of class Complex
    double real;
    double imag;

public: // Public Members of class Complex
    // Reads real and imaginary parts from user
    bool ReadComplex();

    // Returns real part of "this" object
    double GetReal();

    // Returns imaginary part of "this" object
    double GetImag();

    // Stores arg_real value to real part of "this" object
    void SetReal(double arg_real);

    // Stores arg_imag value to imaginary part of "this" object
    void SetImag(double arg_imag);

    // Adds real & imaginary parts of object to real & imaginary parts of "this" object
    // and stores result to real & imaginary parts of "this" object
    void Add(Complex object);

    // Subtracts real & imaginary parts of object from real & imaginary parts of "this" object
    // and stores result to real & imaginary parts of "this" object
    void Subtract(Complex object);

    // Multiplies real & imaginary parts of object with real & imaginary parts of "this" object
    // and stores result to real & imaginary parts of "this" object
    void Multiply(Complex object);

    // Divides real & imaginary parts of object over real & imaginary parts of "this" object
    // and stores result to real & imaginary parts of "this" object
    void Divide(Complex object);

    // Returns Magnitude of "this" object
    double GetMagnitude();

    // Returns Phase of "this" object
    double GetPhase();
    Complex operator+(Complex &e);
};

#endif /* COMPLEX_H_ */

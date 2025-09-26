// Complex number implementation.
//-Function
#include "Mehul_Sept26_task2_Complex.h"

Complex::Complex(double r, double i) : real(r), imaginary(i) {}

Complex Complex::operator+(const Complex& op2) const {
    return Complex(real + op2.real, imaginary + op2.imaginary);
}

Complex Complex::operator-(const Complex& op2) const {
    return Complex(real - op2.real, imaginary - op2.imaginary);
}

Complex Complex::operator*(const Complex& op2) const {
    return Complex(real * op2.real - imaginary * op2.imaginary, real * op2.imaginary + imaginary * op2.real);
}

bool Complex::operator==(const Complex& op2) const {
    return (real == op2.real) && (imaginary == op2.imaginary);
}

bool Complex::operator!=(const Complex& op2) const {
    return !(*this == op2);
}

std::ostream& operator<<(std::ostream& output, const Complex& c) {
    output << '(' << c.real << ", " << c.imaginary << ')';
    return output;
}

std::istream& operator>>(std::istream& input, Complex& c) {
    input.ignore();
    input >> c.real;
    input.ignore(2);
    input >> c.imaginary;
    input.ignore();
    return input;

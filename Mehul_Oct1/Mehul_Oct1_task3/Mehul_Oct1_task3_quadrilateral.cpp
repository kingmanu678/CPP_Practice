#include "Mehul_Oct1_task3_quadrilateral.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Quadrilateral

// Init: copy arrays
Quadrilateral::Quadrilateral(const float s[4], const float a[4]) {
    sides = new float[4];
    angles = new float[4];
    for (int i = 0; i < 4; i++) {
        sides[i] = s[i];
        angles[i] = a[i];
    }
}

// Deep copy
Quadrilateral::Quadrilateral(const Quadrilateral& other) {
    sides = new float[4];
    angles = new float[4];
    for (int i = 0; i < 4; i++) {
        sides[i] = other.sides[i];
        angles[i] = other.angles[i];
    }
}

// Assignment
Quadrilateral& Quadrilateral::operator=(const Quadrilateral& other) {
    if (this != &other) {
        delete[] sides;
        delete[] angles;

        sides = new float[4];
        angles = new float[4];
        for (int i = 0; i < 4; i++) {
            sides[i] = other.sides[i];
            angles[i] = other.angles[i];
        }
    }
    return *this;
}

// Cleanup
Quadrilateral::~Quadrilateral() {
    delete[] sides;
    delete[] angles;
}

// Angle check
bool Quadrilateral::isValid() const {
    float sum = 0;
    for (int i = 0; i < 4; i++) sum += angles[i];
    return std::abs(sum - 360.0f) < 0.001f;
}

// Base area
float Quadrilateral::area() const { return 0.0f; }

float Quadrilateral::perimeter() const {
    return sides[0] + sides[1] + sides[2] + sides[3];
}

std::string Quadrilateral::getType() const { return "Quadrilateral"; }

// Compare areas
bool Quadrilateral::operator==(const Quadrilateral& other) const {
    return std::abs(this->area() - other.area()) < 0.001f;
}

// Stream output operator (print shape details)
std::ostream& operator<<(std::ostream& os, const Quadrilateral& q) {
    os << q.getType() << " [Sides: ";
    for (int i = 0; i < 4; i++) os << q.sides[i] << (i < 3 ? ", " : "");
    os << " | Angles: ";
    for (int i = 0; i < 4; i++) os << q.angles[i] << (i < 3 ? ", " : "");
    os << "]";
    return os;
}

// Operator() returns perimeter
float Quadrilateral::operator()() const { return perimeter(); }

// Cast to float returns area
Quadrilateral::operator float() const { return area(); }

// Trapezoid 
Trapezoid::Trapezoid(const float s[4], const float a[4]) : Quadrilateral(s, a) {}
bool Trapezoid::isValid() const { return Quadrilateral::isValid(); }
float Trapezoid::area() const {
    // Approximation: average of parallel sides * height (using side[1])
    return (sides[0] + sides[2]) / 2 * sides[1];
}
std::string Trapezoid::getType() const { return "Trapezoid"; }

//  Parallelogram
Parallelogram::Parallelogram(const float s[4], const float a[4]) : Trapezoid(s, a) {}
bool Parallelogram::isValid() const { return Quadrilateral::isValid(); }
float Parallelogram::area() const {
    // area = base * height, height derived using sine(angle)
    return sides[0] * sides[1] * std::sin(angles[0] * M_PI / 180.0f);
}
std::string Parallelogram::getType() const { return "Parallelogram"; }

// Rectangle 
Rectangle::Rectangle(const float s[4], const float a[4]) : Parallelogram(s, a) {}
bool Rectangle::isValid() const { return Quadrilateral::isValid(); }
float Rectangle::area() const { return sides[0] * sides[1]; }
std::string Rectangle::getType() const { return "Rectangle"; }

// Square 
Square::Square(const float s[4], const float a[4]) : Rectangle(s, a) {}
bool Square::isValid() const { return Quadrilateral::isValid(); }
float Square::area() const { return sides[0] * sides[0]; }
std::string Square::getType() const { return "Square"; }

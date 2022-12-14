#include "headers/vector.hpp"
#include <math.h>
#include <iostream>

Vector::Vector() : x(0), y(0) {}
Vector::Vector(float _x, float _y) : x(_x), y(_y){}
Vector::Vector(sf::Vector2f vector) : x(vector.x), y(vector.y){}
Vector::Vector(sf::Vector2i vector) : x(vector.x), y(vector.y){}

float Vector::length(){
    return sqrt(x * x + y * y);
}
float Vector::lengthSqrt(){
    return x * x + y * y;
}

void Vector::normalize() {
    float invNorm = 1.0f / length();
    x *= invNorm,
    y *= invNorm;
}

sf::Vector2f Vector::toSfmlVectorF() {
    return sf::Vector2f (x, y);
}
sf::Vector2i Vector::toSfmlVectorI() {
    return sf::Vector2i (x, y);
}

Vector  Vector::operator + (Vector other) { return Vector(x + other.x, y + other.y);}
void    Vector::operator +=(Vector other) { x += other.x; y += other.y; }
Vector  Vector::operator - (Vector other) { return Vector(x - other.x, y - other.y);}
void    Vector::operator -=(Vector other) { x -= other.x; y -= other.y; }
Vector  Vector::operator / (Vector other) { return Vector(x / other.x, y / other.y);}
void    Vector::operator /=(Vector other) { x /= other.x; y /= other.y; }
Vector  Vector::operator * (Vector other) { return Vector(x * other.x, y * other.y); }
void    Vector::operator *=(Vector other) { x *= other.x; y *= other.y; }

Vector  Vector::operator + (float value) { return Vector(x + value, y + value);}
void    Vector::operator +=(float value) { x += value; y += value; }
Vector  Vector::operator - (float value) { return Vector(x - value, y - value);}
void    Vector::operator -=(float value) { x -= value; y -= value; }
Vector  Vector::operator / (float value) { return Vector(x / value, y / value);}
void    Vector::operator /=(float value) { x /= value; y /= value; }
Vector  Vector::operator * (float value) { return Vector(x * value, y * value); }
void    Vector::operator *=(float value) { x *= value; y *= value; }

bool Vector::operator ==(Vector other) { return x == other.x && y == other.y; }
bool Vector::operator !=(Vector other) { return x != other.x && y != other.y; }
bool Vector::operator > (Vector other) { return lengthSqrt() > other.lengthSqrt(); }
bool Vector::operator < (Vector other) { return lengthSqrt() < other.lengthSqrt(); }
bool Vector::operator <=(Vector other) { return lengthSqrt() <= other.lengthSqrt(); }
bool Vector::operator >=(Vector other) { return lengthSqrt() >= other.lengthSqrt(); }

bool Vector::operator ==(float value) { return x == value && y == value; }
bool Vector::operator !=(float value) {return x != value && y != value; }
bool Vector::operator > (float value) {return lengthSqrt() > value * value; }
bool Vector::operator < (float value) {return lengthSqrt() < value * value; }
bool Vector::operator <=(float value) {return lengthSqrt() <= value * value; }
bool Vector::operator >=(float value) {return lengthSqrt() >= value * value; }

std::ostream& operator<<(std::ostream& os, Vector vector)
{
    os << "x: " << vector.x << " y: " << vector.y << " length: " << vector.length() << std::endl;
    return os;
}

void Vector::countLinearFunc (Vector p1, Vector p2, double &k, double &b) {
    k = (p2.y - p1.y) / (p2.x - p1.x);
    b = (p2.x * p1.y - p1.x * p2.y) / (p2.x - p1.x);
}

bool Vector::isPointOnSegment (Vector p1, Vector p2) {
    float segLeng = (p1 - p2).length();
    float aToPoint = (p1 - *this).length();
    float bToPoint = (p2 - *this).length();
    std::cout << (segLeng == aToPoint + bToPoint) << "\n\n\n\n\n\n";
    return segLeng == aToPoint + bToPoint;
}

bool Vector::getIntersection(Vector p1, Vector p2, Vector p3, Vector p4, Vector& res) {
    double k1, b1, k2, b2; // coefficents of first and second graph
    countLinearFunc(p1, p2, k1, b1); 
    countLinearFunc(p3, p4, k2, b2);
    std::cout   << "k1: " << k1 << " b1: " << b1 
                << " k2: " << k2 << " b2: " << b2 
                << std::endl << "p1: " << p1 
                << std::endl << "p2: " << p2
                << std::endl << "p3: " << p3
                << std::endl << "p4: " << p4
                << std::endl;

    float x = (b2 - b1) / (k1 - k2); // coords of common dot
    float y = k1 * x + b1;

    //check if this dot is outside the segments
    std::cout << "x: " << x << " y: " << y << "\t";
    res = Vector(x, y);
    return res.isPointOnSegment(p1, p2); 
}

Vector Vector::getPerpendicular (Vector p1, Vector p2, Vector start) {
    Vector res = Vector(p2.y, -p2.x);
    Vector d = start - p1;
    res += d;
    return res;
}
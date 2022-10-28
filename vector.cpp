#include "headers/vector.hpp"
#include <math.h>

Vector::Vector() : x(0), y(0) {}
Vector::Vector(int _x, int _y) : x(_x), y(_y){}
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

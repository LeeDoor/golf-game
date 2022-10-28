#include "headers/vector.hpp"
#include <math.h>

Vector::Vector() : x(0), y(0) {}
Vector::Vector(int _x, int _y) : x(_x), y(_y){}
Vector::Vector(sf::Vector2f vector) : x(vector.x), y(vector.y){}
Vector::Vector(sf::Vector2i vector) : x(vector.x), y(vector.y){}

float Vector::length(){
    return sqrt(x * x + y * y);
}

void Vector::ChangeLength(float decreaseVal) {
    
}

void Vector::normalize();

sf::Vector2f Vector::toSfmlVectorF();
sf::Vector2i Vector::toSfmlVectorI();

Vector  Vector::operator + (Vector other);
void    Vector::operator +=(Vector other);
Vector  Vector::operator - (Vector other);
void    Vector::operator -=(Vector other);
Vector  Vector::operator / (Vector other);
void    Vector::operator /=(Vector other);

bool Vector::operator ==(Vector other);
bool Vector::operator !=(Vector other);
bool Vector::operator > (Vector other);
bool Vector::operator < (Vector other);
bool Vector::operator <=(Vector other);
bool Vector::operator >=(Vector other);
#pragma once
#include <SFML\Graphics.hpp>

class Vector { 
private:
public:
    float x, y;

    Vector();
    Vector(int x, int y);
    Vector(sf::Vector2f vector);
    Vector(sf::Vector2i vector);

    float length();
    float lengthSqrt();

    void normalize();

    sf::Vector2f toSfmlVectorF();
    sf::Vector2i toSfmlVectorI();

    Vector  operator + (Vector other);
    void    operator +=(Vector other);
    Vector  operator - (Vector other);
    void    operator -=(Vector other);
    Vector  operator / (Vector other);
    void    operator /=(Vector other);

    Vector  operator + (float value);
    void    operator +=(float value);
    Vector  operator - (float value);
    void    operator -=(float value);
    Vector  operator / (float value);
    void    operator /=(float value);

    bool operator ==(Vector other);
    bool operator !=(Vector other);
    bool operator > (Vector other);
    bool operator < (Vector other);
    bool operator <=(Vector other);
    bool operator >=(Vector other);

    bool operator ==(float value);
    bool operator !=(float value);
    bool operator > (float value);
    bool operator < (float value);
    bool operator <=(float value);
    bool operator >=(float value);

    friend std::ostream& operator<<(std::ostream& os, Vector vector);
};
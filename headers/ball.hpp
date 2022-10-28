#pragma once
#include <SFML/Graphics.hpp>
#include "vector.hpp"

class Ball {
private:
    const float friction = 2;
    Vector velocity_;
    sf::CircleShape shape_;
public:
    Ball();
    Ball(sf::CircleShape shape_);

    sf::CircleShape getShape();

    void applyForce(Vector force);
    void update();
};
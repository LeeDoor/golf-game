#pragma once
#include <SFML/Graphics.hpp>
#include "vector.hpp"
#include <memory>

class Ball {
private:
    const float friction = 2;
    Vector direction_;
    float force_;
    std::shared_ptr<sf::CircleShape> shape_;
public:
    Ball();

    std::shared_ptr<sf::CircleShape> getShape();

    void applyForce(Vector direction, float force);
    void update();
};
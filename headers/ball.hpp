#pragma once
#include <SFML/Graphics.hpp>

class Ball {
private:
    const int friction = 0.1;
    sf::Vector2f velocity_;
    sf::CircleShape shape_;
public:
    Ball();
    Ball(sf::CircleShape shape_);

    void ApplyForce(sf::Vector2f force);
    void UpdateMove();
};
#include "headers/ball.hpp"

Ball::Ball() {}
Ball::Ball(sf::CircleShape shape) : shape_(shape){}

void Ball::ApplyForce(sf::Vector2f force) {
    if(velocity_.x == 0 && velocity_.y == 0) {
        velocity_ += force;
    }
}

void Ball::UpdateMove() {
    shape_.setPosition();
}
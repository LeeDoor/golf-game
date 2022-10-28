#include "headers/ball.hpp"
#include <iostream>

Ball::Ball() {}
Ball::Ball(sf::CircleShape shape) : shape_(shape){}

void Ball::applyForce(Vector force) {
    if(velocity_ == 0) {
        velocity_ += force;
    }
}

sf::CircleShape Ball::getShape(){
    return shape_;
}

void Ball::update() {
    if(velocity_.lengthSqrt() > 0) {
        shape_.setPosition(shape_.getPosition() + velocity_.toSfmlVectorF());
        if(velocity_.length() > friction) velocity_ /= friction;
        else velocity_ = Vector();
    }
}
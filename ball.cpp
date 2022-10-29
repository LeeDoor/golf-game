#include "headers/ball.hpp"
#include <iostream>

Ball::Ball() {
    direction_ = Vector();
    force_ = 0;

    shape_ = std::make_shared<sf::CircleShape>(20);
    shape_->setPosition(300, 300);
    shape_->setFillColor(sf::Color::White);
}

std::shared_ptr<sf::CircleShape> Ball::getShape(){
    return shape_;
}

void Ball::applyForce(Vector direction, float force) {
    direction.normalize();
    direction_ = direction;
    force_ += force;
}

void Ball::update() {
    if(force_ > 0) {
        shape_->setPosition((Vector(shape_->getPosition()) + (direction_ * force_)).toSfmlVectorF());
        force_ -= friction;
        if(force_ <= 0) force_ = 0;
    }
}
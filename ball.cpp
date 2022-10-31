#include "headers/ball.hpp"
#include <iostream> 
#include "headers/game_manager.hpp"
#include "headers/wall.hpp"

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
        Vector inters;
        Vector verts;
        Wall wall;
        bool isIntersects = GameManager::getClosestInter(Vector(shape_->getPosition()), vectorToAdd(), inters, wall, verts);

        if(isIntersects) {

            //

            //perpendicular
            Vector perp = Vector::getPerpendicular(wall.getAllVertices()[verts.x], wall.getAllVertices()[verts.y], inters);
            perp.normalize();
            Vector mirror = direction_ - direction_ * perp * perp * (float)2.0; // new direction
            shape_->setPosition(inters.toSfmlVectorF());
            direction_ = mirror;
            // сделать добавление лишней скорости
        }


        shape_->setPosition(vectorToAdd().toSfmlVectorF());
        force_ -= friction;
        if(force_ <= 0) force_ = 0;
    }
}

Vector Ball::vectorToAdd(){
    return Vector(shape_->getPosition()) + direction_ * force_;
}

void Ball::draw(std::shared_ptr<sf::RenderWindow> win){
    win->draw(*shape_);
}
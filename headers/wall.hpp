#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "vector.hpp"
#include <vector>

class Wall {
private:
    std::shared_ptr<sf::RectangleShape> form;
public:
    Wall();
    Wall(Vector pos, float rot, Vector size);

    std::vector<Vector> getAllVertices();
    void draw(std::shared_ptr<sf::RenderWindow> win);
};
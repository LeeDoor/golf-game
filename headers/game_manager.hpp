#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "ball.hpp"
#include "vector.hpp"

class gameManager {
private:
    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<Ball> ball;
public:
    void start();
    void mainLoop();
};
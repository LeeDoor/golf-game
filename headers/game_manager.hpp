#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "ball.hpp"
#include "vector.hpp"
#include "wall.hpp"

class GameManager {
private:
    static std::shared_ptr<sf::RenderWindow> window;
    static std::shared_ptr<Ball> ball;
    static std::shared_ptr<std::vector<Wall>> walls;

    static bool wallInter (Wall wall, Vector p1, Vector p2, Vector& inters, Vector& verticesId);
public:
    static void start();
    static void mainLoop();
    static bool getClosestInter (Vector p1, Vector p2, Vector& inters, Wall& wall, Vector& verticesId);
    static void Update();
};
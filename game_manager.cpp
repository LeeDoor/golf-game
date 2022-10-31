#include "headers/game_manager.hpp"
#include <limits>

std::shared_ptr<sf::RenderWindow>   GameManager::window;
std::shared_ptr<Ball>               GameManager::ball;
std::shared_ptr<std::vector<Wall>>  GameManager::walls;

bool GameManager::wallInter (Wall wall, Vector p1, Vector p2, Vector& inters, Vector& verticesId) {
    std::vector<Vector> verts = wall.getAllVertices();
    float len = std::numeric_limits<float>::max();
    bool isInters = false;

    for(int i = 0, j = 1; i < verts.size(); ++i, j++) {
        if(j == verts.size()) j = 0;
        Vector res;
        if (Vector::getIntersection(p1, p2, verts[i], verts[j], res)) {
            if(res.length() < len) {
                inters = res;
                isInters = true;
                len = inters.length();
                verticesId = Vector(i, j);
            }
        }
    }
    return isInters;
}

bool GameManager::getClosestInter(Vector p1, Vector p2, Vector& inters, Wall& wall, Vector& verticesId) {
    float len = std::numeric_limits<float>::max();
    bool isInters = false;
    
    for(int i = 0; i < walls->size(); ++i) {
        Vector res;
        Vector verticesRes;
        if (wallInter((*walls)[i], p1, p2, res, verticesRes)) {
            if(res.length() < len) {
                inters = res;
                len = inters.length();
                isInters = true;
                verticesId = verticesRes;
            }
        }
    }
    return isInters;
}

void GameManager::start() {
    window = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(1200, 1000), "Golf game"
    );
    window->setFramerateLimit(60);

    ball = std::make_shared<Ball>();

    walls = std::make_shared<std::vector<Wall>>();
    
    Wall w1(Vector(200, 200), 30, Vector(200, 10));
    Wall w2(Vector(100, 400), 60, Vector(400, 20));
    walls->push_back(w1);
    walls->push_back(w2);

    mainLoop();
}

void GameManager::mainLoop() {
    sf::Event event;
    while (window->isOpen())
    {
        while(window->pollEvent(event)){    
            if (event.type == sf::Event::Closed)
                window->close();

            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left){
                Vector mouse = sf::Mouse::getPosition(*window.get());
                Vector move = Vector(ball->getShape()->getPosition()) - mouse;
                ball->applyForce(move, 20);
            }
        }
        ball->update();
        Update();
    }

}

void GameManager::Update(){
    window->clear();

    ball->draw(window);
    for(int i = 0; i < walls->size(); ++i) {
        (*walls)[i].draw(window);
    }

    window->display();
}
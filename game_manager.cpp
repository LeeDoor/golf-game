#include "headers/game_manager.hpp"

void gameManager::start() {
    window = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(1200, 1000), "Golf game"
    );
    window->setFramerateLimit(60);

    ball = std::make_shared<Ball>();

    mainLoop();
}

void gameManager::mainLoop() {
    sf::Event event;
    while (window->isOpen())
    {
        while(window->pollEvent(event)){    
            if (event.type == sf::Event::Closed)
                window->close();

            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left){
                Vector mouse = sf::Mouse::getPosition(*window.get());
                Vector move = Vector(ball->getShape()->getPosition()) - mouse;
                ball->applyForce(move, 50);
            }
        }

        window->clear();

        ball->update();
        window->draw(*ball->getShape());
        window->display();
    }
}
#include <SFML/Graphics.hpp>
#include <iostream>
#include "headers/vector.hpp"
#include "headers/ball.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 600), "SFML works!");
    sf::CircleShape shape(20.f);
    shape.setPosition(300, 300);
    shape.setFillColor(sf::Color::White);
    Ball ball (shape);

    
    
    sf::Event event;
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        while(window.pollEvent(event)){    
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left){
                Vector mouse = sf::Mouse::getPosition(window);
                Vector move = Vector(ball.getShape().getPosition()) - mouse;
                ball.applyForce(move);
            }
        }

        window.clear();

        ball.update();
        window.draw(ball.getShape());
        window.display();
    }
    return 0;
}


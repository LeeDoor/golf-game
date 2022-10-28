#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>


void apply_force(sf::CircleShape& shape, sf::Vector2f force){
    std::cout << "apply force x: " << force.x << " y: " << force.y << std::endl;
    int amount = 500;
    for (int i = 0; i < amount; i++)
    {
        std::cout << "push\n";
        sf::Vector2f pos = shape.getPosition();
        shape.setPosition(pos.x + force.x, pos.y + force.y);
        force = sf::Vector2f(force.x/amount, force.y/amount);
    }
    std::cout << "subthread";
}

std::unique_ptr<std::thread> t1;

int main()
{
    try{
        sf::RenderWindow window(sf::VideoMode(1200, 600), "SFML works!");
        sf::CircleShape shape(20.f);
        shape.setPosition(300, 300);
        shape.setFillColor(sf::Color::White);
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                if(event.type == sf::Event::MouseButtonPressed){
                    sf::Vector2i mouse = sf::Mouse::getPosition(window);
                    std::cout << "x: " << mouse.x << " y: " << mouse.y << std::endl;
                    sf::Vector2f move = shape.getPosition() - (sf::Vector2f)mouse;
                    if(t1.get()!=nullptr)t1->join();
                    t1 = std::make_unique<std::thread>(std::thread([&](){ apply_force(shape, move); }));
                    std::cout << "main thread";
                }
            }

            window.draw(shape);
            window.display();
        }

    }
    catch (std::exception& ex){
        std::cout << ex.what();
    }
    return 0;
}


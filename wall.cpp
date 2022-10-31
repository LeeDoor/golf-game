#include "headers/wall.hpp"

Wall::Wall(){
    form = std::make_shared<sf::RectangleShape>();
}
Wall::Wall(Vector pos, float rot, Vector size) : Wall() {
    form->setPosition(pos.toSfmlVectorF());
    form->setRotation(rot);
    form->setSize(size.toSfmlVectorF());
}

std::vector<Vector> Wall::getAllVertices() {
    std::vector<Vector> res;
    for(int i = 0; i < form->getPointCount(); ++i) {
        res.push_back(form->getPoint(i) + form->getPosition());
    }
    return res;
}

void Wall::draw(std::shared_ptr<sf::RenderWindow> win) {
    win->draw(*form);
}
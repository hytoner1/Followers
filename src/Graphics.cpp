//
// Created by roni on 30.12.2017.
//

#include "Graphics.h"

Graphics::Graphics(sf::RenderWindow &window) :
    m_window(window) {}

void Graphics::drawBodies(std::vector<Follower*> bodies){
    for (auto body : bodies) {
        sf::CircleShape tmp(20, 3);
            tmp.setPosition(body->pos());
            tmp.setFillColor(sf::Color::White);

        m_window.draw(tmp);
    }
}
//
// Created by roni on 30.12.2017.
//

#include <iostream>
#include "Graphics.h"

Graphics::Graphics(sf::RenderWindow &window) :
    m_window(window) {
    sf::Clock m_clock;
}

void Graphics::drawBodies(std::vector<Follower*> bodies){
    for (auto body : bodies) {
        sf::CircleShape tmp(20, 3);
            tmp.setPosition(body->pos());
            tmp.setFillColor(sf::Color::White);

        m_window.draw(tmp);
    }

}



void Graphics::updateBodies(std::vector<Follower*> bodies){
    float t = m_clock.restart().asSeconds();

    for (auto body : bodies) {
        // Update position
        sf::Vector2f tmp_pos(body->pos() + body->vel() * t + (float) 0.5 * body->acc() * (float) pow(t,2));
        sf::Vector2f tmp_vel(body->vel() + body->acc() * t);

        body->pos(tmp_pos);
        body->vel(tmp_vel);

        // Check for out of bounds
        if(body->pos().x < 0){
            body->pos( sf::Vector2f(m_window.getSize().x, 0) +
                       body->pos() );
        }else if(body->pos().x > m_window.getSize().x ){
            body->pos( body->pos() -
                       sf::Vector2f(m_window.getSize().x, 0) );
        }

        if(body->pos().y < 0){
            body->pos( sf::Vector2f(0, m_window.getSize().y) +
                       body->pos() );
        }else if(body->pos().y > m_window.getSize().y ){
            body->pos( body->pos() -
                       sf::Vector2f(0, m_window.getSize().y) );
        }
    }

}


void Graphics::forcesOnBodies(std::vector<Follower*> bodies) {
    for (int i = 0; i < bodies.size() - 1; ++i) {
        bodies[i]->acc(sf::Vector2f(0, 0));
        sf::Vector2f tmp_F(0, 0);

        for (int j = i + 1; j < bodies.size(); ++j) {
            tmp_F = bodies[i]->dir(bodies[j]) *
                    bodies[i]->LJPotentialPair(bodies[j]);


            bodies[i]->acc(bodies[i]->acc() + tmp_F);
            bodies[j]->acc(bodies[j]->acc() - tmp_F);
        }
        //std::cout << tmp_F.x << ", " << tmp_F.y << std::endl;
        //std::cout << bodies[i]->acc().x << ", " << bodies[i]->acc().y << std::endl;
    }
}


void Graphics::eventPoller(sf::Event event){
    while(m_window.pollEvent(event)) {
        switch (event.type) {

            // Window was closed
            case sf::Event::Closed : {
                m_window.close();
                break;
            }


            // Widow was clicked
            case sf::Event::MouseButtonReleased : {
                int mPosx = sf::Mouse::getPosition(m_window).x;
                int mPosy = sf::Mouse::getPosition(m_window).y;

                a2.push_back(new Follower(sf::Vector2f(mPosx,mPosy),
                                          sf::Vector2f(0,0)));
                break;
            }

        }
    }
}

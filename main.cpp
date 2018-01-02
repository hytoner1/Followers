#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>

#include "src/follower.h"
#include "src/Graphics.h"


int main() {

    /*std::vector<Follower*> a2;

    a2.push_back(new Follower(sf::Vector2f(150,1), sf::Vector2f(20,-60)));
    a2.push_back(new Follower(sf::Vector2f(300,1), sf::Vector2f(40,40)));
    a2.push_back(new Follower(sf::Vector2f(500,1), sf::Vector2f(-20,60)));

    a2.push_back(new Follower(sf::Vector2f(100,100), sf::Vector2f(20,60)));
    a2.push_back(new Follower(sf::Vector2f(50,500), sf::Vector2f(20,-60)));
    a2.push_back(new Follower(sf::Vector2f(30,300), sf::Vector2f(40,40)));
    a2.push_back(new Follower(sf::Vector2f(200,20), sf::Vector2f(-20,60)));
    */

    sf::RenderWindow window(sf::VideoMode(800, 600), "Followers");

    Graphics graphics = Graphics(window);
    graphics.m_window.setKeyRepeatEnabled(false);
    graphics.m_window.setFramerateLimit(30);


    graphics.a2.push_back(new Follower(sf::Vector2f(1,1), sf::Vector2f(20,60)));
    graphics.a2.push_back(new Follower(sf::Vector2f(300,1), sf::Vector2f(40,40)));

    while (window.isOpen()) {
        graphics.m_window.clear();

        graphics.drawBodies(graphics.a2);
        graphics.updateBodies(graphics.a2);
        graphics.forcesOnBodies(graphics.a2);

        sf::Event event;

        graphics.eventPoller(event);

        /*while(window.pollEvent(event)) {
            switch (event.type) {
                // Window was closed
                case sf::Event::Closed : {
                    window.close();
                    break;
                }
            }
        }*/
        graphics.m_window.display();
    }


    return 0;
}
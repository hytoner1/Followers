#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>

#include "src/follower.h"
#include "src/Graphics.h"


int main() {
    std::cout << "a!" << std::endl;

    std::vector<Follower*> a2;
    a2.push_back(new Follower(sf::Vector2f(1,1), sf::Vector2f(1,1)));


    std::cout << a2[0]->pos().x << " " << a2[0]->pos().y << std::endl;



    std::cout << "b!" << std::endl;



    sf::RenderWindow window(sf::VideoMode(800, 600), "Followers");

    Graphics graphics = Graphics(window);
    graphics.m_window.setKeyRepeatEnabled(false);
    graphics.m_window.setFramerateLimit(30);

    sf::Clock clock;
    sf::Time t = sf::seconds(0);

    while (window.isOpen()) {
        graphics.m_window.clear();

        graphics.drawBodies(a2);
        a2[0]->updatePos(t);

        sf::Event event;

        while(window.pollEvent(event)) {
            switch (event.type) {
                // Window was closed
                case sf::Event::Closed : {
                    window.close();
                    break;
                }
            }
        }
        graphics.m_window.display();
        t = clock.restart();
    }


    return 0;
}
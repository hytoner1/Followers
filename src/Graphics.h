//
// Created by roni on 30.12.2017.
//

#ifndef FOLLOWERS_GRAPHICS_H
#define FOLLOWERS_GRAPHICS_H

#include <SFML/Graphics.hpp>
#include "follower.h"

/// Graphics engine class
class Graphics {
public:
    /// Initialize graphics engine with a predefined app window
    explicit Graphics(sf::RenderWindow &window);

    void drawBodies(std::vector<Follower*> bodies);
    void updateBodies(std::vector<Follower*> bodies);

    void forcesOnBodies(std::vector<Follower*> bodies);


    sf::RenderWindow &m_window;
    sf::Clock m_clock;
};


#endif //FOLLOWERS_GRAPHICS_H

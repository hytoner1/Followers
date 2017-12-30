//
// Created by roni on 30.12.2017.
//

#ifndef FOLLOWERS_FOLLOWER_H
#define FOLLOWERS_FOLLOWER_H

#include <SFML/System.hpp>

class Follower{
public:
    Follower( sf::Vector2f pos, sf::Vector2f vel );
    ~Follower();

    sf::Vector2f pos() const;
    sf::Vector2f vel() const;

    sf::Vector2f m_pos;
    sf::Vector2f m_vel;
};

#endif //FOLLOWERS_FOLLOWER_H

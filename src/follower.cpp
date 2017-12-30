//
// Created by roni on 30.12.2017.
//

#include "follower.h"

Follower::Follower(sf::Vector2f pos, sf::Vector2f vel) :
    m_pos(pos), m_vel(vel)
    {}

Follower::~Follower() { }

sf::Vector2f Follower::pos() const{
    return m_pos;
}

sf::Vector2f Follower::vel() const{
    return m_vel;
}
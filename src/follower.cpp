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
void Follower::pos(sf::Vector2f pos_new){
    m_pos = pos_new;
}

sf::Vector2f Follower::vel() const{
    return m_vel;
}
void Follower::vel(sf::Vector2f vel_new){
    m_pos = vel_new;
}

void Follower::updatePos(float t){
    sf::Vector2f pos_new = pos() + vel() *  t;
    pos(pos_new);
}
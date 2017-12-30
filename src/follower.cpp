//
// Created by roni on 30.12.2017.
//

#include <iostream>
#include "follower.h"

Follower::Follower(sf::Vector2f pos, sf::Vector2f vel) :
    m_pos(pos), m_vel(vel) {
    }

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

void Follower::updatePos(sf::Time t){
    sf::Vector2f pos_new = pos() + vel() *  t.asSeconds();
    pos(pos_new);
}

float Follower::LJPotentialPair(Follower *other){
    float dist = this->dist(other);
    std::cout << dist << std::endl;
}

float Follower::dist(Follower *other){

    return sqrt(pow(this->pos().x - other->pos().x, 2) +
                pow(this->pos().y - other->pos().y, 2));
}
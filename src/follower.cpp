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
    float abs_vel = sqrt(pow(vel_new.x, 2) + pow(vel_new.y, 2));
    m_vel = vel_new / abs_vel * (float) 50;
}

sf::Vector2f Follower::acc() const{
    return m_acc;
}
void Follower::acc(sf::Vector2f acc_new){
    m_acc = acc_new;
}

void Follower::updatePos(sf::Time t){

}

float Follower::LJPotentialPair(Follower *other){
    float d = this->dist(other);

    float pot = m_eps * -12 * pow(m_sig, 6) * (pow(m_sig, 6) - pow(d, 6)) / (pow(d, 13));
    return pot + m_eps;
}

float Follower::dist(Follower *other){
    return sqrt(pow(this->pos().x - other->pos().x, 2) +
                pow(this->pos().y - other->pos().y, 2));
}

sf::Vector2f Follower::dir(Follower *other) {
    float d = this->dist(other);
    if( d > 0.1 ) {
        return (other->pos() - this->pos()) / d;
    } else{
        return sf::Vector2f(0,0);
    }
}
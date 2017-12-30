//
// Created by roni on 30.12.2017.
//

#ifndef FOLLOWERS_FOLLOWER_H
#define FOLLOWERS_FOLLOWER_H

#include <SFML/System.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class Follower{
public:
    Follower( sf::Vector2f pos, sf::Vector2f vel );
    ~Follower();

    sf::Vector2f pos() const;
    void pos(sf::Vector2f pos_new);

    sf::Vector2f vel() const;
    void vel(sf::Vector2f vel_new);

    sf::Vector2f acc() const;
    void acc(sf::Vector2f acc_new);


    void updatePos(sf::Time t);

    float LJPotentialPair(Follower *other);
    float dist(Follower *other);
    sf::Vector2f dir(Follower *other);

protected:
    sf::Vector2f m_pos;
    sf::Vector2f m_vel;
    sf::Vector2f m_acc = sf::Vector2f(1,0);

    float m_eps = 100;
    float m_sig = 100;

};

#endif //FOLLOWERS_FOLLOWER_H

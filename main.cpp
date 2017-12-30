#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/follower.h"

int main() {
    std::cout << "a!" << std::endl;

    Follower a = Follower(sf::Vector2f(0,0), sf::Vector2f(0,0));
    std::cout << a.pos().x << " " << a.pos().y << std::endl;

    a.pos(sf::Vector2f(10,10));

    std::cout << a.pos().x << " " << a.pos().y << std::endl;



    std::cout << "b!" << std::endl;





    return 0;
}
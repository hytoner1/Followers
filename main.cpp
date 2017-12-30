#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/follower.h"

int main() {
    std::cout << "a!" << std::endl;

    Follower a = Follower(sf::Vector2f(1,1), sf::Vector2f(1,1));
    std::cout << a.pos().x << " " << a.pos().y << std::endl;

    a.updatePos(1.0);

    std::cout << a.pos().x << " " << a.pos().y << std::endl;



    std::cout << "b!" << std::endl;





    return 0;
}
#ifndef _FOOD_HPP_
#define _FOOD_HPP_
#include <SFML/System.hpp>
#include "Map.hpp"

class Food{
    public:
        sf::Vector2f position;
        Food();
        Food(sf::Vector2f place);
        ~Food();
        void relocate(Map &map);
};
#endif

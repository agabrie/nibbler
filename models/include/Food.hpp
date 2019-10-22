#ifndef _FOOD_HPP_
#define _FOOD_HPP_
#include <SFML/System.hpp>
#include "Map.hpp"
#include "Coordinates.hpp"

class Food{
    public:
        // sCoordinates position;
        sf::Vector2f position;
        Food(Map &map);
        // Food(sCoordinates place);
        Food(sf::Vector2f place);
        ~Food();
        void relocate(int width, int height);
};
#endif

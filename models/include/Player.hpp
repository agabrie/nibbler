#ifndef _PLAYERBODY_HPP_
#define _PLAYERBODY_HPP_
#include <list>
#include "PlayerBody.hpp"
class Player{
    public:
        int level;
        std::list<PlayerBody *> body;
        Player();
        ~Player();
        void clearPlayer();
        void extend();
        bool partAt(sf::Vector2f position);
        // bool partAt(sCoordinates position);
        sf::Vector2f checkPosition(sf::Vector2f position, int direction);        
        // sCoordinates checkPosition(sCoordinates position, int direction);
        void moveAll(Map &map);
        void debug();
};
#endif
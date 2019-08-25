#ifndef _PLAYERBODY_HPP_
#define _PLAYERBODY_HPP_
#include <list>
#include "PlayerBody.hpp"
class Player{
    public:
        std::list<PlayerBody *> body;
        Player();
        ~Player();
        void clearPlayer();
        void extend();
        void debug();
};
#endif
#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "./EngineEvent.hpp"
#include "Player.hpp"
// #include "Enemies.hpp"
// #include "Ballom.hpp"
#include "Map.hpp"
#include "Food.hpp"

#include <SFML/System.hpp>
#include <iostream>
#include <vector>

class GameState
{
public:
	Player *player;
	Food food;
	Map *map;
	GameState(int width, int height, int level){
		player = new Player(level);
		map = new Map(width, height);
	}
};

#endif

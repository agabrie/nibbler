
#include "../include/Engine.hpp"
#include <iostream>
#include <vector>
#include <list>
const float UPDATE_TIME = 0.2;
const float EXTEND_TIME = 0.16;

// static float update_time = UPDATE_TIME;
// static float extend_time = EXTEND_TIME;
void Engine::update(double deltaTime, std::vector<EngineEvent> &actions, GameState &gameState)
{
	this->update_time -= deltaTime;
	// this->extend_time -= deltaTime;
	static bool debug_m = false;
	int i = 0;
	PlayerBody *first = gameState.player.body.front();
			
		Direction &direction = first->direction;
			for (EngineEvent event : actions)
			{
				switch (event)
				{
				case EngineEvent::move_up:
					// moveState.north = true;
					if(direction!=Direction::South)
						direction = Direction::North;
					break;
				case EngineEvent::move_right:
					// moveState.east = true;
					if(direction!=Direction::West)
						direction = Direction::East;
					break;
				case EngineEvent::move_down:
					// moveState.south = true;
					if(direction!=Direction::North)
						direction = Direction::South;	
					break;
				case EngineEvent::move_left:
					// moveState.west = true;
					if(direction!=Direction::East)
						direction = Direction::West;
					break;
				case EngineEvent::debug_values:
					debug_m = true;
				// case EngineEvent::debug_stop:
				// 	debug_m = false;
				default:
					break;
				}
			}
		if(this->update_time <= 0.0){
			if(debug_m){
				gameState.player.debug();
				debug_m = false;
			}
			
			this->update_time = UPDATE_TIME;
			Direction next = first->direction;
			for(auto &part:gameState.player.body){
				Direction temp;
				Direction &curr = part->direction;
				part->move(deltaTime, gameState.map);
				temp = curr;
				curr = next;
				next = temp;
			}
			first = gameState.player.body.front();
			if(/*this->update_time <= 0 &&*/ first->position() == gameState.food.position){
				gameState.food.relocate(gameState.map);
				gameState.player.extend();
			}
			// bool destroy = false;
			// int i = -1;
			// for(auto &part:gameState.player.body){
				// i++;
				// if(i>0 && first->position() == part->position())
					// destroy = true;
			// }
			// if(destroy)
				// gameState.player.clearPlayer();
		}

			// gameState.food.reposition();
}
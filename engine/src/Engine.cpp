
#include "../include/Engine.hpp"
#include <iostream>
#include <vector>
#include <list>
const float UPDATE_TIME = 0.2;
// const float EXTEND_TIME = 0.16;

void Engine::update(double deltaTime, std::vector<EngineEvent> &actions, GameState &gameState)
{
	this->update_time -= deltaTime;
	int i = 0;
	PlayerBody *first = gameState.player.body.front();
			
		Direction &direction = first->direction;
			for (EngineEvent event : actions)
			{
				switch (event)
				{
				case EngineEvent::move_up:
					if(direction!=Direction::South)
						direction = Direction::North;
					break;
				case EngineEvent::move_right:
					if(direction!=Direction::West)
						direction = Direction::East;
					break;
				case EngineEvent::move_down:
					if(direction!=Direction::North)
						direction = Direction::South;	
					break;
				case EngineEvent::move_left:
					if(direction!=Direction::East)
						direction = Direction::West;
					break;
				default:
					break;
				}
			}
		if(this->update_time <= 0.0){
			// float diff = (1/(gameState.player.level * 10);
			this->update_time = UPDATE_TIME - (gameState.player.level / 200.0);
			// std::cout<< this->update_time << "\n";
			gameState.player.moveAll(gameState.map);
			if(first->position() == gameState.food.position){
				gameState.food.relocate(gameState.map);
				gameState.player.extend();
			}
			
			first = gameState.player.body.front();
		}
}
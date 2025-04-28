#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "GameState.hpp"
#include <vector>

class Engine
{
	float update_time = 0.195;
	// float extend_time = 0.8;
public:
	void update(double deltaTime, std::vector<EngineEvent> &actions, GameState gameState);
};

#endif

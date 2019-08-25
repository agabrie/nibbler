#ifndef _Renderer_hpp_
#define _Renderer_hpp_

#include <GameState.hpp>

#include <SFML/Graphics.hpp>

#include <vector>

class Renderer
{
public:
	void render(sf::RenderWindow &window, const GameState &state);
private:
	void player(sf::RenderWindow &window, const GameState &state);
	void playerBody(sf::RenderWindow &window, const GameState &state,const PlayerBody &pb);
	void food(sf::RenderWindow &window, const GameState &state);
	// void enemyList(sf::RenderWindow &window, const GameState &state);
	void map(sf::RenderWindow &window, const GameState &state);
};

#endif

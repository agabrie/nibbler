#ifndef _Renderer_hpp_
#define _Renderer_hpp_

#include <GameState.hpp>

#include <SFML/Graphics.hpp>

#include <vector>

class Renderer
{
public:
	float scale;
	// sf::RenderWindow &window;
	Renderer(int x, int y);
	~Renderer();
	void render(sf::RenderWindow &window, const GameState &state);
private:
	virtual void player(sf::RenderWindow &window, const GameState &state);
	virtual void playerBody(sf::RenderWindow &window, const GameState &state,const PlayerBody &pb);
	virtual void food(sf::RenderWindow &window, const GameState &state);
	// void enemyList(sf::RenderWindow &window, const GameState &state);
	virtual void map(sf::RenderWindow &window, const GameState &state);
};

#endif

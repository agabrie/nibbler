#ifndef _Renderer_hpp_
#define _Renderer_hpp_

#include <GameState.hpp>

#include <SFML/Graphics.hpp>

#include <vector>

class IRenderer
{
public:
	float scale;
	// sf::RenderWindow &window;
	IRenderer();
	IRenderer(int x, int y);
	virtual ~IRenderer();
	void render(sf::RenderWindow &window, const GameState &state);
private:
	virtual void player(sf::RenderWindow &window, const GameState &state);
	virtual void playerBody(sf::RenderWindow &window,const PlayerBody &pb);
	virtual void food(sf::RenderWindow &window, const GameState &state);
	// void enemyList(sf::RenderWindow &window, const GameState &state);
	virtual void map(sf::RenderWindow &window, const GameState &state);
};

#endif

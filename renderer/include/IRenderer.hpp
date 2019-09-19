#ifndef _Renderer_hpp_
#define _Renderer_hpp_

#include <GameState.hpp>

#include <SFML/Graphics.hpp>

#include <vector>

class IRenderer
{
	// sf::RenderWindow &_window = NULL;
public:
	float scale;
	IRenderer();
	IRenderer(/*sf::RenderWindow &window,*/int x, int y);
	virtual ~IRenderer();
	void render(sf::RenderWindow &window, const GameState &state);
private:
	virtual void renderHead(sf::RenderWindow &window,const PlayerBody &pb);
	virtual void player(sf::RenderWindow &window, const GameState &state);
	virtual void playerBody(sf::RenderWindow &window,const PlayerBody &pb);
	virtual void food(sf::RenderWindow &window, const GameState &state);
	// void enemyList(sf::RenderWindow &window, const GameState &state);
	virtual void map(sf::RenderWindow &window, const GameState &state);
};

#endif

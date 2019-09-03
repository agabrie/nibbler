#ifndef _Renderer2_hpp_
#define _Renderer2_hpp_

#include <GameState.hpp>

#include <SFML/Graphics.hpp>
#include "IRenderer.hpp"
#include <vector>

class Renderer2:public IRenderer
{
public:
	// float scale;
	// sf::RenderWindow &window;
	Renderer2(int x, int y);
	~Renderer2();
	// void render(sf::RenderWindow &window, const GameState &state);
// private:
// 	virtual void player(sf::RenderWindow &window, const GameState &state);
	void playerBody(sf::RenderWindow &window,const PlayerBody &pb);
	void food(sf::RenderWindow &window, const GameState &state);
// 	// void enemyList(sf::RenderWindow &window, const GameState &state);
	void map(sf::RenderWindow &window, const GameState &state);
};

#endif

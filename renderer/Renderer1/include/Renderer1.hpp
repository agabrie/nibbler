#ifndef _Renderer1_hpp_
#define _Renderer1_hpp_

#include <GameState.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

#include "../../include/IRenderer.hpp"

class Renderer1:public IRenderer
{
public:
	Renderer1();
	Renderer1(int x, int y);
	~Renderer1();
	void render(const GameState &state);
	void player(const GameState &state);
	void playerBody(const PlayerBody &pb);
	void renderHead(const PlayerBody &pb);
	void food(const GameState &state);
	void map(const GameState &state);
};

#endif

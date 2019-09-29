#ifndef _Renderer3_hpp_
#define _Renderer3_hpp_

#include <GameState.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

#include "../../include/IRenderer.hpp"

class Renderer3:public IRenderer
{
public:
	Renderer3();
	Renderer3(int x, int y);
	~Renderer3();

	void render(const GameState &state);
	void player(const GameState &state);
	void playerBody(const PlayerBody &pb);
	void renderHead(const PlayerBody &pb);
	void food(const GameState &state);
	void map(const GameState &state);
};

extern "C" IRenderer *rend(int x, int y){
	return (new Renderer3(x,y));
}
#endif

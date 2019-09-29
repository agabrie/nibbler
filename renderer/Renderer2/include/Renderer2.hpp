#ifndef _Renderer2_hpp_
#define _Renderer2_hpp_

#include <GameState.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

#include "../../include/IRenderer.hpp"

class Renderer2:public IRenderer
{
public:
	Renderer2();
	Renderer2(int x, int y);
	~Renderer2();
	
	void render(const GameState &state);
	void player(const GameState &state);
	void playerBody(const PlayerBody &pb);
	void renderHead(const PlayerBody &pb);
	void food(const GameState &state);
	void map(const GameState &state);
};

extern "C" IRenderer *rend(int x, int y){
	return (new Renderer2(x,y));
}
#endif

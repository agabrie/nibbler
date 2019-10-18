#ifndef _Renderer_hpp_
#define _Renderer_hpp_

#include <GameState.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class IRenderer
{
public:
	sf::RenderWindow _window;
	float scale;
	IRenderer(){}
	IRenderer(int x, int y){if(x == y){;}return ;}
	virtual ~IRenderer(){}
	virtual void render(const GameState &state) = 0;
private:
	virtual void renderHead(const PlayerBody &pb) = 0;
	virtual void player(const GameState &state) = 0;
	virtual void playerBody( const PlayerBody &pb) = 0;
	virtual void food( const GameState &state) = 0;
	virtual void map(const GameState &state) = 0;
};

#endif

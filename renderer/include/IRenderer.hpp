#ifndef _Renderer_hpp_
#define _Renderer_hpp_

#include <GameState.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class IRenderer
{
public:
	sf::RenderWindow *_window;
	float scale;
	IRenderer(){}
	IRenderer(int x, int y){if(x == y){;}return ;}
	virtual ~IRenderer(){}
	// virtual void init(int x, int y) = 0;
	// {
	// 	std::cout <<"didnt make it\n";
	// 	std::cout << sf::VideoMode::getDesktopMode().width<<"\n";
	// 	// _window->create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height),  "nanana");
	// 	sf::RenderWindow *n = new sf::RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height),  "nanana");
	// 	n->clear();
	// 	std::cout <<"didnt make it 2\n";
	// // std::cout << "initted window\n";
	// // getchar();
	// if(x > y)
	//  y = x;

	//  scale = x;
	
	// // {
	// 	std::cout << "scale : " << scale <<"\n";
	// // 	this->scale = sf::VideoMode::getDesktopMode().width/(x+1);
	// // }
	// // else
	// // {
	// // 	std::cout << "x smol\n";
	// // 	this->scale = sf::VideoMode::getDesktopMode().height/(y+1);
	// // }
	// std::cout << "initted window\n";	
	// }
	// virtual IRenderer *init(/*int x, int y*/)=0;
	virtual void render(const GameState &state) = 0;
private:
	virtual void renderHead(const PlayerBody &pb) = 0;
	virtual void player(const GameState &state) = 0;
	virtual void playerBody( const PlayerBody &pb) = 0;
	virtual void food( const GameState &state) = 0;
	virtual void map(const GameState &state) = 0;
};
// IRenderer *init();
#endif

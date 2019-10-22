
#include "./Nibbler.hpp"

#include <stdexcept>
#include <iostream>

// const int MAP_WIDTH = 11;
// const int MAP_HEIGHT = 11;
 static const char *WINDOW_TITLE = "Nibbler";

Nibbler::Nibbler(int width, int height,int level):
	/*: window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), WINDOW_TITLE),*/
	  renderTime(0),
	  engineTime(0)
{
	mapHeight = height;
	mapWidth = width;
	renderer = new Renderer1(width, height);
	// renderer = new IRenderer(width, height);
	gameState = (new GameState(width, height,level));
	this->deltaClock.restart();
	this->frameClock.restart();
}

Nibbler::Nibbler(int width, int height):
	/*: window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), WINDOW_TITLE),*/
	  renderTime(0),
	  engineTime(0)
{
	mapHeight = height;
	mapWidth = width;
	renderer = new Renderer1(width, height);
	gameState = (new GameState(width, height));
	this->deltaClock.restart();
	this->frameClock.restart();
}
Nibbler::~Nibbler()
{
}

void Nibbler::startGame()
{
	this->start();
};

void Nibbler::updateFunc()
{
	if (!renderer->_window.isOpen())
		this->stop();

	std::vector<EngineEvent> actions;
	input.parseKeys(actions, renderer->_window);

	for(EngineEvent event: actions)
	{
		switch (event)
		{
		case EngineEvent::lib1:
			delete renderer;
			renderer = new Renderer1(this->mapWidth, this->mapHeight);
			break;
		case EngineEvent::lib2:
			delete renderer;
			renderer = new Renderer2(this->mapWidth, this->mapHeight);
			break;
		case EngineEvent::lib3:
			delete renderer;
			renderer = new Renderer3(this->mapWidth, this->mapHeight);
		case EngineEvent::quit:
			std::cout<<"\nGame Ended!\n";
			exit(1);
			break;
		default:
			break;
		}
	}
	// input.parseKeys(actions, renderer->_window);
	// Record the time elapsed since starting last render
	this->renderTime = this->deltaClock.getElapsedTime().asSeconds();
	// this->renderTime = 60;
	this->deltaClock.restart();
	
	this->engine.update(this->renderTime + this->engineTime, actions, *this->gameState);
	// std::cout << "Here 1\n";
	// Record the time taken by the engine
	this->engineTime = this->deltaClock.getElapsedTime().asSeconds();
	// this->engineTime = 1000;
	this->deltaClock.restart();

	// Only render if required to enforce frameRate
	if (this->frameClock.getElapsedTime().asSeconds() >= this->perFrameSeconds)
	{
		this->renderer->render(/*this->window,*/ *this->gameState);
		this->frameClock.restart();
	}
}

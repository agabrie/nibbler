
#include "./Nibbler.hpp"

#include <stdexcept>
#include <iostream>

const int MAP_WIDTH = 11;
const int MAP_HEIGHT = 11;

Nibbler::Nibbler()
	: window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE),
	  renderTime(0),
	  engineTime(0)
{
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
	if (!this->window.isOpen())
		this->stop();

	sf::Event event;
	std::vector<EngineEvent> actions;
	input.parseKeys(actions, window);

	// Record the time elapsed since starting last render
	this->renderTime = this->deltaClock.getElapsedTime().asSeconds();
	// this->renderTime = 60;
	this->deltaClock.restart();

	this->engine.update(this->renderTime + this->engineTime, actions, this->gameState);

	// Record the time taken by the engine
	this->engineTime = this->deltaClock.getElapsedTime().asSeconds();
	// this->engineTime = 1000;
	this->deltaClock.restart();

	// Only render if required to enforce frameRate
	if (this->frameClock.getElapsedTime().asSeconds() >= this->perFrameSeconds)
	{
		this->renderer.render(this->window, this->gameState);
		this->frameClock.restart();
	}
}

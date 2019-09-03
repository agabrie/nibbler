#ifndef _Nibbler_hpp_
#define _Nibbler_hpp_

#include "./AMainLoop.hpp"
#include "./Input.hpp"

#include <Engine.hpp>
#include <EngineEvent.hpp>
#include <IRenderer.hpp>
#include <Renderer2.hpp>
#include <SFML/Graphics.hpp>
#include <GameState.hpp>

#include <vector>
#include <ctime>

static const uint WINDOW_WIDTH = 21*60;
static const uint WINDOW_HEIGHT = 21*60;
static const char *WINDOW_TITLE = "Nibbler";

class Nibbler : private AMainLoop
{
private:
	sf::RenderWindow window;
	Engine engine;
	IRenderer *renderer;
	Input input;

	GameState *gameState;

	sf::Clock deltaClock;
	sf::Clock frameClock;
	float renderTime;
	float engineTime;
	int mapWidth;
	int mapHeight;
	virtual void updateFunc();

public:
	Nibbler(int width,int height);
	Nibbler(int width,int height,int level);
	~Nibbler();

	void startGame();
};

#endif

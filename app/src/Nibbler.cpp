
#include "./Nibbler.hpp"
#include <dlfcn.h>
#include <stdexcept>
#include <iostream>

// const int MAP_WIDTH = 11;
// const int MAP_HEIGHT = 11;
//  static const char *WINDOW_TITLE = "Nibbler";
const std::string LIB_EXT = ".so";
const std::string LIB_DIR = "./RenderLib/";
// const std::string EXT = ".dylib";
Nibbler::Nibbler(int width, int height,int level):
renderTime(0),
engineTime(0)
{
	mapHeight = height;
	mapWidth = width;
	loadLib(LIB_DIR+"Renderer1"+LIB_EXT);
	// this->renderer = (*this->dylib_init)(mapWidth,mapHeight);
	gameState = (new GameState(width, height,level));
	this->deltaClock.restart();
	this->frameClock.restart();
}

Nibbler::Nibbler(int width, int height):
renderTime(0),
engineTime(0)
{
	mapHeight = height;
	mapWidth = width;
	loadLib(LIB_DIR+"Renderer1"+LIB_EXT);
	// this->renderer = (*this->dylib_init)(mapWidth,mapHeight);
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

void Nibbler::loadLib(std::string _libPath) {
    this->_libhandle = dlopen(_libPath.c_str(), RTLD_LAZY); 
    if(this->_libhandle == NULL){
        std::cerr << "Failed to load " + _libPath << std::endl << dlerror() << std::endl;
   	// cerr << dlerror() << endl;
        // exit (1);
   		exit(-1);
        // this->init = (init_t) dlsym(this->_libhandle, "init");
        // this->endGame = (endGame_t) dlsym(this->_libhandle, "endGame");
        // this->closeWindow = (closeWindow_t) dlsym(this->_libhandle, "closeWindow");
        // this->getInput = (getInput_t) dlsym(this->_libhandle, "getInput");
    } else {
		typedef IRenderer* (*dylib_init)(int,int);
		this->dylib_init = (dylib_init) dlsym(this->_libhandle, "rend");
		this->renderer = (*this->dylib_init)(mapWidth,mapHeight);
    }
}
void Nibbler::updateFunc()
{
	// std::cout << "update Func\n";
	if (!renderer->_window->isOpen())
		this->stop();
	// std::cout << "test window\n";
	std::vector<EngineEvent> actions;
	input.parseKeys(actions, *(renderer->_window));
	// std::cout << "test keys\n";
	for(EngineEvent event: actions)
	{
		switch (event)
		{
		case EngineEvent::lib1:
			// delete renderer;		
			// renderer = new Renderer1(this->mapWidth, this->mapHeight);
			loadLib(LIB_DIR+"Renderer1"+LIB_EXT);
			break;
		case EngineEvent::lib2:
			// delete renderer;
			// renderer = new Renderer2(this->mapWidth, this->mapHeight);
			loadLib(LIB_DIR+"Renderer2"+LIB_EXT);
			break;
		case EngineEvent::lib3:
			// delete renderer;
			// renderer = new Renderer3(this->mapWidth, this->mapHeight);
			loadLib(LIB_DIR+"Renderer3"+LIB_EXT);
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
		renderer->render(/*this->window,*/ *this->gameState);
		this->frameClock.restart();
	}
}

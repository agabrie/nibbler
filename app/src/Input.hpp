#ifndef _Input_hpp_
#define _Input_hpp_

#include <EngineEvent.hpp>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>

#include <map>

typedef sf::Keyboard::Key Key;

class Input
{
private:
	Key _up;
	Key _down;
	Key _left;
	Key _right;
	Key _lib1;
	Key _lib2;
	Key _lib3;

public:
	Input();
	~Input();

	void parseKeys(std::vector<EngineEvent> &engineEvents, sf::RenderWindow &window);
	// EngineEvent getInput(Key key);

	Key getUp() const;
	void setUp(Key key);

	Key getDown() const;
	void setDown(Key key);

	Key getLeft() const;
	void setLeft(Key key);

	Key getRight() const;
	void setRight(Key key);
	
	Key getLib1() const;
	void setLib1(Key key);

	Key getLib2() const;
	void setLib2(Key key);

	Key getLib3() const;
	void setLib3(Key key);

};

#endif

#include "./Input.hpp"

#include <iostream>

Input::Input() : _up(Key::Up),
				 _down(Key::Down),
				 _left(Key::Left),
				 _right(Key::Right)
{
}

Input::~Input() {}

// EngineEvent Input::getInput(Key key)
// {
// 	if (key == this->_up)
// 		return EngineEvent::move_up;
// 	else if (key == this->_down)
// 		return EngineEvent::move_down;
// 	else if (key == this->_left)
// 		return EngineEvent::move_left;
// 	else if (key == this->_right)
// 		return EngineEvent::move_right;
// 	else if (key == this->_bomb)
// 		return EngineEvent::place_bomb;
// 	else
// 		return EngineEvent::unknown;
// }

// Need to be modified later
void Input::parseKeys(std::vector<EngineEvent> &engineEvents, sf::RenderWindow &window)
{
	// std::cout << "in keys\n";
	sf::Event event;
	EngineEvent eEvent = unknown;
	// TODO: Break into functions
	// TODO: Apply bindings
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case event.KeyPressed:
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				eEvent = EngineEvent::move_up;
				break;
			case sf::Keyboard::Left:
				eEvent = EngineEvent::move_left;
				break;
			case sf::Keyboard::Down:
				eEvent = EngineEvent::move_down;
				break;
			case sf::Keyboard::Right:
				eEvent = EngineEvent::move_right;
				break;
			case sf::Keyboard::Numpad1:
				eEvent = EngineEvent::lib1;
				// std::cout << "num 1 pressed\n";
				break;
			case sf::Keyboard::F1:
				eEvent = EngineEvent::lib1;
				// std::cout << "num 1 pressed\n";
				break;
			case sf::Keyboard::Numpad2:
				eEvent = EngineEvent::lib2;
				break;
			case sf::Keyboard::F2:
				eEvent = EngineEvent::lib2;
				break;
			case sf::Keyboard::Numpad3:
				eEvent = EngineEvent::lib3;
				break;
			case sf::Keyboard::F3:
				eEvent = EngineEvent::lib3;
				break;
			case sf::Keyboard::Escape:
				eEvent = EngineEvent::quit;
				break;
			case sf::Keyboard::Space:
				eEvent = EngineEvent::debug_values;
			default:
				break;
			}
			break;
		}
		case event.KeyReleased:
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				eEvent = EngineEvent::stop_up;
				break;
			case sf::Keyboard::Left:
				eEvent = EngineEvent::stop_left;
				break;
			case sf::Keyboard::Down:
				eEvent = EngineEvent::stop_down;
				break;
			case sf::Keyboard::Right:
				eEvent = EngineEvent::stop_right;
				break;
			case sf::Keyboard::Space:
				eEvent = EngineEvent::debug_stop;
			default:
				break;
			}
			break;
		}
		default:
			break;
		}
		if (eEvent != unknown)
			engineEvents.push_back(eEvent);
	}
}

Key Input::getUp() const
{
	return this->_up;
}

void Input::setUp(Key key)
{
	this->_up = key;
}

Key Input::getDown() const
{
	return this->_down;
}

void Input::setDown(Key key)
{
	this->_down = key;
}

Key Input::getLeft() const
{
	return this->_left;
}

void Input::setLeft(Key key)
{
	this->_left = key;
}

Key Input::getRight() const
{
	return this->_right;
}

void Input::setRight(Key key)
{
	this->_right = key;
}

Key Input::getLib1() const
{
	return this->_lib1;
}

void Input::setLib1(Key key)
{
	this->_lib1 = key;
}

Key Input::getLib2() const
{
	return this->_lib2;
}

void Input::setLib2(Key key)
{
	this->_lib2 = key;
}

Key Input::getLib3() const
{
	return this->_lib3;
}

void Input::setLib3(Key key)
{
	this->_lib3 = key;
}


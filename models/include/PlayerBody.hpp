#ifndef _PlayerBody_hpp_
#define _PlayerBody_hpp_

#include "Map.hpp"

#include <SFML/System.hpp>

enum Direction
{
	North = 1,
	East = 2,
	South = -1,
	West = -2
};

class PlayerBody
{
	sf::Vector2f _position;

	float _playerSpeed;

public:
	PlayerBody();
	PlayerBody(sf::Vector2f start);
	~PlayerBody();

	Direction direction;
	void updateDirection(Direction newDirection);
	sf::Vector2f checkPosition(sf::Vector2f position, Direction direction);
	void move(const Map &map);
	const sf::Vector2f &position() const;
};

#endif

#ifndef _PlayerBody_hpp_
#define _PlayerBody_hpp_

#include "Map.hpp"

#include <SFML/System.hpp>

enum Direction
{
	North,
	East,
	South,
	West
};

class PlayerBody
{
	sf::Vector2f _position;

	float _playerSpeed;

	bool correctPlayerCellCollision(sf::Vector2i cell);

public:
	PlayerBody();
	PlayerBody(sf::Vector2f start);
	~PlayerBody();

	Direction direction;

	void move(float deltaTime, const Map &map);
	const sf::Vector2f &position() const;
};

#endif

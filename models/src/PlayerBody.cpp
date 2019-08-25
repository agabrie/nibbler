#include "../include/PlayerBody.hpp"

#include <iostream>
#include <cmath>

const sf::Vector2f DEFAULT_START(1.5, 1.5);
const float DEFAULT_SPEED = 1;

// Testing order here is important
// Test cardinals first
const sf::Vector2i TEST_NEIGHBOURS[4] = {
	sf::Vector2i(0, 1),   //NORTH
	sf::Vector2i(1, 0),   //EAST
	sf::Vector2i(0, -1),  //SOUTH
	sf::Vector2i(-1, 0),  //WEST
	// sf::Vector2i(1, 1),   //NE
	// sf::Vector2i(-1, 1),  //SE
	// sf::Vector2i(1, -1),  //SW
	// sf::Vector2i(-1, -1), //NW
};

PlayerBody::PlayerBody() : _position(DEFAULT_START),
				   _playerSpeed(DEFAULT_SPEED),
				   direction(Direction::South)
{
}
PlayerBody::PlayerBody(sf::Vector2f start) : _position(start),
										_playerSpeed(DEFAULT_SPEED),
										direction(Direction::South)
{

}
PlayerBody::~PlayerBody()
{
}

bool PlayerBody::correctPlayerCellCollision(sf::Vector2i cell)
{
	const float RADIUS = 0.5;

	// Use variables to avoid multiple pointer refs
	float playerX = this->_position.x;
	float playerY = this->_position.y;
	int cellX = cell.x;
	int cellY = cell.y;

	float testX = playerX;
	float testY = playerY;

	// Check for the closest edge
	if (playerX < cellX)
		testX = cellX; // Left edge
	else if (playerX > cellX + 1)
		testX = cellX + 1; // Right edge
	if (playerY < cellY)
		testY = cellY; // Top edge
	else if (playerY > cellY + 1)
		testY = cellY + 1; // Bottom edge

	// Evaluate distance from closest edges
	sf::Vector2f diff(playerX - testX, playerY - testY);

	// Pythag distance needed for corners
	float distance = std::sqrt((diff.x * diff.x) + (diff.y * diff.y));

	// If the distance is less than the radius, collision!
	if (distance <= RADIUS - 0.0001)
	{
		if (diff.y == 0)
		{
			if (playerX > cellX)
				this->_position.x += RADIUS - diff.x;
			else
				this->_position.x -= RADIUS + diff.x;
		}
		else if (diff.x == 0)
		{
			if (playerY > cellY)
				this->_position.y += RADIUS - diff.y;
			else
				this->_position.y -= RADIUS + diff.y;
		}
		else
		{
			sf::Vector2f corner(testX, testY);
			sf::Vector2f correction = (diff / distance) * RADIUS;
			this->_position = corner + correction;
		}
		return true;
	}
	return false;
}

void PlayerBody::move(float deltaTime, const Map &map)
{
	// MoveState &moveState = this->moveState;

	sf::Vector2f movement(0, 0);
	switch(this->direction){
		case Direction::North:
			movement.y -= 1;
			break;
		case Direction::South:
			movement.y += 1;
			break;
		// movement.x += moveState.east;
		// movement.x -= moveState.west;
		// movement.y += moveState.south;
		case Direction::East:
			movement.x += 1;
			break;
		case Direction::West:
			movement.x -= 1;
			break;
		default:break;

	}
	// std::cout<<deltaTime<<"\n";
	sf::Vector2i playerCell(this->_position);
	sf::Vector2i cell = playerCell + sf::Vector2i(movement);
	if(map.tileAt(cell) != Tile::Solid)
		this->_position = this->_position + movement/* (movement * this->_playerSpeed * deltaTime)*/;

	// for (sf::Vector2i direction : TEST_NEIGHBOURS)
	// {
	// 	Tile tile = map.tileAt(cell);
	// 	if (!(tile == Tile::Clear))
	// 		correctPlayerCellCollision(cell);
	// }
}

const sf::Vector2f &PlayerBody::position() const
{
	return this->_position;
};

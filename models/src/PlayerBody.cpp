#include "../include/PlayerBody.hpp"
#include "../include/Coordinates.hpp"

#include <iostream>
#include <cmath>

const sf::Vector2f DEFAULT_START(1.5, 1.5);
// const sCoordinates DEFAULT_START(1.5, 1.5);

const float DEFAULT_SPEED = 1;

PlayerBody::PlayerBody() : _position(DEFAULT_START),
				   _playerSpeed(DEFAULT_SPEED),
				   direction(Direction::South)
{
}
// PlayerBody::PlayerBody(sCoordinates start) : _position(start),
PlayerBody::PlayerBody(sf::Vector2f start) : _position(start),

										_playerSpeed(DEFAULT_SPEED),
										direction(Direction::South)
{

}
PlayerBody::~PlayerBody()
{
}

void PlayerBody::move(const Map &map)
{
	sf::Vector2f movement(0, 0);
	// sCoordinates movement(0, 0);

	switch(this->direction){
		case Direction::North:
			movement.y -= _playerSpeed;
			break;
		case Direction::South:
			movement.y +=_playerSpeed;
			break;
		case Direction::East:
			movement.x += _playerSpeed;
			break;
		case Direction::West:
			movement.x -= _playerSpeed;
			break;
		default:break;

	}
	if(map.tileAt(sf::Vector2i(checkPosition(this->position(),this->direction))) == Tile::Solid){
	// if(map.tileAt(sCoordinates(checkPosition(this->position(),this->direction))) == Tile::Solid){

		std::cout << "Game Over!\n\tHit A Wall\n";
		exit(1);
	}
	else
		this->_position = checkPosition(this->_position, this->direction);
}
	sf::Vector2f PlayerBody::checkPosition(sf::Vector2f position, Direction direction){
	// sCoordinates PlayerBody::checkPosition(sCoordinates position, Direction direction){    
	sf::Vector2f newPosition(0,0);
	// sCoordinates newPosition(0,0);

    switch (direction)
    {
    case Direction::North:
        newPosition.y = -1;
        break;
    case Direction::South:
        newPosition.y = 1;
        break;
    case Direction::West:
        newPosition.x = -1;
        break;
    case Direction::East:
        newPosition.x = 1;
        break;
        default:break;
    }
    return sf::Vector2f(position+newPosition);

    // return sCoordinates(position+newPosition);
}
void PlayerBody::updateDirection(Direction newDirection){
	this->direction = newDirection;
}
// sCoordinates &PlayerBody::position()
const sf::Vector2f &PlayerBody::position() const
{
	return this->_position;
};

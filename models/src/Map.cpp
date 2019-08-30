#include "../include/Map.hpp"
#include "../include/Coordinates.hpp"

#include <cstdlib>
#include <ctime>

const sf::Vector2i DEFAULT_SIZE(21, 21);
// const sCoordinates DEFAULT_SIZE(21, 21);

const float DESTRUCTABLE_CHANCE = 0.1;

Map::Map(int width, int height)
	: 
	  _tiles(this->_size.x * this->_size.y, Tile::Clear)
{
	_size.x = width;
	_size.y = height;
	std::srand(time(NULL));

	for (int y = 0; y < _size.y; y++)
	{
		for (int x = 0; x < _size.x; x++)
		{
			if (x == 0 || y == 0 || x == this->_size.x - 1 || y == this->_size.y - 1)
				this->_tiles[y * this->_size.x + x] = Tile::Solid;
			// else if (x % 2 == 0 && y % 2 == 0)
			// 	this->_tiles[y * this->_size.x + x] = Tile::Solid;
			// else
			// {
				// if (static_cast<float>(rand()) / RAND_MAX < DESTRUCTABLE_CHANCE)
				// 	this->_tiles[y * this->_size.x + x] = Tile::Destructible;
			// }
		}
	}

	// Player starting cell
	this->_tiles[1 * this->_size.x + 1] = Tile::Clear;
}

Map::~Map()
{
}

// Tile Map::tileAt(sCoordinates pos) const
Tile Map::tileAt(sf::Vector2i pos) const

{
	return this->_tiles[pos.y * this->_size.x + pos.x];
}

// void Map::setTile(sCoordinates pos, Tile tile)
void Map::setTile(sf::Vector2i pos, Tile tile)

{
	this->_tiles[pos.y * this->_size.x + pos.x] = tile;
}

// const sCoordinates &Map::size() const
const sf::Vector2i &Map::size() const

{
	return this->_size;
}

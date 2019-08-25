#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/System.hpp>
#include "Coordinates.hpp"
#include <vector>

enum Tile
{
	Solid,
	Clear
};

class Map
{
private:
	// sf::Vector2i _size;
	sCoordinates _size;
	std::vector<Tile> _tiles;

public:
	Map();
	~Map();
	// sf::Vector2i getSize();
	// Tile tileAt(sf::Vector2i pos) const;
	Tile tileAt(sCoordinates pos) const;

	// void setTile(sf::Vector2i pos, Tile tile);

	void setTile(sCoordinates pos, Tile tile);
	// const sf::Vector2i &size() const;
	const sCoordinates &size() const;

};

#endif

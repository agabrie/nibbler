#include "../include/Renderer2.hpp"

#include <iostream>

const std::string WINDOW_TITLE = "Nibbler 2";

Renderer2::Renderer2()
{
	this->scale = sf::VideoMode::getDesktopMode().height/(sf::VideoMode::getDesktopMode().bitsPerPixel+1);
}

Renderer2::Renderer2(int x, int y)
{
	_window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height),  WINDOW_TITLE);
	if(x > y)
		this->scale = sf::VideoMode::getDesktopMode().width/(x+1);
	else
		this->scale = sf::VideoMode::getDesktopMode().height/(y+1);
}

Renderer2::~Renderer2(){
}

void Renderer2::render(const GameState &state)
{
	_window.clear(sf::Color::Black);
	map(state);
	player(state);
	food(state);
	_window.display();
}

void Renderer2::player(const GameState &state)
{
	int i = 0;
	for(auto &part: state.player->body){
		i++;
		if(i == 1)
			renderHead(*part);
		else
			playerBody(*part);
	}
}

void Renderer2::renderHead(const PlayerBody &pb)
{
	sf::CircleShape player(scale / 2,3);
	
	player.setOrigin(scale/2,scale/2);
	switch(pb.direction){
		case Direction::South:
			player.rotate(180.f);
			break;
		case Direction::East:
			player.rotate(90.f);
			break;
		case Direction::North:
			player.rotate(0.f);
			break;
		case Direction::West:
			player.rotate(270.f);
			break;
		default:break;
	}
	player.setFillColor(sf::Color(255, 255, 255));
	
	sf::Vector2f playerPosition(pb.position());
	playerPosition *= scale;
	player.setPosition(playerPosition);
	
	_window.draw(player);
}

void Renderer2::playerBody(const PlayerBody &pb)
{
	sf::CircleShape player(scale / 2,6);

	player.setFillColor(sf::Color(200, 200, 200));
	
	sf::Vector2f playerPosition(pb.position());
	playerPosition -= sf::Vector2f(0.5, 0.5);
	playerPosition *= scale;
	player.setPosition(playerPosition);
	
	_window.draw(player);
}

void Renderer2::food(const GameState &state)
{
	sf::CircleShape food(scale / 2,6);
	
	food.setFillColor(sf::Color(255, 102, 178));
	
	sf::Vector2f foodPosition(state.food->position);
	foodPosition -= sf::Vector2f(0.5, 0.5);
	foodPosition *= scale;
	food.setPosition(foodPosition);
	
	_window.draw(food);
}

void Renderer2::map(const GameState &state)
{
	const Map &map = *state.map;
	const sf::Vector2i &mapSize = map.size();
	Tile tile;
	sf::CircleShape cell(scale / 2,6);
	cell.setFillColor(sf::Color(250));
	for (int y = 0; y < mapSize.y; y++)
	{
		for (int x = 0; x < mapSize.x; x++)
		{
			sf::Vector2i cellPosition(x, y);
			tile = map.tileAt(cellPosition);
			if (tile != Tile::Clear)
			{
				cellPosition *= static_cast<int>(scale);
				cell.setPosition(cellPosition.x, cellPosition.y);
				
				switch (tile)
				{
				case Tile::Solid:
					cell.setFillColor(sf::Color(50, 150, 20));
					_window.draw(cell);
					break;
				default:
					break;
				}
			}
		}
	}
}

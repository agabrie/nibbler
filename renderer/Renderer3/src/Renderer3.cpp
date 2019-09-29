#include "../include/Renderer3.hpp"

#include <iostream>

const std::string WINDOW_TITLE = "Nibbler 3";
const std::string TEXTURE_PATH = "../renderer/Renderer3/textures/";
Renderer3::Renderer3()
{
	this->scale = sf::VideoMode::getDesktopMode().height/(sf::VideoMode::getDesktopMode().bitsPerPixel+1);
}

Renderer3::Renderer3(int x, int y)
{
	_window->create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height),  WINDOW_TITLE);
	if(x > y)
		this->scale = sf::VideoMode::getDesktopMode().width/(x+1);
	else
		this->scale = sf::VideoMode::getDesktopMode().height/(y+1);
}

Renderer3::~Renderer3(){
}

void Renderer3::render(const GameState &state)
{
	_window->clear(sf::Color::Black);
	map(state);
	player(state);
	food(state);
	_window->display();
}

void Renderer3::player(const GameState &state)
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

void Renderer3::playerBody(const PlayerBody &pb)
{
	sf::RectangleShape player(sf::Vector2f(scale-(scale/10),scale-(scale/10)));
	
	sf::Texture texture;
	if (!texture.loadFromFile(TEXTURE_PATH+"BodyDown.png")){}
	sf::Vector2f playerPosition(pb.position());
	player.setTexture(&texture); // texture is a sf::Texture
	player.setTextureRect(sf::IntRect(0, 0, 32, 32));
	
	playerPosition -= sf::Vector2f(0.5, 0.5);
	playerPosition *= scale;
	player.setPosition(playerPosition);
	
	_window->draw(player);
}

void Renderer3::renderHead(const PlayerBody &pb)
{
	sf::RectangleShape player(sf::Vector2f(scale-(scale/10),scale-(scale/10)));
	
	sf::Texture texture;
	texture.loadFromFile(TEXTURE_PATH+"headup.png");
	player.setOrigin(scale/2,scale/2);
	switch(pb.direction){
		case Direction::North:
			player.rotate(0.f);
			break;
		case Direction::East:
			player.setOrigin((scale/2),(scale/2));
			player.rotate(90.f);
			break;
		case Direction::South:
			player.setOrigin((scale/2)-(scale/10),(scale/2)-(scale/10));
			player.rotate(180.f);
			break;
		case Direction::West:
			player.setOrigin((scale/2)-(scale/10),(scale/2));
			player.rotate(270.f);
			break;
		default:break;
	}
	player.setTexture(&texture); // texture is a sf::Texture
	player.setTextureRect(sf::IntRect(0, 0, 32, 32));
	
	sf::Vector2f playerPosition(pb.position());
	playerPosition *= scale;
	player.setPosition(playerPosition);
	
	_window->draw(player);
}

void Renderer3::food(const GameState &state)
{
	sf::CircleShape food((scale -( scale/10))/ 2);

	sf::Vector2f foodPosition(state.food->position);
	foodPosition -= sf::Vector2f(0.5, 0.5);
	foodPosition *= scale;

	food.setPosition(foodPosition);
	food.setFillColor(sf::Color(255, 102, 178));
	_window->draw(food);
}

void Renderer3::map(const GameState &state)
{
	const Map &map = *state.map;
	const sf::Vector2i &mapSize = map.size();
	Tile tile;
	sf::RectangleShape cell(sf::Vector2f(scale-(scale/10), scale-(scale/10)));

	sf::Texture texture;
	if (!texture.loadFromFile(TEXTURE_PATH+"block.png"))
	{
	}
	for (int y = 0; y < mapSize.y; y++)
	{
		for (int x = 0; x < mapSize.x; x++)
		{
			sf::Vector2i cellPosition(x, y);
			tile = map.tileAt(cellPosition);
			if (tile != Tile::Clear)
			{
				cellPosition *= static_cast<int>(scale);
				cell.setPosition((cellPosition.x-0.5)*1, (cellPosition.y-0.5)*1);
				switch (tile)
				{
					case Tile::Solid:
						cell.setTexture(&texture); // texture is a sf::Texture
						cell.setTextureRect(sf::IntRect(0, 0, 32, 32));
						_window->draw(cell);
						break;
					default:
						break;
				}
			}
		}
	}
}
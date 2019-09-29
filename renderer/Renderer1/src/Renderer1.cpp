#include "../include/Renderer1.hpp"

#include <iostream>

const std::string WINDOW_TITLE = "Nibbler 1";

Renderer1::Renderer1()
{
	this->scale = sf::VideoMode::getDesktopMode().height/(sf::VideoMode::getDesktopMode().bitsPerPixel+1);
}

Renderer1::Renderer1(int x, int y)
{
	this->_window = new sf::RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height),  WINDOW_TITLE);
	if(x > y)
		this->scale = sf::VideoMode::getDesktopMode().width/(x+1);
	else
		this->scale = sf::VideoMode::getDesktopMode().height/(y+1);
}

Renderer1::~Renderer1()
{
}

void Renderer1::render(const GameState &state)
{
	_window->clear(sf::Color::Black);
	map(state);
	player(state);
	food(state);
	_window->display();
}

void Renderer1::player(const GameState &state)
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

void Renderer1::renderHead(const PlayerBody &pb)
{
	sf::RectangleShape player(sf::Vector2f(scale-(scale/10),scale-(scale/10)));
	sf::Vector2f playerPosition(pb.position());
	playerPosition -= sf::Vector2f(0.5, 0.5);
	playerPosition *= scale;
	player.setOutlineThickness(5);
	player.setOutlineColor(sf::Color(0, 0, 0));
	player.setPosition(playerPosition);
	player.setFillColor(sf::Color(255, 255, 255));
	_window->draw(player);
}
void Renderer1::playerBody(const PlayerBody &pb)
{
	sf::RectangleShape player(sf::Vector2f(scale-(scale/10),scale-(scale/10)));
	player.setOutlineThickness(5);
	player.setOutlineColor(sf::Color(0, 0, 0));
	sf::Vector2f playerPosition(pb.position());
	playerPosition -= sf::Vector2f(0.5, 0.5);
	// playerPosition.y *= -1;
	playerPosition *= scale;

	player.setPosition(playerPosition);
	// player.setFillColor(sf::Color(50, 250, 50));
			player.setFillColor(sf::Color(200, 200, 200));

	_window->draw(player);
}

void Renderer1::food(const GameState &state)
{
	sf::CircleShape food((scale -( scale/10))/ 2);

	sf::Vector2f foodPosition(state.food->position);
	foodPosition -= sf::Vector2f(0.5, 0.5);
	foodPosition *= scale;

	food.setPosition(foodPosition);
// 	switch(e.type){
// 		case EnemyType::EBallom:
			// enemy.setFillColor(sf::Color(0, 255, 255));
// 			break;
// 		case EnemyType::EAggroBallom:
			food.setFillColor(sf::Color(255, 102, 178));
// 			break;
// 		default:
// 			enemy.setFillColor(sf::Color(255, 255, 0));
// 			break;
// 	}
	_window->draw(food);
}

void Renderer1::map(const GameState &state)
{
	const Map &map = *state.map;
	const sf::Vector2i &mapSize = map.size();
	Tile tile;
	sf::RectangleShape cell(sf::Vector2f(scale-(scale/10), scale-(scale/10)));
	// sf::CircleShape bomb(SCALE / 2);
	// system("pwd");
	// sf::Texture texture;
	// if (!texture.loadFromFile("../renderer/src/block.png"))
	{
    	// cell.setTexture(&texture); // texture is a sf::Texture
		// cell.setTextureRect(sf::IntRect(0, 0, 32, 32));
	}
	// cell.setFillColor(sf::Color(250));

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
				
				cell.setOutlineThickness(5);
				cell.setOutlineColor(sf::Color(0, 0, 0));
				switch (tile)
				{
				case Tile::Solid:
					cell.setFillColor(sf::Color(50, 150, 20));
					// cell.setTexture(&texture); // texture is a sf::Texture
					// cell.setTextureRect(sf::IntRect(0, 0, 32, 32));
					_window->draw(cell);
					break;
				// case Tile::Destructible:
					// cell.setFillColor(sf::Color(50, 50, 150));
					// window.draw(cell);
					// break;
				// case Tile::Bomb:
					// bomb.setPosition(cellPosition.x, cellPosition.y);
					// window.draw(bomb);
					// break;
				// case Tile::Flame:
					// cell.setFillColor(sf::Color(255, 0, 0));
					// window.draw(cell);
					// break;
				default:
					break;
				}
			}
		}
	}
}

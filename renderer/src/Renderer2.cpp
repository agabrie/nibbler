#include "../include/Renderer2.hpp"

#include <iostream>

// const float SCALE = 60;

Renderer2::Renderer2(int x, int y){
	// this->window = window;
	if(x > y)
		this->scale = sf::VideoMode::getDesktopMode().width/(x+1);
	else
		this->scale = sf::VideoMode::getDesktopMode().height/(y+1);
}
Renderer2::~Renderer2(){
}

// void Renderer2::render(sf::RenderWindow &window, const GameState &state)
// {
// 	window.clear(sf::Color::Black);
// 	map(window, state);
// 	player(window, state);
// 	food(window, state);
// 	window.display();
// }

void Renderer2::playerBody(sf::RenderWindow &window,const PlayerBody &pb)
{
	sf::CircleShape player(scale / 2,6);
	// sf::
	// sf::RectangleShape player(sf::Vector2f(scale,scale));
	// sf::CircleShape player(SCALE / 2);
	sf::Vector2f playerPosition(pb.position());
	playerPosition -= sf::Vector2f(0.5, 0.5);
	// playerPosition.y *= -1;
	playerPosition *= scale;

	player.setPosition(playerPosition);
	// player.setFillColor(sf::Color(50, 250, 50));
			player.setFillColor(sf::Color(200, 200, 200));

	window.draw(player);
}
void Renderer2::renderHead(sf::RenderWindow &window,const PlayerBody &pb)
{
	sf::CircleShape player(scale / 2,3);
	player.setOrigin(scale/2,scale/2);
	// sf::
	// sf::RectangleShape player(sf::Vector2f(scale,scale));
	// sf::CircleShape player(SCALE / 2);
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
	sf::Vector2f playerPosition(pb.position());
	// playerPosition -= sf::Vector2f(0.5, 0.5);
	// playerPosition.y *= -1;
	playerPosition *= scale;

	player.setPosition(playerPosition);
	// player.setFillColor(sf::Color(50, 250, 50));
			player.setFillColor(sf::Color(255, 255, 255));

	window.draw(player);
}
// void Renderer2::player(sf::RenderWindow &window, const GameState &state)
// {
// 	for(auto &part: state.player->body){
// 		playerBody(window,*part);
// 	}
// }

void Renderer2::food(sf::RenderWindow &window, const GameState &state)
{
	// sf::CircleShape food(scale / 2);
	sf::CircleShape food(scale / 2,6);
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
	window.draw(food);
}

void Renderer2::map(sf::RenderWindow &window, const GameState &state)
{
	const Map &map = *state.map;
	const sf::Vector2i &mapSize = map.size();
	Tile tile;
	// sf::RectangleShape cell(sf::Vector2f(scale, scale));
	sf::CircleShape cell(scale / 2,6);
	// sf::CircleShape bomb(SCALE / 2);
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
					window.draw(cell);
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

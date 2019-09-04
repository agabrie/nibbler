#include "../include/Renderer3.hpp"

#include <iostream>

// const float SCALE = 60;
// sf::Texture texture;
// texture.loadFromFile("./block.png");
Renderer3::Renderer3(){
	this->scale = sf::VideoMode::getDesktopMode().height/(sf::VideoMode::getDesktopMode().bitsPerPixel+1);
}
Renderer3::Renderer3(/*sf::RenderWindow &window,*/int x, int y)
// :_window(window)
{
	;
	if(x > y)
		this->scale = sf::VideoMode::getDesktopMode().width/(x+1);
	else
		this->scale = sf::VideoMode::getDesktopMode().height/(y+1);
}
Renderer3::~Renderer3(){
}


void Renderer3::playerBody(sf::RenderWindow &window,const PlayerBody &pb)
{
	// sf::CircleShape player(SCALE / 2);
	sf::RectangleShape player(sf::Vector2f(scale-(scale/10),scale-(scale/10)));
	sf::Texture texture;
	if (!texture.loadFromFile("../renderer/src/Body2.png")){}
	// player.setOutlineThickness(5);
	// player.setOutlineColor(sf::Color(0, 0, 0));
	// sf::CircleShape player(SCALE / 2);
	sf::Vector2f playerPosition(pb.position());
	playerPosition -= sf::Vector2f(0.5, 0.5);
	// playerPosition.y *= -1;
	playerPosition *= scale;

	player.setPosition(playerPosition);
	// player.setFillColor(sf::Color(50, 250, 50));
			// player.setFillColor(sf::Color(50, 175, 255));
		player.setTexture(&texture); // texture is a sf::Texture
		player.setTextureRect(sf::IntRect(0, 0, 32, 32));
	window.draw(player);
}
void Renderer3::renderHead(sf::RenderWindow &window,const PlayerBody &pb)
{
	// sf::CircleShape player(SCALE / 2);
	sf::RectangleShape player(sf::Vector2f(scale-(scale/10),scale-(scale/10)));
	sf::Texture texture;
	// switch(pb.direction){
	// 	case Direction::North:
			texture.loadFromFile("../renderer/src/headup.png");
	// 		break;
	// 	case Direction::South:
	// 		texture.loadFromFile("../renderer/src/headdown.png");
	// 		break;
	// 	case Direction::East:
	// 		texture.loadFromFile("../renderer/src/headright.png");
	// 		break;
	// 	case Direction::West:
	// 		texture.loadFromFile("../renderer/src/headleft.png");
	// 		break;
	// 	default:break;
	// }
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
	// if (!texture.loadFromFile("../renderer/src/headup.png")){}
	// player.setOutlineThickness(5);
	// player.setOutlineColor(sf::Color(0, 0, 0));
	// sf::CircleShape player(SCALE / 2);
	sf::Vector2f playerPosition(pb.position());
	// playerPosition -= sf::Vector2f(0.5, 0.5);
	// playerPosition.y *= -1;
	playerPosition *= scale;

	player.setPosition(playerPosition);
	// player.setFillColor(sf::Color(50, 250, 50));
			// player.setFillColor(sf::Color(50, 175, 255));
		player.setTexture(&texture); // texture is a sf::Texture
		player.setTextureRect(sf::IntRect(0, 0, 32, 32));
	window.draw(player);
}

void Renderer3::food(sf::RenderWindow &window, const GameState &state)
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
	window.draw(food);
}

void Renderer3::map(sf::RenderWindow &window, const GameState &state)
{
	const Map &map = *state.map;
	const sf::Vector2i &mapSize = map.size();
	Tile tile;
	sf::RectangleShape cell(sf::Vector2f(scale-(scale/10), scale-(scale/10)));
	// sf::CircleShape bomb(SCALE / 2);
	// system("pwd");
	sf::Texture texture;
	if (!texture.loadFromFile("../renderer/src/block.png"))
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
				
				// cell.setOutlineThickness(5);
				// cell.setOutlineColor(sf::Color(0, 0, 0));
				switch (tile)
				{
				case Tile::Solid:
					// cell.setFillColor(sf::Color(50, 150, 20));
					cell.setTexture(&texture); // texture is a sf::Texture
					cell.setTextureRect(sf::IntRect(0, 0, 32, 32));
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
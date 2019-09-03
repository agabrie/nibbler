#include "../include/IRenderer.hpp"

#include <iostream>

// const float SCALE = 60;
// sf::Texture texture;
// texture.loadFromFile("./block.png");
IRenderer::IRenderer(){
	this->scale = sf::VideoMode::getDesktopMode().height/(sf::VideoMode::getDesktopMode().bitsPerPixel+1);
}
IRenderer::IRenderer(/*sf::RenderWindow &window,*/int x, int y)
// :_window(window)
{
	;
	if(x > y)
		this->scale = sf::VideoMode::getDesktopMode().width/(x+1);
	else
		this->scale = sf::VideoMode::getDesktopMode().height/(y+1);
}
IRenderer::~IRenderer(){
}

void IRenderer::render(sf::RenderWindow &window, const GameState &state)
{
	window.clear(sf::Color::Black);
	map(window, state);
	player(window, state);
	food(window, state);
	window.display();
}

void IRenderer::playerBody(sf::RenderWindow &window,const PlayerBody &pb)
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

void IRenderer::player(sf::RenderWindow &window, const GameState &state)
{
	for(auto &part: state.player->body){
		playerBody(window,*part);
	}
}

void IRenderer::food(sf::RenderWindow &window, const GameState &state)
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

void IRenderer::map(sf::RenderWindow &window, const GameState &state)
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

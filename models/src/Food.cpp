#include "../include/Food.hpp"

const sf::Vector2f DEFAULT_SPAWN(11.5,11.5);
Food::Food():position(sf::Vector2f(DEFAULT_SPAWN))
{
}
Food::Food(sf::Vector2f place):position(place)
{}
Food::~Food(){

}
void Food::relocate(Map &map){
    // GameState::map;
}
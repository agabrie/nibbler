#include "../include/Food.hpp"
#include <iostream>
const sf::Vector2f DEFAULT_SPAWN(11.5,11.5);
// const sCoordinates DEFAULT_SPAWN(11.5,11.5);

// Food::Food():position(sCoordinates(DEFAULT_SPAWN))
Food::Food():position(sf::Vector2f(DEFAULT_SPAWN))

{
}
// Food::Food(sCoordinates place):position(place)
Food::Food(sf::Vector2f place):position(place)
{}
Food::~Food(){

}
void Food::relocate(Map &map){
    // GameState::map;
    int maxX = map.size().x;
    int maxY = map.size().y;
    // std::cout<<"map limits ("<<maxX<<", "<<maxY<<")\n";
    sf::Vector2f newLocation(0,0);
    // sCoordinates newLocation(0,0);

    int x = (rand()%(maxX-2));
    int y = (rand()%(maxY-2));
    // std::cout<<"Random ints ("<<x<<", "<<y<<")\n";
    newLocation.x = x+1.5;
    newLocation.y = y+1.5;
    // std::cout<<"Location ("<<newLocation.x<<", "<<newLocation.y<<")\n";
    this->position = newLocation;

}
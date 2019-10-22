#include "../include/Food.hpp"
#include <iostream>
const sf::Vector2f DEFAULT_SPAWN(11.5,11.5);
// const sCoordinates DEFAULT_SPAWN(11.5,11.5);

// Food::Food():position(sCoordinates(DEFAULT_SPAWN))
Food::Food(Map &map)
{
    this->relocate(map.size().x, map.size().y);
}
// Food::Food(sCoordinates place):position(place)
Food::Food(sf::Vector2f place)
{
    this->relocate(place.x, place.y);
    // position.x = place.x/2;
    // position.y = place.y/2;
    
}
Food::~Food(){

}
void Food::relocate(int width, int height){
    // GameState::map;
    int maxX = width;
    int maxY = height;
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
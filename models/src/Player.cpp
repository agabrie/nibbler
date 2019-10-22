#include "../include/Player.hpp"
#include "../include/Coordinates.hpp"

#include <iostream>
Player::Player(int width,int height,int level){
    // if(level > 23)
        // level = 1;
    this->level = 1;
    PlayerBody *part = new PlayerBody(sf::Vector2f((width/2)+0.5,(height/2)+0.5));
    // PlayerBody *part = new PlayerBody(sCoordinates(1.5,2.5));
        this->body.push_back(part);
    for(int i = 1; i < level; i++)
        this->extend();
}
void Player::clearPlayer(){
    for(auto &e:this->body){
        delete e;
    }
}
Player::~Player(){
    this->clearPlayer();
    return ;
}
void Player::extend(){
    PlayerBody *lastPart;
    sf::Vector2f newPosition;
    // sCoordinates newPosition;

    lastPart = this->body.back();
    newPosition = checkPosition(lastPart->position(), -(lastPart->direction));
    PlayerBody *newBody = new PlayerBody(newPosition);
    newBody->updateDirection(lastPart->direction);
    this->body.push_back(newBody);
    if(this->level < 39)
        this->level++;
}
void Player::moveAll(Map &map){
    PlayerBody *first = this->body.front();
    Direction next = first->direction;
    int i = -1;
	for(auto &part:this->body){
        i++;
		Direction curr = part->direction;
        if(!partAt(checkPosition(part->position(),curr)))
		    part->move(map);
        else{
            if(!i){
                    std::cout<<"Game Over!\n\tHit a Body Part\n";
                exit(1);
            }
        }
        part->updateDirection(next);
		next = curr;
	}
}

// bool Player::partAt(sCoordinates position){
bool Player::partAt(sf::Vector2f position){

    for(auto &e:this->body){
        if(position == e->position())
            return true;
    }
    return false;
}

// sCoordinates Player::checkPosition(sCoordinates position, int direction){
sf::Vector2f Player::checkPosition(sf::Vector2f position, int direction){
    sf::Vector2f newPosition(0,0);
    // sCoordinates newPosition(0,0);

    switch (direction)
    {
    case Direction::North:
        newPosition.y = -1;
        break;
    case Direction::South:
        newPosition.y = 1;
        break;
    case Direction::West:
        newPosition.x = -1;
        break;
    case Direction::East:
        newPosition.x = 1;
        break;
        default:break;
    }
    return sf::Vector2f(position+newPosition);
    // return sCoordinates(position+newPosition);
}

void Player::debug(){
    std::cout<<"################START###############\n";
    for(auto &part:this->body){
        switch(part->direction)
        {
            case Direction::East:
            std::cout <<"EAST ";
            break;
            case Direction::West:
            std::cout <<"WEST ";
            break;
            case Direction::North:
            std::cout <<"NORTH ";
            break;
            case Direction::South:
            std::cout <<"SOUTH ";
            break;
            default:break;
        }
        std::cout << "Node : ("<<part->position().x<<", "<<part->position().y<<");\n";
    }    
    std::cout<<"#################END################\n\n";
}
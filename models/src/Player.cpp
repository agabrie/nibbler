#include "../include/Player.hpp"
#include <iostream>
Player::Player(){
    PlayerBody *part = new PlayerBody(sf::Vector2f(1.5,2.5));
    // PlayerBody *part2 = new PlayerBody(sf::Vector2f(1.5,1.5));


    this->body.push_back(part);
    // this->extend();
    // this->extend();
    // this->body.push_back(part2);

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
    for(auto &e:this->body){
        // newPosition = e->position();

        lastPart = e;
    }
    switch(lastPart->direction){
        case Direction::North:
            newPosition = sf::Vector2f(0,-1);
            break;
        case Direction::South:
            newPosition = sf::Vector2f(0,+1);
            break;
        case Direction::West:
            newPosition = sf::Vector2f(-1,0);
            break;
        case Direction::East:
            newPosition = sf::Vector2f(+1,0);
            break;
        default:
            break;
    }
    newPosition = lastPart->position() - newPosition;
    std::cout << "Last Node : ("<<lastPart->position().x<<", "<<lastPart->position().y<<") + ";
    switch (lastPart->direction)
    {
    case Direction::North:
        std::cout << "Direction : DOWN  =>\n";    
        break;
    case Direction::South:
        std::cout << "Direction : UP  =>\n";    
        break;
    case Direction::East:
        std::cout << "Direction : LEFT  =>\n";    
        break;
    case Direction::West:
        std::cout << "Direction : RIGHT  =>\n";    
        break;
    default:
        break;
    }
    std::cout << "Estimated Node : ("<<newPosition.x<<", "<<newPosition.y<<");\n";
    // std::cout << "Actual";
    PlayerBody *newBody = new PlayerBody(newPosition);
    std::cout << "Actual Node : ("<<newBody->position().x<<", "<<newBody->position().y<<");\n";
    this->body.push_back(newBody);
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
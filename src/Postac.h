#pragma once
#include "AnimatedSprite.h"

class Postac : public AnimatedSprite
{
    
protected:
    std::map<std::string, std::vector<sf::IntRect>> all_frames;
    std::string state;
    int speed;
public:
    int sila;
    int zycie;
    Postac(std::string filename, std::map<std::string, std::vector<sf::IntRect>> Frames, int Zycie, int Sila, int Speed) : AnimatedSprite(filename, Frames["Down_Stay"])
    {
        this->speed = Speed;
        this->zycie = Zycie;
        this->sila = Sila;
        this->all_frames = Frames;
        this->state = "Down_Stay";
    }
    virtual void choose(std::string State)
    {
        this->state = State;
        this->changes(all_frames[State]);
    }
};
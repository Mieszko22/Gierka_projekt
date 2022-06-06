#pragma once
#include "AnimatedSprite.h"

class Postac : public AnimatedSprite
{
    int zycie;
    int sila;
    std::string state;
    std::map<std::string, std::vector<sf::IntRect>> all_frames;
    
public:
    Postac(std::string filename, std::map<std::string, std::vector<sf::IntRect>> Frames, int Zycie, int Sila) : AnimatedSprite(filename, Frames["Down_Stay"])
    {
        this->zycie = Zycie;
        this->sila = Sila;
        this->all_frames = Frames;
        this->state = "Down_Stay";
    }
    virtual void choose(std::string State)
    {
        try 
        {
            this->state = State;
            this->changes(all_frames[State]);
        }
        catch(std::string q)
        {
            throw "Blad nazwy kierunku";
        }
    }
};
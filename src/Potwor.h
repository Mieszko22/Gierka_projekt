#pragma once
#include "Postac.h"
#include <cmath>
class Potwor : public Postac
{
    int range;
public:
    Potwor(std::string filename, std::map<std::string, std::vector<sf::IntRect>> Frames, int Zycie, int Sila, int Speed, int Range) : Postac(filename, Frames, Zycie, Sila, Speed)
    {
        this->range = Range;
    }
    void follow(sf::FloatRect &data, sf::Time &time)
    {
        sf::FloatRect x = this->getGlobalBounds();
        if(abs(x.left - data.left) < this->range && abs(x.top - data.top) < this->range)
        {
            if(x.left > data.left)
            {
                this->setPosition(x.left - this->speed*time.asSeconds(), x.top);
                if(this->state != "Left")
                {
                    this->choose("Left");
                }
            }
            else if(x.left < data.left)
            {
                this->setPosition(x.left + this->speed*time.asSeconds(), x.top);
                if(this->state != "Right")
                {
                    this->choose("Right");
                }
            }
            else if(x.top > data.top)
            {
                this->setPosition(x.left, x.top - this->speed*time.asSeconds());
                if(this->state != "Up")
                {
                    this->choose("Up");
                }
            }
            else if(x.top < data.top)
            {
                this->setPosition(x.left, x.top + this->speed*time.asSeconds());
                if(this->state != "Down")
                {
                    this->choose("Down");
                }
            }
        }
        else
        {
            if(*--this->state.end() != 'y')
            {
                this->choose(this->state + "_Stay");
            }
        }
    }
};
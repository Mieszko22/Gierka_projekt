#pragma once
#include "Postac.h"
#include "Walk.h"

class Bohater : public Postac
{
    int level;
public:
    Bohater(std::string filename, std::map<std::string, std::vector<sf::IntRect>> Frames, int Zycie, int Sila, int Speed) : Postac(filename, Frames, Zycie, Sila, Speed)
    {

    }
    void ruch(sf::Keyboard::Key &wsad, sf::Time &time, std::vector<Walk> *Background)
    {
        sf::FloatRect x = this->getGlobalBounds();
        switch (wsad)
        {
        case sf::Keyboard::W:
        {
            this->setPosition(x.left, x.top - this->speed*time.asSeconds());
            sf::FloatRect Reaction = this->getGlobalBounds();
            bool Flag = true;
            for(auto &x : *Background)
            {
                if(x.allow && Reaction.intersects(x.getGlobalBounds()))
                {
                    Flag = false;
                    break;
                }
            }
            if(Flag)
            {
                this->setPosition(x.left, x.top + this->speed*time.asSeconds());
            }
            if(this->state != "Up")
            {
                this->choose("Up");
            }
            break;
        }
        case sf::Keyboard::S:
            this->setPosition(x.left, x.top + this->speed*time.asSeconds());
            if(this->state != "Down")
            {
                this->choose("Down");
            }
            break;
        case sf::Keyboard::A:
            this->setPosition(x.left - this->speed*time.asSeconds(), x.top);
            if(this->state != "Left")
            {
                this->choose("Left");
            }
            break;
        case sf::Keyboard::D:
            this->setPosition(x.left + this->speed*time.asSeconds(), x.top);
            if(this->state != "Right")
            {
                this->choose("Right");
            }
            break;
        default:
            break;
        }
    }
    void stop()
    {
        if(*--this->state.end() != 'y')
        {
            this->choose(this->state + "_Stay");
        }
    }
};








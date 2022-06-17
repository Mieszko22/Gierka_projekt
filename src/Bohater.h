#pragma once
#include "Postac.h"
#include "Walk.h"

class Bohater : public Postac
{
public:
    int Max_life;
    Bohater(std::string filename, std::map<std::string, std::vector<sf::IntRect>> Frames, int Zycie, int Sila, int Speed) : Postac(filename, Frames, Zycie, Sila, Speed)
    {
        this->Max_life = Zycie;
    }
    void ruch(sf::Keyboard::Key &wsad, sf::Time &time, std::vector<Walk> *Background)
    {
        sf::FloatRect X = this->getGlobalBounds();
        switch (wsad)
        {
        case sf::Keyboard::W:
        {
            this->setPosition(X.left, X.top - this->speed*time.asSeconds());
            sf::FloatRect y = this->getGlobalBounds();
            sf::FloatRect Reaction(y.left + 15, y.top + 30, 1, 1);
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
                this->setPosition(X.left, X.top);
            }
            if(this->state != "Up")
            {
                this->choose("Up");
            }
            break;
        }
        case sf::Keyboard::S:
        {
            this->setPosition(X.left, X.top + this->speed*time.asSeconds());
            sf::FloatRect y = this->getGlobalBounds();
            sf::FloatRect Reaction(y.left + 15, y.top + 30, 1, 1);
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
                this->setPosition(X.left, X.top);
            }
            if(this->state != "Down")
            {
                this->choose("Down");
            }
            break;
        }
        case sf::Keyboard::A:
        {
            this->setPosition(X.left - this->speed*time.asSeconds(), X.top);
            sf::FloatRect y = this->getGlobalBounds();
            sf::FloatRect Reaction(y.left + 15, y.top + 30, 1, 1);
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
                this->setPosition(X.left, X.top);
            }
            if(this->state != "Left")
            {
                this->choose("Left");
            }
            break;
        }
        case sf::Keyboard::D:
        {
            this->setPosition(X.left + this->speed*time.asSeconds(), X.top);
            sf::FloatRect y = this->getGlobalBounds();
            sf::FloatRect Reaction(y.left + 15, y.top + 30, 1, 1);
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
                this->setPosition(X.left, X.top);
            }
            if(this->state != "Right")
            {
                this->choose("Right");
            }
            break;
        }
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








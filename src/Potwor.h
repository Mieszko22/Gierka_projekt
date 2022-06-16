#pragma once
#include "Bohater.h"
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
    bool fight(Bohater *Hero, sf::RenderWindow &window)
    {
        if(this->getGlobalBounds().intersects(Hero->getGlobalBounds()))
        {
            sf::Texture tekstura, tekstura2, tekstura3;
            tekstura.loadFromFile("lpc_home_cup.png");
            tekstura2.loadFromFile("soldier.png");
            sf::Sprite Potwor2(this->texture, {0, 70, 32, 28});
            // sf::Sprite Potwor2(this->texture, this->frames[0]);
            sf::Sprite Mapa(tekstura);
            sf::Sprite Hero2(tekstura2, {16,143,31,47});
            Hero2.setPosition(150,200);
            Potwor2.setPosition(350,200);
            while(window.isOpen())
            {
                sf::Event event;
                while(window.pollEvent(event))
                {
                    if(event.type == sf::Event::Closed)
                        window.close();
                    if(event.type == sf::Event::KeyPressed)
                    {
                        if(event.key.code == sf::Keyboard::F)
                        {
                            this->zycie -= Hero->sila;
                            Hero->zycie -= this->sila;
                        }
                    }
                }
                if(Hero->zycie <= 0)
                {
                    window.close();
                }
                if(this->zycie <= 0)
                {
                    break;
                }
                window.clear(sf::Color::Black);
                window.draw(Mapa);
                window.draw(Hero2);
                window.draw(Potwor2);
                window.display();
            }
            window.clear(sf::Color::Black);
            return true;
            
        }
        return false;
    }
};
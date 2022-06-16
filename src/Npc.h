#pragma once
#include "Bohater.h"

class Npc : public sf::Sprite
{
    sf::Texture texture;
    sf::Sprite speak;
    
public:
    bool the_end;
    Npc(sf::Texture &texture2, sf::IntRect A, bool the_end2, std::string filename) : Sprite(texture2, A)
    {
        if(!texture.loadFromFile(filename))
        {
           throw "Brak tekstury";
        }
        speak.setTexture(texture);
        this->the_end = the_end2;
    }
    void Speak(Bohater *Hero, sf::RenderWindow &window)
    {
        if(this->getGlobalBounds().intersects(Hero->getGlobalBounds()))
        {
            speak.setPosition(200,200);
            window.draw(speak);
        }
    }

};
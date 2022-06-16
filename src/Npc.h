#pragma once
#include "Bohater.h"

class Npc : public sf::Sprite
{
    sf::Sprite speak;
    
public:
    bool the_end;
    Npc(sf::Texture &texture2, sf::IntRect A, bool the_end2, sf::Texture &texture3) : Sprite(texture2, A)
    {
        speak.setTexture(texture3);
        this->the_end = the_end2;
    }
    void Speak(Bohater *Hero, sf::RenderWindow &window)
    {
        if(this->getGlobalBounds().intersects(Hero->getGlobalBounds()))
        {
            speak.setPosition(50,45);
            window.draw(speak);
        }
    }

};
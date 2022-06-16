#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class AnimatedSprite : public sf::Sprite
{
    float frame;
protected:
    std::vector<sf::IntRect> frames;
    sf::Texture texture;
    virtual void changes(std::vector<sf::IntRect> new_frames)
    {
        this->frames = new_frames;
        this->frame = 0;
    }
public:
    AnimatedSprite(std::string filename, std::vector<sf::IntRect> Frames)
    {
        if(!texture.loadFromFile(filename))
        {
           throw "Brak tekstury";
        }
        this->setTexture( texture );
        this->setTextureRect( Frames[0] );
        this->frames = Frames;
        this->frame = 0;
    }
    virtual ~AnimatedSprite(){}

    virtual void animate(const sf::Time &czas)
    {
        frame += czas.asSeconds() * 60.0f;
        while ( frame > 10 * frames.size() ) {
            frame -= 10 * frames.size() ;
        }
        this->setTextureRect( frames[frame/10] );
    }
   
};


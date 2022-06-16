#pragma once
#include <SFML/Graphics.hpp>

class Walk : public sf::Sprite
{
public:
    bool allow, is_door, heal;
    std::string where;
    Walk()
    {
        this->is_door = false;
        this->heal = false;
    }
};
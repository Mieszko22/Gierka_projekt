#pragma once
#include <SFML/Graphics.hpp>

class Walk : public sf::Sprite
{
public:
    bool allow, is_door;
    std::string where;
    Walk()
    {
        this->is_door = false;
    }
};
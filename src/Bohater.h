#pragma once
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Postac.h"


class Bohater : public Postac
{
    
public:
    Bohater(std::string filename, std::map<std::string, std::vector<sf::IntRect>> Frames, int Zycie, int Sila) : Postac(filename, Frames, Zycie, Sila)
    {

    }
};








#pragma once
#include "Walk.h"
#include "Bohater.h"

class Locations
{
    std::map<std::string, std::vector<Walk>> Levels;
    std::map<std::string, sf::Texture> Graphics;

public:
    std::vector<Walk> *Background;
    Locations(Bohater *Hero)
    {
        Graphics.insert({"Water", sf::Texture()});
        if (!this->Graphics["Water"].loadFromFile("water.png"))
        {
            throw "Brak tekstury";
        }
        Graphics.insert({"Dirt", sf::Texture()});
        if (!this->Graphics["Dirt"].loadFromFile("dirt2.png"))
        {
            throw "Brak tekstury";
        }
        Graphics.insert({"Victoria", sf::Texture()});
        if (!this->Graphics["Victoria"].loadFromFile("victoria.png"))
        {
            throw "Brak tekstury";
        }
        Graphics.insert({"Inside", sf::Texture()});
        if (!this->Graphics["Inside"].loadFromFile("inside.png"))
        {
            throw "Brak tekstury";
        }
        Graphics.insert({"Grass", sf::Texture()});
        if (!this->Graphics["Grass"].loadFromFile("grass.png"))
        {
            throw "Brak tekstury";
        }
        Graphics.insert({"House", sf::Texture()});
        if (!this->Graphics["House"].loadFromFile("house.png"))
        {
            throw "Brak tekstury";
        }
        this->Levels.insert({"House", std::vector<Walk>{}});
        this->Levels.insert({"Outdoor", std::vector<Walk>{}});
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                Walk temp; //(Inside, {0,128,32,32});
                temp.allow = true;
                temp.setTexture(this->Graphics["Inside"]);
                temp.setTextureRect({0, 128, 32, 32});
                temp.setPosition(100 + i * 32, 100 + j * 32);
                this->Levels["House"].push_back(temp);
            }
        }
        for (int i = 0; i < 5; i++)
        {
            Walk temp;
            temp.allow = false;
            temp.setTexture(this->Graphics["Inside"]);
            temp.setTextureRect({0, 178, 32, 62});
            temp.setPosition(100 + i * 32, 38);
            this->Levels["House"].push_back(temp);
        }
        {
            Walk temp;
            temp.allow = false;
            temp.is_door = true;
            temp.where = "Outdoor";
            temp.setTexture(this->Graphics["Inside"]);
            temp.setTextureRect({256, 16, 32, 47});
            temp.setPosition(164, 53);
            this->Levels["House"].push_back(temp);
        }
        this->Travel("House", Hero);
    }
    void Travel(std::string Place, Bohater *Hero)
    {
        this->Background = &this->Levels[Place];
        if(Place == "House")
        {
            Hero->setPosition(164,100);
        }
        else if(Place == "Outdoor")
        {
            Hero->setPosition(300,300);
        }
    
    }
};
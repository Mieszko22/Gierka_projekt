#pragma once
#include "Walk.h"
#include "Bohater.h"
#include "Potwor.h"
#include "Npc.h"

class Locations
{
    std::map<std::string, std::vector<Walk>> Levels;
    std::map<std::string, std::vector<Potwor>> monsters;
    std::map<std::string, std::vector<Npc>> npc;
    
    std::map<std::string, sf::Texture> Graphics;

public:
    std::vector<Walk> *Background;
    std::vector<Potwor> *Monster;
    std::vector<Npc> *NPC;
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
        Graphics.insert({"Castlefloors", sf::Texture()});
        if (!this->Graphics["Castlefloors"].loadFromFile("castlefloors_outside.png"))
        {
            throw "Brak tekstury";
        }
        Graphics.insert({"Princess", sf::Texture()});
        if (!this->Graphics["Princess"].loadFromFile("princess.png"))
        {
            throw "Brak tekstury";
        }
        Graphics.insert({"Soldier", sf::Texture()});
        if (!this->Graphics["Soldier"].loadFromFile("soldier_altcolor.png"))
        {
            throw "Brak tekstury";
        }
        Graphics.insert({"Mapa", sf::Texture()});
        if (!this->Graphics["Mapa"].loadFromFile("lpc_home_cup.png"))
        {
            throw "Brak tekstury";
        }
        Graphics.insert({"Bat", sf::Texture()});
        if (!this->Graphics["Bat"].loadFromFile("bat.png"))
        {
            throw "Brak tekstury";
        }
        Graphics.insert({"Eye", sf::Texture()});
        if (!this->Graphics["Eye"].loadFromFile("eyeball.png"))
        {
            throw "Brak tekstury";
        }
        Graphics.insert({"Speak1", sf::Texture()});
        if (!this->Graphics["Speak1"].loadFromFile("Speak1.png"))
        {
            throw "Brak tekstury";
        }
        Graphics.insert({"Speak2", sf::Texture()});
        if (!this->Graphics["Speak2"].loadFromFile("Speak2.png"))
        {
            throw "Brak tekstury";
        }
        this->Levels.insert({"House", std::vector<Walk>{}});
        this->Levels.insert({"Outdoor", std::vector<Walk>{}});
        this->monsters.insert({"Outdoor", std::vector<Potwor>{}});
        this->Levels.insert({"Mapa_walki", std::vector<Walk>{}});
        this->npc.insert({"Outdoor", std::vector<Npc>{}});
        this->npc.insert({"House", std::vector<Npc>{}});
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                Walk temp; 
                temp.allow = false;
                temp.setTexture(this->Graphics["Castlefloors"]);
                temp.setTextureRect({32, 96, 32, 32});
                temp.setPosition(106 + i * 32, 169 + j * 32);
                this->Levels["House"].push_back(temp);
            }
        }
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 6; j++)
            {   
                Walk temp; 
                temp.allow = true;
                if( i == 0 && j == 4)
                {
                    temp.allow = false;
                    temp.setTexture(this->Graphics["Inside"]);
                    temp.setTextureRect({0, 128, 32, 32});
                    temp.setPosition(138 + i * 32, 169 + j * 32);
                    this->Levels["House"].push_back(temp);
                }
                else if( i == 0 && j == 5)
                {
                    temp.allow = false;
                    temp.setTexture(this->Graphics["Inside"]);
                    temp.setTextureRect({0, 128, 32, 32});
                    temp.setPosition(138 + i * 32, 169 + j * 32);
                    this->Levels["House"].push_back(temp);
                }
                else
                {
                    temp.setTexture(this->Graphics["Inside"]);
                    temp.setTextureRect({0, 128, 32, 32});
                    temp.setPosition(138 + i * 32, 169 + j * 32);
                    this->Levels["House"].push_back(temp);
                }
            }
        }
        for (int i = 0; i < 9; i++)
        {
            Walk temp;
            temp.allow = false;
            temp.setTexture(this->Graphics["Inside"]);
            temp.setTextureRect({0, 178, 32, 62});
            temp.setPosition(106 + i * 32, 107);
            this->Levels["House"].push_back(temp);
        }
        {
            Walk temp;
            temp.allow = false;
            temp.is_door = true;
            temp.where = "Outdoor";
            temp.setTexture(this->Graphics["Inside"]);
            temp.setTextureRect({256, 16, 32, 47});
            temp.setPosition(232, 122);
            this->Levels["House"].push_back(temp);
        }
        {
            Walk temp;
            temp.allow = false;
            temp.setTexture(this->Graphics["Victoria"]);
            temp.setTextureRect({72, 14, 47, 81});
            temp.setPosition(138, 280);
            this->Levels["House"].push_back(temp);
        }
        {
            Walk temp;
            temp.heal = true;
            temp.allow = false;
            temp.setTexture(this->Graphics["Victoria"]);
            temp.setTextureRect({133, 134, 21, 19});
            temp.setPosition(330, 329);
            this->Levels["House"].push_back(temp);
        }
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                Walk temp; 
                temp.allow = false;
                temp.setTexture(this->Graphics["Water"]);
                temp.setTextureRect({0, 160, 32, 32});
                temp.setPosition(0 + i * 32, 0 + j * 32);
                this->Levels["Outdoor"].push_back(temp);
            }
        }
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                Walk temp; 
                temp.allow = true;
                temp.setTexture(this->Graphics["Dirt"]);
                temp.setTextureRect({0, 160, 32, 32});
                temp.setPosition(0 + i * 32, 320 + j * 32);
                this->Levels["Outdoor"].push_back(temp);
            }
        }
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                Walk temp; 
                temp.allow = false;
                temp.setTexture(this->Graphics["Water"]);
                temp.setTextureRect({0, 160, 32, 32});
                temp.setPosition(0 + i * 32, 416 + j * 32);
                this->Levels["Outdoor"].push_back(temp);
            }
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                Walk temp; 
                temp.allow = true;
                temp.setTexture(this->Graphics["Dirt"]);
                temp.setTextureRect({0, 160, 32, 32});
                temp.setPosition(224 + i * 32, 0 + j * 32);
                this->Levels["Outdoor"].push_back(temp);
            }
        }
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                Walk temp; 
                temp.allow = true;
                temp.setTexture(this->Graphics["Dirt"]);
                temp.setTextureRect({0, 160, 32, 32});
                temp.setPosition(352 + i * 32, 0 + j * 32);
                this->Levels["Outdoor"].push_back(temp);
            }
        }
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                Walk temp; 
                temp.allow = true;
                temp.setTexture(this->Graphics["Water"]);
                temp.setTextureRect({0, 160, 32, 32});
                temp.setPosition(352 + i * 32, 128 + j * 32);
                this->Levels["Outdoor"].push_back(temp);
            }
        }
        {
            Walk temp;
            temp.allow = false;
            temp.setTexture(this->Graphics["House"]);
            temp.setTextureRect({0, 0, 95, 95});
            temp.setPosition(32, 225);
            this->Levels["Outdoor"].push_back(temp);
        }
        {
            Walk temp;
            temp.allow = false;
            temp.setTexture(this->Graphics["House"]);
            temp.setTextureRect({0, 96, 95, 95});
            temp.setPosition(32, 130);
            this->Levels["Outdoor"].push_back(temp);
        }
        {
            Walk temp;
            temp.allow = false;
            temp.is_door = true;
            temp.where = "House";
            temp.setTexture(this->Graphics["House"]);
            temp.setTextureRect({160, 0, 32, 48});
            temp.setPosition(47, 272);
            this->Levels["Outdoor"].push_back(temp);
        }
        {
            Npc temp(this->Graphics["Princess"],{18, 141, 27, 49}, true, this->Graphics["Speak2.png"]);
            temp.setPosition(450, 30);
            this->npc["Outdoor"].push_back(temp);
        }
        {
            Npc temp(this->Graphics["Soldier"],{18, 141, 27, 49}, true, this->Graphics["Speak1.png"]);
            temp.setPosition(200, 130);
            this->npc["House"].push_back(temp);
        }
        // {
        //     Walk temp;
        //     temp.allow = false;
        //     temp.setTexture(this->Graphics["Mapa"]);
        //     temp.setTextureRect({0, 0, 500, 500});
        //     temp.setPosition(0, 0);
        //     this->Levels["Mapa_walki"].push_back(temp);
        // }
        {
            std::map<std::string, std::vector<sf::IntRect>> Label1;
            std::string Direkt[4] = {"Up", "Left", "Down", "Right"};
            for(int i = 0; i < 4; i++)
            {
                Label1.insert({Direkt[i] + "_Stay", {{0, 4 + i*32, 32, 28}}});
                Label1.insert({Direkt[i], std::vector<sf::IntRect>(3)});
                for(int j = 0; j < 3; j++)
                {
                    Label1[Direkt[i]][j] = {0 + j*32, 4 + i*32, 32, 28};
                }
            } 
            Potwor temp("bat.png", Label1, 30, 9, 10, 100);
            temp.setTexture(this->Graphics["Bat"]);
            temp.setPosition(304,200);
            this->monsters["Outdoor"].push_back(temp);
        }
        {
            std::map<std::string, std::vector<sf::IntRect>> Label1;
            std::string Direkt[4] = {"Up", "Left", "Down", "Right"};
            for(int i = 0; i < 4; i++)
            {
                Label1.insert({Direkt[i] + "_Stay", {{0, i*38, 32, 38}}});
                Label1.insert({Direkt[i], std::vector<sf::IntRect>(3)});
                for(int j = 0; j < 3; j++)
                {
                    Label1[Direkt[i]][j] = {j*32, i*38, 32, 38};
                }
            } 
            Potwor temp("eyeball.png", Label1, 30, 9, 10, 100);
            temp.setTexture(this->Graphics["Eye"]);
            temp.setPosition(400,30);
            this->monsters["Outdoor"].push_back(temp);
        }
        this->Travel("House", Hero);

    }
    void Travel(std::string Place, Bohater *Hero)
    {
        this->Background = &this->Levels[Place];
        this->Monster = &this->monsters[Place];
        this->NPC = &this->npc[Place];
        if(Place == "House")
        {
            Hero->setPosition(232,169);
        }
        else if(Place == "Outdoor")
        {
            Hero->setPosition(47,332);
        }
        // else if(Place == "Mapa_walki")
        // {
        //     Hero->setPosition(305,300);
        // }
    }
};
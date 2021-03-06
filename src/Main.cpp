#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Locations.h"
#include "Potwor.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(500,500),"Kolos");
    std::map<std::string, std::vector<sf::IntRect>> Label1;
    std::string Direkt[4] = {"Up", "Left", "Down", "Right"};
    for(int i = 0; i < 4; i++)
    {
        Label1.insert({Direkt[i] + "_Stay", {{16, 15 + i*64, 31, 47}}});
        Label1.insert({Direkt[i], std::vector<sf::IntRect>(8)});
        for(int j = 0; j < 8; j++)
        {
            Label1[Direkt[i]][j] = {80 + j*64, 15 + i*64, 31, 47};
        }
    }
    Bohater *Hero = new Bohater("soldier.png", Label1, 10, 10, 2000);
    Locations Map(Hero);
    Hero->setPosition(185,300);
    sf::Clock clock;
    while(window.isOpen())
    {
        sf::Time time = clock.restart();
        sf::Event event;
        bool is_move = false;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed)
            {
                Hero->ruch(event.key.code, time, Map.Background);
                is_move = true;
                if(event.key.code == sf::Keyboard::Q)
                {
                    for(auto &x : *Map.Background)
                    {
                        sf::FloatRect Reaction = Hero->getGlobalBounds();
                        if(x.is_door && Reaction.intersects(x.getGlobalBounds()))
                        {
                            Map.Travel(x.where, Hero);
                            break;
                        }
                        if(x.heal && Reaction.intersects(x.getGlobalBounds()))
                        {
                            Hero->zycie = Hero->Max_life;
                        }
                    }
                    for(auto &X : *Map.NPC)
                    {
                        sf::FloatRect Reaction = Hero->getGlobalBounds();
                        if(X.the_end && Reaction.intersects(X.getGlobalBounds()))
                        {
                            window.close();
                        }
                    }
                }
            }
            else if(!is_move)
            {
                Hero->stop();
            }
        }
        window.clear(sf::Color::Black);
        for(auto &X : *Map.Background)
        {
            window.draw(X);
        }
        for(auto &X : *Map.NPC)
        {
            window.draw(X);
        }
        Hero->animate(time);
        window.draw(*Hero);
        for(auto &X : *Map.NPC)
        {
            X.Speak(Hero, window);
        }
        auto temp = Hero->getGlobalBounds();
        int i = 0;
        for(auto &X : *Map.Monster)
        {
            window.draw(X);
            X.animate(time);
            X.follow(temp,time);
            if(X.fight(Hero, window))
            {
                Map.Monster->erase(Map.Monster->begin()+i);
                break;
            }
            i++;
        }

        window.display();
    }
    return 0;
}

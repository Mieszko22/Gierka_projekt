#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include "bohater.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000,1000),"Kolos");
    std::vector<std::unique_ptr<Postac>> Characters;
    std::map<std::string, std::vector<sf::IntRect>> Label;
    std::string Direkt[4] = {"Up", "Left", "Down", "Right"};
    // Label.insert("Up_Stay", {{16,15,31,47}});
    // Label.insert("Left_Stay", {{16,79,31,47}});
    // Label.insert("Down_Stay", {{16,143,31,47}});
    // Label.insert({"Right_Stay", {{16,207,31,47}}});
    for(int i = 0; i < 4; i++)
    {
        Label.insert({Direkt[i] + "_Stay", {{16, 15 + i*64, 31, 47}}});
        Label.insert({Direkt[i], std::vector<sf::IntRect>(8)});
        for(int j = 0; j < 8; j++)
        {
            Label[Direkt[i]][j] = {80 + j*64, 15 + i*64, 31, 47};
        }
    }
    Characters.push_back(std::unique_ptr<Postac>(new Postac("soldier.png", Label, 10, 10)));
    Characters[0]->setPosition(100, 100);
    sf::Clock clock;
    while(window.isOpen())
    {
        sf::Time time = clock.restart();
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
         }
        window.clear(sf::Color::Black);
        for(auto &Made : Characters)
        {
            Made->animate(time);
            window.draw(*Made);

        }
        window.display();
    }
    return 0;
}

#include <SFML/Graphics.hpp>
#include <animatedsprite.h>
#include <iostream>
#include "localuser.h"
#include "drawbuffer.h"
#include "map.h"

int main()
{
    std::cout<<"BOMB!!!"<<std::endl;
    LocalUser user;
    Tile tile1(0,"tile2.png",false);
    Tile tile2(1,"tile1.png",true);
    Map map;
    map.setTextureSize(tile1.size());
    map.loadFromFile("map.map");
    map.setTile(tile1);
    map.setTile(tile2);

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }

        DrawBuffer::add(&map,-1000);
        user.update();
        window.clear();
        DrawBuffer::drawOn(window);
        window.display();
    }

    return 0;
}

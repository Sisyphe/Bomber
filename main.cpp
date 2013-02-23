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
    sf::Image img;
    img.loadFromFile("tile2.png");
    img.createMaskFromColor(img.getPixel(0,0));
    sf::Texture tex1,tex2;
    tex1.loadFromFile("tile1.png");
    tex2.loadFromImage(img);
    Map map;
    map.setTextureSize(tex1.getSize().x);
    map.loadFromFile("map.map");
    map.setTexture(0,tex2);
    map.setTexture(1,tex1);

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

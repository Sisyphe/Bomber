#include "localuser.h"
#include <iostream>
#include "collision_manager.h"

LocalUser::LocalUser()
{
    sf::Image img;
    img.loadFromFile("cloclo.png");
    img.createMaskFromColor(img.getPixel(0,0));

    m_character.loadFromImage(img,4,4);
    m_character.addAnimRow(0,"walk_back");
    m_character.addAnimRow(1,"walk_right");
    m_character.addAnimRow(2,"walk_front");
    m_character.addAnimRow(3,"walk_left");
    m_character.play("walk_right");
}

void LocalUser::update()
{
    sf::Vector2f offset(0,0);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) offset.x-=1;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) offset.y-=1;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) offset.x+=1;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) offset.y+=1;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) m_character.setBomb(m_character.getPosition());

    if(offset!=sf::Vector2f(0,0) && (offset.x==0 || offset.y==0))
    {
        sf::Vector2f t_move=offset*m_character.speed();
        if(CollisionManager::allowMove(m_character,t_move))
        {
            m_character.move(t_move);
        }

        if(offset.x!=0 && offset.y==0)
        {
            if(offset.x<0) m_character.play("walk_left");
            else m_character.play("walk_right");

        }
        if(offset.y!=0 && offset.x==0)
        {
            if(offset.y<0) m_character.play("walk_back");
            else m_character.play("walk_front");

        }
    }
    else m_character.stop();

    m_character.update();
}

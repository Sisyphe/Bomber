#include "bomb.h"
#include <iostream>

Bomb::Bomb()
{
    sf::Image img;
    img.loadFromFile("bomb.png");
    img.createMaskFromColor(img.getPixel(0,0));
    loadFromImage(img,1,1);
    m_countdown=2;
    m_is_triggered=false;
    m_is_detonated=false;
    m_is_destroyed=false;
}

void Bomb::trigger()
{
    m_is_triggered=true;
    m_remaining_time=m_countdown;
    m_timer.restart();
}

float Bomb::countdown()
{
    return m_countdown;
}

void Bomb::update()
{
    if(m_is_triggered)
    {
        m_remaining_time=m_countdown-m_timer.getElapsedTime().asSeconds();
        if(m_remaining_time<=0)
        {
            if(!m_is_detonated) detonate();
            else m_is_destroyed=true;
        }
    }
}

bool Bomb::isDestroyed()
{
    return m_is_destroyed;
}

void Bomb::detonate()
{
    m_is_detonated=true;
    sf::Image img;
    img.loadFromFile("explosion.png");
    img.createMaskFromColor(img.getPixel(0,0));
    loadFromImage(img,4,4,1,16);
    addAnimRow(0,"explosion");
    play("explosion",32);
    m_timer.restart();
    m_countdown=0.5;
}

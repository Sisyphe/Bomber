#include "character.h"
#include "drawbuffer.h"
#include <iostream>

Character::Character()
{
    m_speed=1;
    m_can_drop_bomb=true;
    m_reload_time=1;
}

float Character::speed() const
{
    return m_speed;
}

void Character::setBomb(const sf::Vector2f &n_pos)
{
    if(m_can_drop_bomb)
    {
        Bomb* bomb=new Bomb;
        m_bombs.push_back(bomb);
        bomb->setPosition(n_pos);
        bomb->trigger();
        m_can_drop_bomb=false;
        m_timer.restart();
    }
}

void Character::update()
{
    std::list<Bomb*>::iterator it=m_bombs.begin();
    while(it!=m_bombs.end())
    {
        (*it)->update();
        if((*it)->isDestroyed())
        {
            delete *it;
            m_bombs.erase(it++);
        }
        else
        {
            DrawBuffer::add(*it,(*it)->getPosition().y);
            ++it;
        }
    }
    if(m_timer.getElapsedTime().asSeconds()>=m_reload_time) m_can_drop_bomb=true;
    DrawBuffer::add(this,getPosition().y);
}

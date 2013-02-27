#include "character.h"
#include "drawbuffer.h"
#include <anim.h>
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
            DrawBuffer::add(*it,(*it)->getBounds().top+(*it)->getBounds().height);
            ++it;
        }
    }
    if(m_timer.getElapsedTime().asSeconds()>=m_reload_time) m_can_drop_bomb=true;
    DrawBuffer::add(this,getBounds().top+getBounds().height);
}

sf::FloatRect Character::getBounds() const
{
    sf::FloatRect bounds=AnimatedSprite::getBounds();

    float new_height=bounds.height/4;
    bounds.top+=bounds.height-new_height;
    bounds.height=new_height;

    float new_width=bounds.width/1.5;
    bounds.left+=(bounds.width-new_width)/2;
    bounds.width=new_width;

    return bounds;
}

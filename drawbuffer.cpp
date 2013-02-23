#include "drawbuffer.h"

std::multimap<int,sf::Drawable*> DrawBuffer::m_drawables;

void DrawBuffer::add(sf::Drawable* n_drawable,float z)
{
    m_drawables.insert(std::pair<int,sf::Drawable*>(z,n_drawable));
}

void DrawBuffer::drawOn(sf::RenderTarget& target)
{
    std::multimap<int,sf::Drawable*>::iterator it;
    for(it=m_drawables.begin();it!=m_drawables.end();++it)
    {
        target.draw(*((*it).second));
    }
    m_drawables.clear();
}

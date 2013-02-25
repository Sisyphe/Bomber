#ifndef DRAWBUFFER_H
#define DRAWBUFFER_H

#include <SFML/Graphics.hpp>
#include <map>

class DrawBuffer: public sf::Drawable
{
    public:
        static void add(sf::Drawable* n_drawable,float z);
        static void drawOn(sf::RenderTarget& target);

    protected:
        static std::multimap<int,sf::Drawable*> m_drawables;
};

#endif // DRAWBUFFER_H

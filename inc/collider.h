#ifndef COLLIDER_H
#define COLLIDER_H

#include <SFML/Graphics.hpp>

class Collider
{
    public:

        virtual sf::FloatRect getBounds() const=0;
};

#endif // COLLIDER_H

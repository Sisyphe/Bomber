#include "layer.h"
#include <iostream>

Layer::Layer()
{
}

Layer::~Layer()
{
}

void Layer::draw(sf::RenderTarget& Target) const
{
    // Let the derived class render the object geometry
    for( itFrame i = begin() ;i!=end();i++)
        Target.draw(*(*i));
}

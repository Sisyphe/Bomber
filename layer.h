#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include <SFML/Graphics.hpp>

typedef std::vector<sf::Drawable*> FrameSet;
typedef FrameSet::const_iterator itFrame;

/*
*	Petite classe simple qui gère le système de couche de drawable.
*	Elle a la même utilisation que std::vector, l'élément à l'indice 0 est le premier affiché.
*/
class Layer :
    public sf::Drawable, public FrameSet
{
 public :
    //!Même constructeur que sf::Drawable
    Layer();

    virtual ~Layer();
protected :
    virtual void draw(sf::RenderTarget& Target) const;
};

#endif

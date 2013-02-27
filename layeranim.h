#ifndef LAYERANIM_H
#define LAYERANIM_H

#include "anim.h"
#include "layer.h"

/*
*	Animation où chaque frame est représenté par une couche de Layer.
*/
class LayerAnim :
    public Anim, public Layer
{
public:
    LayerAnim(void);

    //!Retourne le nombre de frame de l'animation
    virtual unsigned int getSize() const;

protected:
    virtual void Render(sf::RenderTarget& Target) const;
};

#endif

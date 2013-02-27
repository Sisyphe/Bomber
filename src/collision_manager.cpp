#include "collision_manager.h"
#include <iostream>
#include <math.h>

Map const* CollisionManager::m_map=0;
std::vector<sf::Sprite*> CollisionManager::m_colliders;

void CollisionManager::setMap(const Map& map)
{
    m_map=&map;
}

void CollisionManager::addCollider(sf::Sprite& n_collider)
{
    m_colliders.push_back(&n_collider);
}

bool CollisionManager::allowMove(const Collider& n_collider, sf::Vector2f n_move)
{
    if(m_map)
    {
        sf::FloatRect bounds=n_collider.getBounds();
        bounds.left+=n_move.x;
        bounds.top+=n_move.y;
        int size=m_map->tileSize();
        sf::Vector2f dest=sf::Vector2f(bounds.left,bounds.top);
        std::cout<<bounds.left<<";"<<bounds.top<<";"<<bounds.width<<";"<<bounds.height<<std::endl;
        std::cout<<"("<<dest.x/size<<";"<<dest.y/size<<")"<<std::endl;

        for(int i=0;(i-1)*size<bounds.width;++i)
        {
            for(int j=0;(j-1)*size<bounds.height;++j)
            {
                int x=i+floor(dest.x/size);
                int y=j+floor(dest.y/size);
                std::cout<<"["<<i<<";"<<j<<"] "<<"["<<x<<";"<<y<<"]"<<std::endl;
                if(m_map->isTileBlocking(x,y,bounds))
                {
                    return false;
                }
            }
        }
    }
    return true;
}

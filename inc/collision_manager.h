#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "map.h"
#include "collider.h"

class CollisionManager
{
    public:

        static void setMap(const Map& map);
        static void addCollider(sf::Sprite& n_collider);
        static bool allowMove(const Collider& n_collider, sf::Vector2f n_move);
        std::basic_ostream< char, std::char_traits< char > >::__ostream_type n_char();

    protected:

        static Map const* m_map;
        static std::vector<sf::Sprite*> m_colliders;
};

#endif

#ifndef CHARACTER_H
#define CHARACTER_H

#include "animatedsprite.h"
#include <list>
#include "bomb.h"

class Character : public AnimatedSprite
{
    public:
        Character();
        float speed() const;
        virtual void update();
        void setBomb(const sf::Vector2f& n_pos);

    protected:
        float m_speed;
        std::list<Bomb*> m_bombs;
        bool m_can_drop_bomb;
        sf::Clock m_timer;
        float m_reload_time;
};

#endif // CHARACTER_H

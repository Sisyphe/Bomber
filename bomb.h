#ifndef BOMB_H
#define BOMB_H

#include "animatedsprite.h"

class Bomb : public AnimatedSprite
{
    public:
        Bomb();
        float countdown();
        void trigger();
        bool isDestroyed();
        void update();

    protected:
        void detonate();
        float m_countdown;
        float m_range;
        float m_remaining_time;
        bool m_is_triggered;
        sf::Clock m_timer;
        bool m_is_detonated;
        bool m_is_destroyed;
};

#endif // BOMB_H

#ifndef LOCALUSER_H
#define LOCALUSER_H

#include "user.h"

enum Key
{
    Left,
    Right,
    Up,
    Down,
    Bomb
};

class LocalUser : public User
{
    public:
        LocalUser();
        virtual void update();

    protected:
        std::map<Key,sf::Keyboard::Key> m_key_set;
};

#endif // LOCALUSER_H

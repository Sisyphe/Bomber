#ifndef USER_H
#define USER_H

#include "character.h"

class User
{
    public:
        User();
        const Character* const character();
        virtual void update()=0;

    protected:
        Character m_character;
};

#endif // USER_H

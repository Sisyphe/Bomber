#include "user.h"

User::User()
{
}

const Character *const User::character()
{
    return &m_character;
}

#ifndef LAB2_PLAYER_H
#define LAB2_PLAYER_H

#include "strategy.h"

namespace labirint
{
    enum class direction
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    class player
    {
    private:
        direction m_dirrection;
        unsigned m_x, m_y;
        strategy m_strategy;
    };
}


#endif //LAB2_PLAYER_H

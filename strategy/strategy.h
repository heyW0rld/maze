#ifndef LAB2_STRATEGY_H
#define LAB2_STRATEGY_H

#include "../include/map.h"

namespace labirint
{
    enum class direction
    {
        HERE,
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    class strategy
    {
    public:
        virtual void step(labirint::map &someMap, unsigned &x, unsigned &y) = 0;

    protected:
        direction m_currentDirrection = direction::HERE;
        unsigned m_x, m_y;
    };
}


#endif //LAB2_STRATEGY_H

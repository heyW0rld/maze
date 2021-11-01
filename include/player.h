#ifndef LAB2_PLAYER_H
#define LAB2_PLAYER_H

#include <memory>

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
    public:
        void setStrategy(std::unique_ptr<strategy> someStrategy);
    private:
        direction m_dirrection;
        unsigned m_x, m_y;
        std::unique_ptr<strategy> m_strategy;
    };
}


#endif //LAB2_PLAYER_H

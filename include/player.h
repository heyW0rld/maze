#ifndef LAB2_PLAYER_H
#define LAB2_PLAYER_H

#include <memory>

#include "../strategy/strategy.h"

namespace labirint
{


    class player
    {
    public:
        player() = default;
        player(player&&);
        void setStrategy(std::unique_ptr<strategy> someStrategy);
        void setCoords(unsigned x, unsigned y);
        void step(labirint::map &someMap);

        player& operator=(player &rhs) noexcept;
    private:
        direction m_dirrection;
        unsigned m_x, m_y;
        std::unique_ptr<strategy> m_strategy;
    };
}


#endif //LAB2_PLAYER_H

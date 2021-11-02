#include "player.h"

void labirint::player::setStrategy(std::unique_ptr<strategy> someStrategy)
{
    m_strategy = std::move(someStrategy);
}

labirint::player& labirint::player::operator=(labirint::player &rhs)
 noexcept
{
    if(&rhs == this)
        return *this;

    m_dirrection = rhs.m_dirrection;
    m_strategy = std::move(rhs.m_strategy);
    m_x = rhs.m_x;
    m_y = rhs.m_y;

    return *this;
}

labirint::player::player(labirint::player &&somePlayer)
{
    m_dirrection = somePlayer.m_dirrection;
    m_strategy = std::move(somePlayer.m_strategy);
    m_x = somePlayer.m_x;
    m_y = somePlayer.m_y;
}

void labirint::player::step(labirint::map &someMap)
{
    m_strategy->step(someMap, m_x, m_y);
}

void labirint::player::setCoords(unsigned int x, unsigned int y)
{
    m_x = x;
    m_y = y;
}





//
// Created by dpavlov on 31.10.2021.
//

#include "player.h"

void labirint::player::setStrategy(std::unique_ptr<strategy> someStrategy)
{
    m_strategy = std::move(someStrategy);
}

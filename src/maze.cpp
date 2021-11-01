//
// Created by dpavlov on 31.10.2021.
//

#include "maze.h"

void labirint::maze::uploadMap(const std::vector<std::vector<char>> &&map)
{
    m_map.upload(std::move(map));
}

void labirint::maze::addPlayer(char number, const labirint::player &somePlayer)
{
    m_players[number] = somePlayer;
}

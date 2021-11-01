//
// Created by dpavlov on 31.10.2021.
//

#include "maze.h"

void labirint::maze::uploadMap(const std::vector<std::vector<char>> &&map)
{
    m_map.upload(std::move(map));
}

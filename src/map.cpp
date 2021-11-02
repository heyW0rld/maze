#include "../include/map.h"

namespace labirint
{
    void map::upload(const std::vector<std::vector<char>> &&map)
    {
        m_map = map;
    }

    unsigned map::width()
    {
        return m_map[0].size();
    }

    unsigned map::heigth()
    {
        return m_map.size();
    }

    char &map::getSymbol(unsigned int x, unsigned int y)
    {
        return m_map[y][x];
    }
}
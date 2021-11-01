#include "../include/map.h"

namespace labirint
{
    void map::upload(const std::vector<std::vector<char>> &&map)
    {
        m_map = map;
    }
}
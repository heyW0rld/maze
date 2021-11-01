#ifndef LAB2_MAZE_H
#define LAB2_MAZE_H

#include <array>

#include "map.h"
#include "player.h"

namespace labirint
{
    class maze
    {
    public:
        void addPlayer(char number, const player &somePlayer);
        void uploadMap(const std::vector<std::vector<char>> &&map);
    private:
        map m_map;
        std::array<labirint::player, 4> m_players;

    };
}


#endif //LAB2_MAZE_H

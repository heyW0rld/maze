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
        maze();
        void addPlayer(char number, player &&somePlayer);
        void uploadMap(const std::vector<std::vector<char>> &&map);
        void showMaze();
        void clearShow();
    private:
        map m_map;
        std::vector<labirint::player> m_players;

    };
}


#endif //LAB2_MAZE_H

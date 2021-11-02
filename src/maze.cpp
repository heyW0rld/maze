#include "maze.h"
#include "thread"

void labirint::maze::uploadMap(const std::vector<std::vector<char>> &&map)
{
    m_map.upload(std::move(map));
}

void labirint::maze::addPlayer(char number, labirint::player &&somePlayer)
{
    m_players.at(number - 1) = somePlayer;
}

labirint::maze::maze()
{
    m_players.resize(4);
}


#include <iostream>
void labirint::maze::showMaze()
{
    while(true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds (50));
        clearShow();
        for (unsigned i = 0; i < m_map.heigth(); ++i)
        {
            for (unsigned j = 0; j < m_map.width(); ++j)
            {
                std::cout << m_map.getSymbol(j, i);
            }
            std::cout << std::endl;
        }
        m_players[0].step(m_map);
    }
}

void labirint::maze::clearShow()
{
    for(unsigned i = 0; i < 50; ++i)
        std::cout << std::endl;
}

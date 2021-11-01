#ifndef LAB2_LABIRINTMANAGER_H
#define LAB2_LABIRINTMANAGER_H

#include <fstream>
#include <vector>

#include "maze.h"
#include "player.h"
#include "../strategy/backRevert.h"
#include "../strategy/greedy.h"
#include "../strategy/leftHand.h"
#include "../strategy/rightHand.h"

namespace labirint
{
    class labirintManager
    {
    public:
        static void uploadMazeFromFile(const std::string &pathToFile, maze &someMaze);
    private:
        static unsigned getWidth(std::ifstream &ifStream);
        static unsigned getHeight(std::ifstream &ifStream);
        static bool isPlayer(char symbol);
        static std::unique_ptr<strategy> strategyForPlayer(char number);
    };
}


#endif //LAB2_LABIRINTMANAGER_H

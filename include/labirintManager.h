#ifndef LAB2_LABIRINTMANAGER_H
#define LAB2_LABIRINTMANAGER_H

#include <fstream>
#include <vector>

#include "maze.h"
#include "player.h"

namespace labirint
{
    class labirintManager
    {
    public:
        static void uploadMazeFromFile(const std::string &pathToFile, maze &someMaze);
    private:
        static unsigned getWidth(std::ifstream &ifstream);
        static unsigned getHeight(std::ifstream &ifStream);
    };
}


#endif //LAB2_LABIRINTMANAGER_H

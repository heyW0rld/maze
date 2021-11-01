#include <iostream>
#include "labirintManager.h"
#include "map.h"


int main(int argc, char** argv)
{
    labirint::maze mainMaze;
    labirint::labirintManager::uploadMazeFromFile(std::string(argv[1]), mainMaze);

    return 0;
}

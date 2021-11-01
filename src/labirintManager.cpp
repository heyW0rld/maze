#include "labirintManager.h"

void labirint::labirintManager::uploadMazeFromFile(const std::string &pathToFile, labirint::maze &someMaze)
{
    std::ifstream ifStream(pathToFile);

    if(!ifStream.is_open())
    {
        throw std::runtime_error("Dont open file");
    }

    unsigned widthOfMap = getWidth(ifStream);
    unsigned heightOfMap = getHeight(ifStream);

    std::vector<std::vector<char>> charMap(heightOfMap);
    for(unsigned i = 0; i < heightOfMap; ++i)
    {
        std::vector<char> line(widthOfMap);
        charMap[i] = line;
        for(unsigned j = 0; j < widthOfMap; ++j)
        {
            charMap[i][j] = ifStream.get();
        }
        ifStream.get(); //символ переноса
    }

    someMaze.uploadMap(std::move(charMap));
}

unsigned labirint::labirintManager::getWidth(std::ifstream &ifStream)
{
    ifStream.seekg(0, std::ios::beg);

    unsigned width = 0;char ch = -1;
    while (ifStream.get() != '\n') {
        width++;
    }

    ifStream.seekg(0, std::ios::beg);

    return width;
}

unsigned labirint::labirintManager::getHeight(std::ifstream &ifStream) {
    ifStream.seekg(0, std::ios::beg);

    unsigned height = 0;
    std::string tmpStr;
    while (getline(ifStream, tmpStr))
    {
        height++;
    }

    ifStream.clear();
    ifStream.seekg(0, std::ios::beg);

    return height - 1;
}


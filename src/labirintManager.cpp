#include "labirintManager.h"

namespace labirint
{
    void labirint::labirintManager::uploadMazeFromFile(const std::string &pathToFile, labirint::maze &someMaze)
    {
        std::ifstream ifStream(pathToFile);

        if (!ifStream.is_open()) {
            throw std::runtime_error("Dont open file");
        }

        unsigned widthOfMap = getWidth(ifStream);
        unsigned heightOfMap = getHeight(ifStream);

        std::vector<std::vector<char>> charMap(heightOfMap);
        for (unsigned i = 0; i < heightOfMap; ++i)
        {
            std::vector<char> line(widthOfMap);
            charMap[i] = line;
            for (unsigned j = 0; j < widthOfMap; ++j)
            {
                charMap[i][j] = ifStream.get();
                if (isPlayer(charMap[i][j]))
                {
                    player somePlayer;
                    char numberOfPlayer = charMap[i][j] - '0';
                    somePlayer.setStrategy(strategyForPlayer(1));
                    somePlayer.setCoords(j, i);
                    someMaze.addPlayer(numberOfPlayer, std::move(somePlayer));
                }
            }
            ifStream.get(); //символ переноса
        }

        someMaze.uploadMap(std::move(charMap));
    }


    unsigned labirint::labirintManager::getWidth(std::ifstream &ifStream)
    {
        ifStream.seekg(0, std::ios::beg);

        unsigned width = 0;
        while (ifStream.get() != '\n') {
            width++;
        }

        ifStream.seekg(0, std::ios::beg);

        return width;
    }

    unsigned labirint::labirintManager::getHeight(std::ifstream &ifStream)
    {
        ifStream.seekg(0, std::ios::beg);

        unsigned height = 0;
        std::string tmpStr;
        while (getline(ifStream, tmpStr)) {
            height++;
        }

        ifStream.clear();
        ifStream.seekg(0, std::ios::beg);

        return height - 1;
    }

    std::unique_ptr<strategy> labirint::labirintManager::strategyForPlayer(char number)
    {
        switch (number) {
            case 1:
                return std::make_unique<greedy>();
//            case 2:
//                return std::make_unique<leftHand>();
//            case 3:
//                return std::make_unique<rightHand>();
//            case 4:
//                return std::make_unique<backRevert>();
        }
    }

    bool labirint::labirintManager::isPlayer(char symbol) {
        return (symbol >= '1' && symbol <= '4');
    }
}


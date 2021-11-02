#ifndef LAB2_MAP_H
#define LAB2_MAP_H

#include <vector>

namespace labirint
{

    class map {
    private:
        std::vector<std::vector<char>> m_map;

    public:
        char &getSymbol(unsigned x, unsigned y);
        void upload(const std::vector<std::vector<char>> &&map);
        unsigned width();
        unsigned heigth();
    };
}

#endif //LAB2_MAP_H

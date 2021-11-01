#ifndef LAB2_MAP_H
#define LAB2_MAP_H

#include <vector>

namespace labirint
{

    class map {
    private:
        std::vector<std::vector<char>> m_map;

    public:
        void upload(const std::vector<std::vector<char>> &&map);
    };
}

#endif //LAB2_MAP_H

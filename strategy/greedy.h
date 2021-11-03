#ifndef LAB2_GREEDY_H
#define LAB2_GREEDY_H

#include <array>

#include "strategy.h"

namespace labirint
{
    class greedy : public strategy
    {
    public:
        void step(labirint::map &someMap, unsigned &x, unsigned &y) override;

    private:
        unsigned m_max = 10;

        labirint::direction whereisMoney(labirint::map &someMap, unsigned &x, unsigned &y);
        labirint::direction whereisExit(labirint::map &someMap, unsigned &x, unsigned &y);
        labirint::direction whereisWall(labirint::map &someMap, unsigned &x, unsigned &y);


        bool scanLine(char symbol, labirint::map &someMap, labirint::direction someDirection, unsigned &x, unsigned &y);
    };
}


#endif //LAB2_GREEDY_H

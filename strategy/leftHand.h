//
// Created by dpavlov on 01.11.2021.
//

#ifndef LAB2_LEFTHAND_H
#define LAB2_LEFTHAND_H

#include <array>

#include "strategy.h"

namespace labirint
{
    class leftHand : public strategy {
    public:
        void step(labirint::map &someMap, unsigned &x, unsigned &y) override;

    private:
        direction whereisLeft(labirint::map &someMap, unsigned &x, unsigned &y);
        direction scanLine(labirint::map &someMap, labirint::direction someDirection, unsigned &x, unsigned &y);

    };
}

#endif //LAB2_LEFTHAND_H

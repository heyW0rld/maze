//
// Created by dpavlov on 01.11.2021.
//

#include "leftHand.h"
#include <iostream>

namespace labirint
{
    void leftHand::step(labirint::map &someMap, unsigned &x, unsigned &y)
    {
        if (m_currentDirrection == labirint::direction::HERE)
        {
            m_x = x;
            m_y = y;
            m_currentDirrection = whereisMoney(someMap, m_x, m_y);
            if(m_currentDirrection == labirint::direction::HERE)
            {
                m_currentDirrection = whereisExit(someMap, m_x, m_y);
                if(m_currentDirrection == labirint::direction::HERE) {
                    m_currentDirrection = whereisWall(someMap, m_x, m_y);
                }

            }
        }
        else
        { //toDo вынести изменение позиции в стратегию (исходная позиция -> позиция, которая нашлась в функции внутри стратегии)
            int stepX = 0, stepY = 0;
            if (m_currentDirrection == labirint::direction::UP)
                stepY = -1;
            else if (m_currentDirrection == labirint::direction::RIGHT)
                stepX = 1;
            else if (m_currentDirrection == labirint::direction::DOWN)
                stepY = 1;
            else if (m_currentDirrection == labirint::direction::LEFT)
                stepX = -1;

            if (x != m_x || y != m_y)
            {
                if(someMap.getSymbol(x + stepX, y + stepY) == 'e')
                {
                    someMap.getSymbol(x, y) = ' ';
                }
                else
                {
                    someMap.getSymbol(x, y) = ' ';
                    someMap.getSymbol(x + stepX, y + stepY) = '1';
                    x += stepX;
                    y += stepY;
                }
            }
            else
            {
                m_currentDirrection = labirint::direction::HERE;
            }
        }
    }

    labirint::direction leftHand::whereisLeft(labirint::map &someMap, unsigned &x, unsigned &y)
    {
        unsigned curPosX, curPosY;

        std::array<labirint::direction, 4> directions {direction::UP, direction::RIGHT,
                                                       direction::DOWN, direction::LEFT};

        for(auto dir : directions)
        {
            curPosX = x;
            curPosY = y;

            if(scanLine(someMap, dir, curPosX, curPosY))
            {
                x = curPosX;
                y = curPosY;
                return dir;
            }
        }

        return labirint::direction::HERE;
    }

    direction scanLine(labirint::map &someMap, labirint::direction someDirection, unsigned &x, unsigned &y)
    {
        unsigned curPosX = x;
        unsigned curPosY = y;

        int stepX = 0, stepY = 0;

        direction result;
        int viewX = 0, viewY = 0;
        switch(someDirection) //toDo вынести повыше
        {
            case direction::UP:
                stepY = -1;
                viewX = -1;
                result = direction::LEFT;
                break;
            case direction::RIGHT:
                stepX = 1;
                viewY = -1;
                result = direction::UP;
                break;
            case direction::DOWN:
                stepY = 1;
                viewX = 1;
                result = direction::RIGHT;
                break;
            case direction::LEFT:
                stepX = -1;
                viewY = 1;
                result = direction::DOWN;
                break;
        }

        while (someMap.getSymbol(curPosX+stepX+viewX, curPosY+stepY+viewY) != ' ' &&
                            someMap.getSymbol(curPosX+stepX, curPosY+stepY) == ' ')
        {
            curPosX += stepX;
            curPosY += stepY;
        }

        curPosX += stepX;
        curPosY += stepY;

        x = curPosX;
        y = curPosY;
        return result;
    }
}

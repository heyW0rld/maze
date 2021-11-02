#include "greedy.h"
#include "iostream"

namespace labirint
{
    void greedy::step(labirint::map &someMap, unsigned &x, unsigned &y)
    {
        if (m_currentDirrection == labirint::direction::HERE)
        {
            m_x = x;
            m_y = y;
            m_currentDirrection = whereisMoney(someMap, m_x, m_y);
            if(m_currentDirrection == labirint::direction::HERE)
                m_currentDirrection = whereisExit(someMap, m_x, m_y);
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
            {;
                m_currentDirrection = labirint::direction::HERE;
            }
        }

    }

    labirint::direction greedy::whereisMoney(labirint::map &someMap, unsigned &x, unsigned &y)
    {
        int curPosX, curPosY, stepX, stepY;

        curPosX = x;
        curPosY = y;
        stepX = 0;
        stepY = -1;

        while (someMap.getSymbol(curPosX, curPosY) != '*' && someMap.getSymbol(curPosX, curPosY) != 'e')
        {
            curPosX += stepX;
            curPosY += stepY;
            if (someMap.getSymbol(curPosX, curPosY) == '$')
            {
                x = curPosX;
                y = curPosY;
                return labirint::direction::UP;
            }
        }

        curPosX = x;
        curPosY = y;
        stepX = 1;
        stepY = 0;
        while (someMap.getSymbol(curPosX, curPosY) != '*' && someMap.getSymbol(curPosX, curPosY) != 'e')
        {
            curPosX += stepX;
            curPosY += stepY;
            if (someMap.getSymbol(curPosX, curPosY) == '$')
            {
                x = curPosX;
                y = curPosY;
                return labirint::direction::RIGHT;
            }
        }

        curPosX = x;
        curPosY = y;
        stepX = 0;
        stepY = 1;
        while (someMap.getSymbol(curPosX, curPosY) != '*' && someMap.getSymbol(curPosX, curPosY) != 'e')
        {
            curPosX += stepX;
            curPosY += stepY;
            if (someMap.getSymbol(curPosX, curPosY) == '$')
            {
                x = curPosX;
                y = curPosY;
                return labirint::direction::DOWN;
            }
        }

        curPosX = x;
        curPosY = y;
        stepX = -1;
        stepY = 0;
        while (someMap.getSymbol(curPosX, curPosY) != '*' && someMap.getSymbol(curPosX, curPosY) != 'e')
        {
            curPosX += stepX;
            curPosY += stepY;
            if (someMap.getSymbol(curPosX, curPosY) == '$')
            {
                x = curPosX;
                y = curPosY;
                return labirint::direction::LEFT;
            }
        }

        return labirint::direction::HERE;
    }

    labirint::direction greedy::whereisExit(labirint::map &someMap, unsigned &x, unsigned &y)
    {
        int curPosX, curPosY, stepX, stepY;

        curPosX = x;
        curPosY = y;
        stepX = 0;
        stepY = -1;

        while (someMap.getSymbol(curPosX, curPosY) != '*')
        {
            curPosX += stepX;
            curPosY += stepY;
            if (someMap.getSymbol(curPosX, curPosY) == 'e')
            {
                x = curPosX;
                y = curPosY;
                return labirint::direction::UP;
            }
        }

        curPosX = x;
        curPosY = y;
        stepX = 1;
        stepY = 0;
        while (someMap.getSymbol(curPosX, curPosY) != '*')
        {
            curPosX += stepX;
            curPosY += stepY;
            if (someMap.getSymbol(curPosX, curPosY) == 'e')
            {
                x = curPosX;
                y = curPosY;
                return labirint::direction::RIGHT;
            }
        }

        curPosX = x;
        curPosY = y;
        stepX = 0;
        stepY = 1;
        while (someMap.getSymbol(curPosX, curPosY) != '*')
        {
            curPosX += stepX;
            curPosY += stepY;
            if (someMap.getSymbol(curPosX, curPosY) == 'e')
            {
                x = curPosX;
                y = curPosY;
                return labirint::direction::DOWN;
            }
        }

        curPosX = x;
        curPosY = y;
        stepX = -1;
        stepY = 0;
        while (someMap.getSymbol(curPosX, curPosY) != '*')
        {
            curPosX += stepX;
            curPosY += stepY;
            if (someMap.getSymbol(curPosX, curPosY) == 'e')
            {
                x = curPosX;
                y = curPosY;
                return labirint::direction::LEFT;
            }
        }
    }
}

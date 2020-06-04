#pragma once
#include <vector>
#include <iostream>
#include <time.h>
#include "Cell.h"
#include "TextureHolder.h"
using namespace std;


class Deck
{
    public:
        Deck();
        void Shuffle();
        int GetNumber(int Xpos, int Ypos);
        Sprite getSprite(int cell);
        void Move (int dx, int dy);
        Vector2i getEmptyPosition();
        Sprite m_MenuSprite;

    private:
        vector <cCell> m_Cells;
        Vector2i m_EmptyPosition;
        Sprite m_SpriteTiles;
        TextureHolder th;
        const int CELL_SIZE=64;
};


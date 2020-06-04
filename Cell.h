#pragma once
#include "SFML/Graphics.hpp"


using namespace sf;

class cCell
{
    public:
        cCell(int number, Sprite sprite);
        int GetNumber();
        void Move(int dx, int dy);
        Vector2i GetPosition();
        Sprite getSprite();

    private:
        int m_Number;
        Vector2i m_Position;
        Sprite m_Sprite;
        const int CELL_SIZE=64;
};


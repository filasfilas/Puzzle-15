#include "Cell.h"

cCell::cCell(int number, Sprite sprite)
{
    m_Number=number;
    m_Position.x=(number-1)%4;
    m_Position.y=(number-1)/4;
    m_Sprite = sprite;
    m_Sprite.setPosition(Vector2f(m_Position.x*CELL_SIZE, m_Position.y*CELL_SIZE));
}

int cCell::GetNumber()
{
    return m_Number;
}

Vector2i cCell::GetPosition()
{
    return m_Position;
}

void cCell::Move(int dx, int dy)
{
    m_Position.y +=dy;
    m_Position.x +=dx;

    Vector2f temp=m_Sprite.getPosition();
    temp.x +=dx*CELL_SIZE;
    temp.y +=dy*CELL_SIZE;
    m_Sprite.setPosition(Vector2f(temp));
}

Sprite cCell::getSprite()
{
    return m_Sprite;
}


#include "Deck.h"

Deck::Deck()
{
    m_EmptyPosition.x=3;
    m_EmptyPosition.y=3;


    for (int num=1; num<16; num++)
    {
        int x=(num-1)%4;
        int y=(num-1)/4;
        m_SpriteTiles=Sprite(TextureHolder::GetTexture("images/15.png"));
        m_SpriteTiles.setTextureRect(IntRect(x*CELL_SIZE, y*CELL_SIZE, CELL_SIZE, CELL_SIZE));
        m_Cells.push_back(cCell(num, m_SpriteTiles));
    }

        m_MenuSprite=Sprite(TextureHolder::GetTexture("images/menu.png"));
        m_MenuSprite.setPosition(Vector2f(0, 4*CELL_SIZE));
}

int Deck::GetNumber (int x, int y)
{
    Vector2i pos;
    for (int i=0; i<m_Cells.size(); i++)
    {
        pos=m_Cells[i].GetPosition();
        if (pos.x==x && pos.y==y) return m_Cells[i].GetNumber();
    }
}

void Deck::Move (int dx, int dy)
{
    if (dx==-1 && m_EmptyPosition.x==3) return;
    if (dx==1  && m_EmptyPosition.x==0) return;
    if (dy==-1 && m_EmptyPosition.y==3) return;
    if (dy==1  && m_EmptyPosition.y==0) return;

    int x = m_EmptyPosition.x-dx;
    int y = m_EmptyPosition.y-dy;
    m_EmptyPosition.x = x;
    m_EmptyPosition.y = y;

    Vector2i pos;
    for (int i=0; i<m_Cells.size(); i++)
    {
        pos=m_Cells[i].GetPosition();
        if (pos.x==x && pos.y==y)
        {
            m_Cells[i].Move(dx,dy);
        }
    }

}

void Deck::Shuffle()
{
    srand( time(0) );
    int choise;
    for (int i=0; i<200; i++)
    {
        choise = rand()%4;
        switch (choise)
        {
            case 0: Move(-1,0); break;
            case 1: Move(1,0); break;
            case 2: Move(0,-1); break;
            case 3: Move(0,1); break;
        }
    }
}

Sprite Deck::getSprite(int cell)
{
    return m_Cells[cell].getSprite();
}

Vector2i Deck::getEmptyPosition()
{
    return m_EmptyPosition;
}


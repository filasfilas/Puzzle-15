#include "GameEngine.h"

void GameEngine::Input()
{
    Event event;
    if (m_GameState ==New) return;

    while (m_Window.pollEvent(event))
    {
        if (event.type == Event::Closed){m_GameState = Exit;}

        if (event.type == Event::KeyPressed)
        {
            if (Keyboard::isKeyPressed(Keyboard::Escape)){m_GameState = Exit;}
            if (Keyboard::isKeyPressed(Keyboard::Return)) {m_GameState=New;}
            if (Keyboard::isKeyPressed(Keyboard::Left))  {m_Deck.Move(-1,0);}
            if (Keyboard::isKeyPressed(Keyboard::Right)) {m_Deck.Move(1,0);}
            if (Keyboard::isKeyPressed(Keyboard::Up))    {m_Deck.Move(0,-1);}
            if (Keyboard::isKeyPressed(Keyboard::Down))  {m_Deck.Move(0,1);}
        }

        if (event.type == Event::MouseButtonPressed)
        {
            if (event.key.code == Mouse::Left)
            {
                Vector2i position = Mouse::getPosition(m_Window);
                int x = position.x/CELL_SIZE;
                int y = position.y/CELL_SIZE;
                int emptyX = m_Deck.getEmptyPosition().x;
                int emptyY = m_Deck.getEmptyPosition().y;
                int dx= emptyX-x;
                int dy = emptyY-y;

                if (dx*dy==0 && abs(dx+dy)==1)
                {
                    m_Deck.Move(dx,dy);
                }
            }
        }
    }
}


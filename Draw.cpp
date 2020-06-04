#include "GameEngine.h"

void GameEngine::Draw()
{
    m_Window.clear(Color::White);


    for (int i=0; i<15; i++)
    {
        m_Window.draw(m_Deck.getSprite(i));
    }

    //menu
    m_Window.draw(m_Deck.m_MenuSprite);



    m_Window.display();
}


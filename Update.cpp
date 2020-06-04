#include "GameEngine.h"

void GameEngine::Update(float dtAsSeconds)
{
    if(m_GameState == New)
    {
        m_Deck.Shuffle();
        m_GameState=Play;
    }
}


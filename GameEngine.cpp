#include "GameEngine.h"

GameEngine::GameEngine()
{
	m_GameState=New;

    Vector2f resolution;
    resolution.x= 4* CELL_SIZE;
    resolution.y= 4* CELL_SIZE+20;
    m_Window.create (VideoMode(resolution.x, resolution.y), "Puzzle 15", Style::Close | Style::Titlebar);
    m_Window.setFramerateLimit(60);
}

void GameEngine::run()
{
        Clock clock;
        while (m_GameState != Exit)
        {
            Time dt = clock.restart();

            Input();
            Update(dt.asSeconds());
            Draw();
        }
    
		m_Window.close();
}


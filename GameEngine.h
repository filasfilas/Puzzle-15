#pragma once
#include "Deck.h"
#include "SFML/Graphics.hpp"
#include "TextureHolder.h"
using namespace std;
using namespace sf;

enum GameState {New, Play, Exit};

class GameEngine
{
    public:
        GameEngine();
        //~GameEngine();
        void run();

    private:
        Deck m_Deck;
        void Input();
        void Update(float dtAsSeconds);
        void Draw();
        GameState m_GameState;

        RenderWindow m_Window;
        const int CELL_SIZE=64;
 };

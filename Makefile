

Puzzle15:	Puzzle15.o Cell.o Deck.o Draw.o GameEngine.o Input.o TextureHolder.o Update.o
	g++ -o Puzzle15 Puzzle15.o Cell.o Deck.o Draw.o GameEngine.o Input.o TextureHolder.o Update.o -lsfml-graphics -lsfml-system -lsfml-window 

Puzzle15.o : Puzzle15.cpp GameEngine.h
	g++ -c  Puzzle15.cpp


Cell.o : Cell.cpp Cell.h Deck.h TextureHolder.h
	g++ -c Cell.cpp

Deck.o : Deck.cpp Deck.h
	g++ -c Deck.cpp

Draw.o : Draw.cpp GameEngine.h
	g++ -c Draw.cpp

GameEngine.o : GameEngine.cpp GameEngine.h Deck.h TextureHolder.h
	g++ -c GameEngine.cpp

Input.o : Input.cpp GameEngine.h Deck.h TextureHolder.h
	g++ -c Input.cpp

Update.o : Update.cpp GameEngine.h Deck.h TextureHolder.h
	g++ -c Update.cpp

TextureHolder.o : TextureHolder.cpp TextureHolder.h
	g++ -c TextureHolder.cpp

clean :
	rm Puzzle15.o Cell.o Deck.o Draw.o GameEngine.o Input.o TextureHolder.o Update.o

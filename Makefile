all: board.hpp board.cpp main.cpp ai.hpp ai.cpp
	g++ board.cpp ai.cpp main.cpp -o game

.PHONY: clean

clean:
	rm game

all: main player

main: main.cpp
	g++ -std=c++11 -o main main.cpp

player: player.cpp
	g++ -std=c++11 -o player player.cpp

.PHONY: clean
clean:
	rm -rf main

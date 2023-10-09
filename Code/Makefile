CC = gcc
CXXFLAGS = -O2 -std=c++14
LDFLAGS = -lstdc++
OUT = file



all: file

file: main.o ghost.o pacman.o board.o
	$(CC) main.o ghost.o pacman.o board.o -o $(OUT) $(LDFLAGS)

main: main.cpp
	$(CC) -c main.cpp $(CXXFLAGS)

ghost: ghost.cpp
	$(CC) -c ghost.cpp $(CXXFLAGS)

pacman: pacman.cpp
	$(CC) -c pacman.cpp $(CXXFLAGS)

board: board.cpp
	$(CC) -c board.cpp $(CXXFLAGS)
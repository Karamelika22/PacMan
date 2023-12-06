CC = gcc
CXXFLAGS = -O2 -std=c++14
LDFLAGS = -lstdc++
OUT = file




all: file

file: main.o libEnemy.a libPacman.a board.o
	$(CC) main.o libEnemy.a libPacman.a board.o -o $(OUT) $(LDFLAGS)

main: main.cpp
	$(CC) -c main.cpp $(CXXFLAGS)

libEnemy.a: enemy.o
	ar rcs libEnemy.a enemy.o

enemy: enemy.cpp
	$(CC) -c enemy.cpp $(CXXFLAGS)

libPacman.a: pacman.o
	ar rcs libPacman.a pacman.o

pacman: pacman.cpp
	$(CC) -c pacman.cpp $(CXXFLAGS)

board: board.cpp
	$(CC) -c board.cpp $(CXXFLAGS)


clean:
	rm -f *.o *.a $(OUT)
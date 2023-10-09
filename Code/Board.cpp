
#include "Board.h"
#include "Pacman.h" // Добавлен заголовок Pacman.h
#include "Ghost.h" // Добавлен заголовок Ghost.h
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <iostream>


char map[screenHeight][screenWidth];
char stage[screenHeight][screenWidth] = { " ################### ",
										  " #........#........# ",
										  " #.##.###.#.###.##.# ",
										  " #.................# ",
										  " #.##.#.#####.#.##.# ",
										  " #....#...#...#....# ",
										  " ####.###.#.###.#### ",
										  "    #.#.......#.#    ",
										  "#####.#.##.##.#.#####",
										  "#...................#",
										  "#####.#.##.##.#.#####",
										  "    #.#.......#.#    ",
										  " ####.#.#####.#.#### ",
										  " #........#........# ",
										  " #.##.###.#.###.##.# ",
										  " #..#...........#..# ",
										  " ##.#.#.#####.#.#.## ",
										  " #....#...#...#....# ",
										  " #.######.#.######.# ",
										  " #.................# ",
										  " ################### " };


Pacman pacman;
Ghost enemy[7];

void setup() {
	srand(time(NULL));
	pacman.x = 10;
	pacman.y = 15;
	pacman.dir = 'S';
	pacman.delay = 2;


	enemy[0].x = 9;
	enemy[0].y = 9;
	enemy[0].delay = 3;

	enemy[1].x = 10;
	enemy[1].y = 9;
	enemy[1].delay = 5;

	enemy[2].x = 11;
	enemy[2].y = 9;
	enemy[2].delay = 5;

	enemy[3].x = 2;
	enemy[3].y = 1;
	enemy[3].delay = 5;

	enemy[4].x = 18;
	enemy[4].y = 1;
	enemy[4].delay = 5;

	enemy[5].x = 2;
	enemy[5].y = 19;
	enemy[5].delay = 5;

	enemy[6].x = 18;
	enemy[6].y = 19;
	enemy[6].delay = 5;
}

void layout() {
	for (int i = 0; i < screenHeight; i++) {
		for (int j = 0; j < screenWidth; j++) {
			if (stage[i][j] == '#') map[i][j] = 9;
			else if (stage[i][j] == '.')map[i][j] = 8;
			else map[i][j] = 0;
		}
	}
}

void display() {
	gotoxy(2, 1); std::cout << "LIFE:  " << life;
	layout();
	pacman.draw();
	for (int i = 0; i < 7; i++) enemy[i].drwa();
	for (int i = 0; i < screenHeight; i++) {
		for (int j = 0; j < screenWidth; j++) {
			gotoxy(j + 2, i + 3);
			if (map[i][j] == 9) std::cout << char(219);
			if (map[i][j] == 8) std::cout << char(250);
			if (map[i][j] == 1) std::cout << char(86);
			if (map[i][j] == 2) std::cout << char(94);
			if (map[i][j] == 3) std::cout << char(62);
			if (map[i][j] == 4) std::cout << char(60);
			if (map[i][j] == 5) std::cout << char(234);
			if (map[i][j] == 0) std::cout << ' ';
		}
	}
}

void input() {
	if (kbhit()) {
		switch (getch()) {
		case 80:
			if (!pacman.collision(pacman.x, pacman.y + 1)) pacman.dir = 'D';
			break;
		case 72:
			if (!pacman.collision(pacman.x, pacman.y - 1))pacman.dir = 'U';
			break;
		case 75:
			if (!pacman.collision(pacman.x - 1, pacman.y)) pacman.dir = 'L';
			break;
		case 77:
			if (!pacman.collision(pacman.x + 1, pacman.y)) pacman.dir = 'R';
			break;
		}
	}
}

void movements() {
	pacman.move();
	for (int i = 0; i < 7; i++) enemy[i].move();
}

void gotoxy(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}

void hideCursor() {
	CONSOLE_CURSOR_INFO cursor;

	cursor.dwSize = 100;
	cursor.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);

}
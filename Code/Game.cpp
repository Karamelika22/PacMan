#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

using namespace std;

void gotoxy(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c)

}

void hideCursor() {
	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize = 100;
	cursor.dVisible = false;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), &cursor)

}

int life = 5;
int const screenHeight = 22;
int const screenWidth = 22;
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
                                       
class Pacman {
public:
	int x;
	int y;
	char dir;
	int delay;
	int count_delay;

	void draw() {
		if (dir == 'U')map[y][x] = 1;
		else if (dir == 'D')map[y][x] = 2;
		else if (dir == 'L')map[y][x] = 3;
		else if (dir == 'R'|| dir == 'S')map[y][x] = 4;
	}

	void move() {
		dead();
		if (count_delay == delay) {
			if (dir == 'U' && !collision(x, y - 1)) y--;
			if (dir == 'D' && !collision(x, y + 1)) y++;
			if (dir == 'L' && !collision(x-1, y )) x--;
			if (dir == 'R' && !collision(x + 1, y)) x++;
			count_delay = 0;

		}
		count_delay++;
		eat();
	}
	bool collision(int fx, int fy) {
		if (map[fy][fx] == 9)return true;
		return false;
	}

	void dead() {
		if (map[y][x] == 5) {
			dir = 'S';
			x = 10;
			y = 15;
			life--;
		}
	}
};

class Enemy {
public:
	int x;
	int y;
	int dir;
	int delay;
	int count_delay;


	void drwa() {
		map[y][x] = 5;
	}

	void move() {
		if (count_delay == delay) {
			if (dir == 0 && !collision(x, y - 1)) y--;
			if (dir == 1 && !collision(x, y + 1)) y++;
			if (dir == 2 && !collision(x - 1, y)) x--;
			if (dir == 2 && !collision(x + 1, y)) x++;
			coubt_delay = 0;
			dir = rand() % 4;
		}
		count_delay++;
	}
	bool collision(int fx, int fy) {
		if (map[fy][fx] == 9)return true;
		return false;
	}
};

Pacman pacman;
Enemy enemy[7];

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
	for (int i = o; i < screenHeight; i++) {
		for (int j = 0, j < screenWidth; j++) {
			if (stage[i][j] == '#') map[i][j] = 9;
			else if (stage[i][j] == '.')map[i][j] = 8;
			else map[i][j] = 0;
		}
	}
}

void display() {
	gotoxy(2, 1); cout << "LIFE:  " << life;
	layout();
	pacman.draw();
	for(int i = 0; i < 7; i++) enemy[i].draw();
	for (int i = 0; i < screenHeight; i++) {
		for (int j = 0; j < screenWidth; j++) {
			gotoxy(j + 2, i + 3);
			if (map[i][j] == 9) cout << char(219);
			if (map[i][j] == 8) cout << char(250);
			if (map[i][j] == 1) cout << char(86);
			if (map[i][j] == 2) cout << char(94);
			if (map[i][j] == 3) cout << char(62);
			if (map[i][j] == 4) cout << char(60);
			if (map[i][j] == 5) cout << char(234);
			if (map[i][j] == 0) cout << ' ';
		}
	}
}

void input() {
	if (kbhit()) {
		switch(getch()){
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

int main() {
	HWND s = GetConsoleWindow();
	MoveWindow(s, 300, 200, 250, 450, true);
	hideCursor();
	setup();
	while (life > 0) {
		display();
		input();
		movements();
	}
}
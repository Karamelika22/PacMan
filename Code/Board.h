

#ifndef BOARD_H
#define BOARD_H

extern int life; // ��������� ���������� life �� main.cpp
extern const int screenHeight = 24; // ��������� ���������� ���������� screenHeight
extern const int screenWidth = 22;
extern char map[screenHeight][screenWidth];

void setup();
void layout();
void display();
void input();
void movements();
void hideCursor();
void gotoxy(int x, int y);

#endif // BOARD_H

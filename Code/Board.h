#pragma once

extern const int screenHeight;
extern const int screenWidth;
extern char** map;
extern char** stage;
extern int life;

void layout();
void display();
void gotoxy(int x, int y);
void hideCursor();
void initializeMap();
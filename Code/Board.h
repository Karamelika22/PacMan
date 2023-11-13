#pragma once

#include <vector>
#include <string>

extern const int screenHeight;
extern const int screenWidth;
extern std::vector<std::string> map;
extern std::vector<std::string> stage;
extern int life;

void layout();
void display();
void gotoxy(int x, int y);
void hideCursor();
void initializeMap();
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "Board.h"
#include "Enemy.h"
#include "Pacman.h"
const int screenHeight = 22;
const int screenWidth = 22;
char** map;
char** stage;
int life = 5;

void initializeMap() {
    map = new char* [screenHeight];
    stage = new char* [screenHeight];
    for (int i = 0; i < screenHeight; i++) {
        map[i] = new char[screenWidth];
        stage[i] = new char[screenWidth];
    }
    char stageData[screenHeight][screenWidth] = {
                                          " ################### ",
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
                                          " ################### "
    };
    for (int i = 0; i < screenHeight; i++) {
        for (int j = 0; j < screenWidth; j++) {
            stage[i][j] = stageData[i][j];
        }
    }

    char mapData[screenHeight][screenWidth] = {
                                          " ################### ",
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
                                          " ################### "
    };

    for (int i = 0; i < screenHeight; i++) {
        for (int j = 0; j < screenWidth; j++) {
            map[i][j] = mapData[i][j];
        }
    }

}
extern Pacman pacman;
extern Enemy enemy[7];

void layout() {
    for (int i = 0; i < screenHeight; i++) {
        for (int j = 0; j < screenWidth; j++) {
            if (stage[i][j] == '#') map[i][j] = 9;
            else if (stage[i][j] == '.') map[i][j] = 8;
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

void freeMap() {
    for (int i = 0; i < screenHeight; i++) {
        delete[] map[i];
        delete[] stage[i];
    }
    delete[] map;
    delete[] stage;
    map = nullptr;
    stage = nullptr;
}
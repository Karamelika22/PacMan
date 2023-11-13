#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "Board.h"
#include "Enemy.h"
#include "Pacman.h"
#include <algorithm>

const int screenHeight = 22;
const int screenWidth = 22;
std::vector<std::string> map;
std::vector<std::string> stage;
int life = 5;

void initializeMap() {
    std::string stageData[screenHeight] = {
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

    std::string mapData[screenHeight] = {
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

    stage = std::vector<std::string>(std::begin(stageData), std::end(stageData));
    map = std::vector<std::string>(std::begin(mapData), std::end(mapData));

}
extern Pacman pacman;
extern Enemy enemy[7];

void layout() {
    for (int i = 0; i < screenHeight; i++) {
        for (int j = 0; j < screenWidth; j++) {
            if (stage[i][j] == '#') map[i][j] = '#';
            else if (stage[i][j] == '.') map[i][j] = '.';
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
            std::cout << map[i][j];
        }
    }
}

void freeMap() {
    stage.clear();
    map.clear();
}
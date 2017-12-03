//
// Created by jglrxavpok on 03/12/2017.
//

#ifndef ADVENTOFCODE2017_DAY3_H
#define ADVENTOFCODE2017_DAY3_H
#define GRID_SIZE 100

typedef int grid_t[GRID_SIZE][GRID_SIZE];
void runday3(int part);
int solveday3pt1(int input);
int solveday3pt2(int input);
int getgrid(grid_t *grid, int x, int y);
void setgrid(grid_t *grid, int x, int y, int value);
#endif //ADVENTOFCODE2017_DAY3_H

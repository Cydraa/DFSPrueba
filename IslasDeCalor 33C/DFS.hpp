#pragma once

#include <iostream>
#include <vector>

using std::vector;

struct Point
{
    float temp;
    bool isVisited;
    bool isLand;
    Point();
};

bool isSafe(const vector<vector<Point*>> &grid, int r, int c);
void dfs(vector<vector<Point*>> &grid, int r, int c, int depth);
int countIslands(vector<vector<Point*>> &grid);
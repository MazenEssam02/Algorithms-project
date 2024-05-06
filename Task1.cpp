#include <wchar.h>
#include <iostream>
using namespace std;

int gridSize, holeX, holeY, colorIndex = -1;
int grid[128][128];
int colorPattern[4];
int dp[4];

void placeColors(int x1, int y1, int x2, int y2, int x3, int y3)
{
    grid[x1][y1] = 1;
    grid[x2][y2] = 1;
    grid[x3][y3] = 1;
}

int getColor()
{
    if (colorIndex == 3)
        colorIndex = -1;
    colorIndex++;
    if (dp[colorIndex] != -1)
    {
        return dp[colorIndex];
    }
    if (colorIndex == 0 || colorIndex == 3)
        dp[colorIndex] = 2;
    else
        dp[colorIndex] = 3;
    return dp[colorIndex];
}

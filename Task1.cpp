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
void fillGrid(int n, int x, int y)
{
    int r, c, color;
    if (n == 2)
    {
        color = getColor();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[x + i][y + j] == 0)
                {
                    grid[x + i][y + j] = color;
                }
            }
        }
        return;
    }

    // Find hole
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (grid[i][j] != 0)
                r = i, c = j;
        }
    }

    if (r < x + n / 2 && c < y + n / 2)
        placeColors(x + n / 2, y + (n / 2) - 1, x + n / 2, y + n / 2, x + n / 2 - 1, y + n / 2);
    else if (r >= x + n / 2 && c < y + n / 2)
        placeColors(x + (n / 2) - 1, y + (n / 2), x + (n / 2), y + n / 2, x + (n / 2) - 1, y + (n / 2) - 1);
    else if (r < x + n / 2 && c >= y + n / 2)
        placeColors(x + n / 2, y + (n / 2) - 1, x + n / 2, y + n / 2, x + n / 2 - 1, y + n / 2 - 1);
    else if (r >= x + n / 2 && c >= y + n / 2)
        placeColors(x + (n / 2) - 1, y + (n / 2), x + (n / 2), y + (n / 2) - 1, x + (n / 2) - 1, y + (n / 2) - 1);

    fillGrid(n / 2, x, y);
    fillGrid(n / 2, x, y + n / 2);
    fillGrid(n / 2, x + n / 2, y);
    fillGrid(n / 2, x + n / 2, y + n / 2);
}


int main()
{
    gridSize = 8;
    memset(grid, 0, sizeof(grid));
    memset(dp, -1, sizeof(dp));
    holeX = 0, holeY = 3;
    grid[holeX][holeY] = -1;
    fillGrid(gridSize, 0, 0);
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
            cout << grid[i][j] << " \t";
        cout << "\n";
    }
}

/* Description:  C++ program to for Knight's tour problem using
 *  Warnsdorff's algorithm
 *  */
#include <bits/stdc++.h>
#define N 8

/* Arrays with all possible moves (X and Y offsets)
 *  from any position for the knight*/
static int cx[N] = {1,1,2,2,-1,-1,-2,-2};
static int cy[N] = {2,-2,1,-1,2,-2,1,-1};

/*Function: checks if a move is valid by
 * making sure it doesn't go out of board range*/
bool isMoveValid(int x, int y)
{
	return ((x >= 0 && y >= 0) && (x < N && y < N));
}

/* Function: checks whether a square is valid and empty or not */
bool isEmpty(int a[], int x, int y)
{
	return (isMoveValid(x, y)) && (a[y*N+x] < 0);
}

/* Function: returns the  number of possible moves
 *  from a certain position (x, y)
 *  N.B. Degree of a position means the number of possible moves from it,
 *  or in other words the number of unvisited adjacent */
int getDegree(int a[], int x, int y)
{
	int moveOptions = 0;
	for (int i = 0; i < N; i++)
		if (isEmpty(a, (x + cx[i]), (y + cy[i])))
			moveOptions++;

	return moveOptions;
}

/* Function: Picks next point using Warnsdorff's heuristic algorithm,
 * meaning that it explores all adjacent moves from the current (x,y) and
 * calculates the degree of each possible moves from my current position,
 * then it chooses the nextMove that has minimum degree or
 * has (minimum number of unvisited adjacent)
 * returns false if it is not possible to pick next point and discards
 * this solution.*/
bool nextMove(int a[], int *x, int *y)
{
	int min_deg_idx = -1, c, min_deg = (N+1), nx, ny;

	// Try all N adjacent of (*x, *y) starting
	// from a random adjacent. Find the adjacent
	// with minimum degree.
	int start = rand()%N;
	for (int count = 0; count < N; ++count)
	{
		int i = (start + count)%N;
		nx = *x + cx[i];
		ny = *y + cy[i];
		if ((isEmpty(a, nx, ny)) &&
		(c = getDegree(a, nx, ny)) < min_deg)
		{
			min_deg_idx = i;
			min_deg = c;
		}
	}

	// IF we could not find a next cell
	if (min_deg_idx == -1)
		return false;

	// Store coordinates of next point
	nx = *x + cx[min_deg_idx];
	ny = *y + cy[min_deg_idx];

	// Mark next move
	a[ny*N + nx] = a[(*y)*N + (*x)]+1;

	// Update next point
	*x = nx;
	*y = ny;

	return true;
}
/* Function: displays the chessboard with all the
 * legal knight's moves */
void print(int a[])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			printf("%d\t",a[j*N+i]);
		printf("\n");
	}
}

/* Function: checks the condition that
 * the knight ends on a square that is one
 * knight's move from the beginning square,
 * meaning then the tour is closed */
bool isTourClosed(int x, int y, int xx, int yy)
{
	for (int i = 0; i < N; ++i)
		if (((x+Xmove[i]) == xx)&&((y + Ymove[i]) == yy))
			return true;

	return false;
}

/* Function: Generates the legal moves using warnsdorff's heuristics.
 * Returns false if not possible */
bool findClosedTour()
{
	// Filling up the chessboard matrix with -1's
	int a[N*N];
	for (int i = 0; i< N*N; ++i)
		a[i] = -1;

	// Random initial position
	int sx = rand()%N;
	int sy = rand()%N;

	// Current points are same as initial points
	int x = sx, y = sy;
	a[y*N+x] = 1; // Mark first move.

	// Keep picking next points using
	// Warnsdorff's heuristic
	for (int i = 0; i < N*N-1; i++)
		if (nextMove(a, &x, &y) == 0)
			return false; //if we got stuck with these starting points return false

	// Check if tour is closed (Can end
	// at starting point)
	if (!isTourClosed(x, y, sx, sy))
		return false;

	print(a);
	return true;
}

int main()
{
	// To make sure that different random
	// initial positions are picked.
	srand(time(NULL));

	// While we don't get a solution call the findClosedTour function
	while (!findClosedTour())
	{
	;
	}

	return 0;
}


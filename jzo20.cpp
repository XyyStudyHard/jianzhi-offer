#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 101

int PrintMatrixInCircle(int (*num)[MAX], int row, int column, int start)
{
	if (num == NULL || row <= 0 || column <= 0)
		return 0;
	int endx, endy, i;
	endx = column - start - 1;
	endy = row - start - 1;


	//from left to right
	for (i = start; i <= endx; i ++)
	{
		printf("%d ", num[start][i]);
	}
	
	//from up to down
	if (endy > start)
	{
		for (i = start + 1; i <= endy; i ++)
			printf("%d ", num[i][endx]);
	}

	//from right to left
	if (endy > start && endx > start)
	{
		for (i = endx - 1; i >= start; i--)
			printf("%d ", num[endy][i]);
	}

	//from down to up
	if (endy > start + 1 && endx > start)
	{
		for (i = endy - 1; i > start; i --)
			printf("%d ", num[i][start]);
	}
	return 0;
}

void PrintMatrixClockwisely(int (*num)[MAX], int row, int column)
{
	if (num == NULL || row <= 0 || column <= 0)
		return ;
	int start = 0;
	while (column > start * 2 && row > start * 2)
	{
		PrintMatrixInCircle(num, row, column, start);
		++ start;
	}
	return ;
}


int main(void)
{
	int num[MAX][MAX];
	int m, n, i, j;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> m >> n)
	{
		for (i = 0; i < m; i ++)
			for (j = 0; j < n; j ++)
				cin >> num[i][j];

		PrintMatrixClockwisely(num, m, n);
		cout << endl;
	}
	
	system("pause");
    return 0;
}
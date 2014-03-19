#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int find_num(int arr[MAX][MAX], int rows, int columns, int num)
{
	int row = 0, column  = columns - 1;
	if (arr != NULL || rows >0 && columns > 0)
	{
		while(row < rows && column >= 0)
		{
			if (arr[row][column] == num)
				return 1;
			else
				if (arr[row][column] > num)
					--column;
				else
					++row;
		}
	}
	return 0;
}

int main(void)
{
	int m, n, i, j, num, result;
	int arr[MAX][MAX];

	while (scanf("%d %d", &m, &n) != EOF)
	{
		scanf("%d", &num);
		for (i = 0; i < m; i ++)
			for (j = 0; j < n; j++)
				scanf("%d", &arr[i][j]);
		result = find_num(arr, m, n, num);
		if (result == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

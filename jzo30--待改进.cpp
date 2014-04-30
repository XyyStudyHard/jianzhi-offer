#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 200005

int main(void)
{
	int  n, k;

	while (scanf("%d %d", &n, &k) != EOF)
	{
		unsigned long numbers[MAX];
		for (int i = 0; i < n; i++)
			scanf("%lu", &numbers[i]);
		if (numbers == NULL || n <= 0 || k <= 0 || k > n)
			continue;
		sort(numbers, numbers + n);
		for (int i = 0; i < k - 1; i++)
		{
			printf("%lu ", numbers[i]);
		}
		printf("%lu\n", numbers[k - 1]);
	}

	system("pause");
	return 0;
}
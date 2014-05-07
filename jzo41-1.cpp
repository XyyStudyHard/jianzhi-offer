#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 10006

void FindNumbersWithSum(int *num, int n, int k)
{
	if (num == NULL || n <= 0)
	{
		cout << "-1 -1" << endl;
		return;
	}

	int first = 0, end = n - 1, num1 = -1, num2 = -1, sum = 0;
	long int min_multi = 0x7fffffff, multi = 0;
	while (first < end)
	{
		sum = num[first] + num[end];
		if (sum == k)
		{
			multi = num[first] * num[end];
			if (multi < min_multi)
			{
				num1 = num[first];
				num2 = num[end];
				min_multi = multi;
			}
			first ++;
			end --;
		}
		else
			if (sum > k)
				end --;
			else
				first ++;
	}
	cout << num1 << " " << num2 << endl;

}


int main(void)
{
	int n, k, num[MAX];
	while(cin >> n >> k)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);
		FindNumbersWithSum(num, n, k);
	}

	system("pause");
	return 0;
}


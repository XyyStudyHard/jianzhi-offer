#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

bool IsContinous(int n, int *num)
{
	if (num == NULL || n < 1)
		return false;
	int number_of_zero = 0;
	int number_of_gap = 0;
	int num_repeat[14];
	for (int i = 0; i < 14; i++)
		num_repeat[i] = 0;
	for (int i = 0; i < n; i++)
	{
		num_repeat[num[i]] ++;
		if (num_repeat[num[i]] > 1 && num[i] != 0)
			return false;
	}
	number_of_zero = num_repeat[0];
	int j = number_of_zero;
	for (int i = 0; i < j; i++)
		num[i] = 0;
	int big, small;
	
	for (int i = 1; i < 14; i++)
	{
		if (num_repeat[i] != 0)
		{
			num[j] = i;
			j++;
		}
	}
	small = number_of_zero;
	big = small + 1;
	while (big < n)
	{
		number_of_gap += num[big] - num[small] - 1;
		small = big;
		big++;
	}
	if (number_of_gap > number_of_zero)
		return false;
	else
		return true;
}

int main(void)
{
	int n;
	cin >> n;
	while (n)
	{
		int *num = new int[n];
		for (int i = 0; i < n; i++)
			cin >> num[i];
		bool TF = IsContinous(n, num);
		if (TF)
			cout << "So Lucky!" << endl;
		else
			cout << "Oh My God!" << endl;
		cin >> n;
	}

	system("pause");
	return 0;
}


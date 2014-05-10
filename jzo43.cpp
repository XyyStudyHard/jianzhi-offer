#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX 80
double cmp(const void *a, const void *b)
{
	return *(double *)b - *(double *)a;
}



double *Probability(int n, int m, double *ratio)
{
	if (n < 1 || m <= 0)
		return NULL;
	int *appear_times[2];
	appear_times[0] = new int[n * m + 1];
	appear_times[1] = new int[n * m + 1];
	for (int i = 0; i < n * m + 1; i++)
	{
		appear_times[0][i] = 0;
		appear_times[1][i] = 0;
	}

	int flag = 0;
	for (int i = 1; i <= m; i++)
		appear_times[flag][i] = 1;
	//第一个骰子结果和的次数已经在前面的for循环里面进行了初始化
	//这个for循环针对之后的几次投骰子，计算对应的和的次数
	//放在数组里面	
	for (int k = 2; k <= n; k++)
	{
		for (int i = 0; i < k; i++)
			appear_times[1 - flag][i] = 0;
		//对每一个可能的和值，计算其次数
		for (int i = k; i <= m * k; i++)
		{
			appear_times[1 - flag][i] = 0;
			for (int j = 1; j <= i && j <= m; j++)
				appear_times[1 - flag][i] += appear_times[flag][i - j];
		}
		flag = 1 - flag;
	}
	double total = pow((double)m, n);
	for (int i = n; i <= n * m; i++)
	{
		ratio[i] = (double)appear_times[flag][i] / total;

	}

	delete[] appear_times[0];
	delete[] appear_times[1];
	return ratio;
}

double MaxNum(double *ratio, int *max_sum, double *max_ratio)
{
	double max = ratio[0];
	int index = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (max < ratio[i])
		{
			max = ratio[i];
			index = i;
		}
	}
	ratio[index] = 0;
	*max_sum = index;
	*max_ratio = max;
	return max;
}

int main(void)
{
	int n, m, flag = 0;
	while (cin >> n)
	{
		if (n == 0)
			return 0;
		cin >> m;
		if (flag == 1)
			printf("\n");
		flag = 1;
		double ratio[MAX];
		for (int i = 0; i < MAX; i++)
			ratio[i] = 0;
		Probability(n, m, ratio);
		
		for (int i = n; i <= n * m; i++)
			cout << ratio[i] << " ";
		cout << endl;
		int max_sum;
		double max_ratio;
		for (int i = 1; i <= 3; i++)
		{
			MaxNum(ratio, &max_sum, &max_ratio);
			printf("%d %.2f\n", max_sum, max_ratio);
		}

	}



	system("pause");
	return 0;
}


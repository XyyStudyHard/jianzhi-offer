#include <iostream>
#include <cstdio>


using namespace std;

#define MAX 100010

//也可以用动态规划的思想来解
// f(i) = numbers[i]           ,  i = 0 || f(i - 1) < 0 
//        f(i - 1) + numbers[i],  i != 0 && f(i - 1) >= 0
// 最后的=的位置可以根据题目要求来，如果要求得到的字符串是元素下标最小的那个
// 那么就要按照上面的来。
void FindGreatedstSumOfSubArray(int *numbers, int length)
{
	int sum = 0, start_max = 0, start = 0, end = 0;
	int max_sum = -2147483647 - 1; //设置最小数的方法
	if (numbers == NULL || length <= 0)
		return ;
	for (int i = 0; i < length; i++)
	{
		if (sum < 0)
		{
			start = i;
			sum = numbers[i];
		}
		else
			sum += numbers[i];
		if (sum > max_sum)
		{
			end = i;
			start_max = start;
			max_sum = sum;
		}
	}
	printf("%d %d ", max_sum, start_max);
	printf("%d\n", end);
}


int main(void)
{
	int  n;
	scanf("%d", &n);
	while (n != 0)
	{
		int numbers[MAX];
		for (int i = 0; i < n; i++)
			scanf("%d", &numbers[i]);
		FindGreatedstSumOfSubArray(numbers, n);
		

		scanf("%d", &n);
	}

	system("pause");
	return 0;
}
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

#define MAX 100000

void Swap(unsigned long *a, unsigned long *b)
{
	unsigned long tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}



//随机产生快排的基准点的位置
int Rand(int a, int b)
{
	return (int)(a + rand() % (b - a + 1));
}

//采用挖坑、从字符串两边“同时”开始比较的方法，常见的方法
//需要一个额外的空间O(1)保存基准值
int QuickSortPartition1(unsigned long *arr, int left, int right)
{
	if (arr == NULL || left < 0 || right < 0 || left > right)
		return 0;
	int rand_num = Rand(left, right); //随机产生基准点
	//cout << rand_num << endl;
	//int rand_num = left;
	//将基准值和字符串的第一个字符交换，这样第一个位置的字符变成基准值，
	//基准值保存在ref中，就在第一个位置产生了空缺位
	Swap(&arr[rand_num], &arr[left]);
	unsigned long ref = arr[left]; 
	int i, j;
	i = left;
	j = right;
	while (i < j)
	{
		//先从后面向前面比较 （因为基准值放在字符串的第一个，将小的填到基准值的）
		while (i < j && arr[j] >= ref)
			j--;
		//填补空缺
		if (i < j)
		{
			arr[i] = arr[j];
			i++;
		}
		//从前往后比较
		while (i < j && arr[i] <= ref)
			i++;
		if (i < j)
		{
			arr[j] = arr[i];
			j--;
		}
	}
	//最后的空缺在i=j处，将ref的值放到“中间”，前面小于该值，后面的大于该值
	arr[i] = ref;
	//i值将这个字符串分为了三部分，返回这个i值，便于之后分治的进行
	return i;
}

bool CheckMoreThanHalf(unsigned long *numbers, int length, unsigned long result)
{
	int count = 0;
	for (int i = 0;i < length; i++)
	{
		if (numbers[i] == result)
			count ++;
	}
	if (count * 2 <= length)
		return false;
	else
		return true;
}


int MoreThanHalfNum1(unsigned long *numbers, int length)
{
	if (numbers == NULL || length <= 0)
	{
		printf("-1\n");
		return 0;
	}
	int middle = length >> 1;
	int left = 0, right = length - 1, index;
	index = QuickSortPartition1(numbers, left, right);
	while (index != middle)
	{
		if (index < middle)
			index = QuickSortPartition1(numbers, index + 1, right);
		else if(index > middle)
			index = QuickSortPartition1(numbers, left, index - 1);
	}
	unsigned long result = numbers[middle];

	int count = 0;
	for (int i = 0;i < length; i++)
	{
		if (numbers[i] == result)
			count ++;
	}
	if (count * 2 <= length)
		printf("-1\n");
	else
		printf("%lu\n", result);

	return 0;
}

int MoreThanHalfNum2(unsigned long *numbers, int length)
{
	int i;
	int count = 1;
	unsigned long num = numbers[0];
	for (i = 0; i < length; i++)
	{
		if (count == 0)
		{
			count = 1;
			num = numbers[i];
		}
		else if (numbers[i] != num)
			count --;
		else
			count ++;
	}
	if (!CheckMoreThanHalf(numbers, length, num))
		printf("-1\n");
	else
		printf("%lu\n", num);
	return 0;
}



int main(void)
{
	int  n;

	while (scanf("%d", &n) != EOF)
	{
		unsigned long numbers[MAX];
		for (int i = 0; i < n; i++)
			scanf("%lu", &numbers[i]);
		MoreThanHalfNum1(numbers, n);


	}

	system("pause");
	return 0;
}
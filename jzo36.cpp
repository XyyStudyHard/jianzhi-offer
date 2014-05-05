#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX 100005

unsigned long long InversePairsCore(int *copy, int *num, int start, int end)
{
	if (start == end)
	{
		copy[start] = num[start];
		return 0;
	}
	int length = (end - start) / 2;
	int left = InversePairsCore(copy, num, start, start + length);
	int right = InversePairsCore(copy, num ,start + length + 1, end);

	//分别指向用于归并的两个串和归并后串的末尾
	int i = start + length;
	int j = end;
	int copy_index = end;
	unsigned long long count = 0;  //逆序对的个数

	while (i >= start && j >= start + length + 1)
	{
		if (num[i] > num[j])
		{
			copy[copy_index --] = num[i --];
			count += j - start - length;
		}
		else
			copy[copy_index --] = num[j --];
	}
	while (i >= start)
		copy[copy_index --] = num[i --];
	while (j >= start + length + 1)
		copy[copy_index --] = num[j --];
	for (i = start; i <= end; i++)
	{
		num[i] = copy[i];
	}

	count = left + right + count;
	return count;
}

unsigned long long InversePairs(int *num, int length)
{
	if (num == NULL || length <= 0)
		return 0;
	int *copy = new int[length];
	unsigned long long count = InversePairsCore(copy, num, 0, length - 1);
	delete[] copy;
	return count;
}


int main(void)
{
	int num[MAX], n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);
		unsigned long long count = InversePairs(num, n);
		printf("%llu\n", count);
	}

	system("pause");
	return 0;
}


#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 10001

bool VerifySquenceOfBST(unsigned long *arr, int n)
{
	int i;
	if (arr == NULL || n <= 0)
		return false;
	unsigned long int root = arr[n - 1];
	for (i = 0;i < n - 1; i++)
	{
		if (arr[i] > root)
			break;
	}
	int j;
	for (j = i; j < n - 1; j ++)
	{
		if (arr[j] < root)
			return false;
	}
	//left child tree
	bool left = true;;
	if (i > 0)
		left = VerifySquenceOfBST(arr, i);
	//right child tree
	bool right = true;
	if (j < n - 1)
		right = VerifySquenceOfBST(arr + i, n - i - 1);
	return (left && right);
}

int main(void)
{
	int n;
	unsigned long arr[MAX];
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			scanf("%lu", &arr[i]);
		if (VerifySquenceOfBST(arr, n))
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	system("pause");
    return 0;
}
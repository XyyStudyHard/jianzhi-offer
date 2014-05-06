#include <iostream>
#include <cstdio>


using namespace std;

#define MAX 10006

int GetFirstK(int *arr, int k, int start, int end)
{
	if (start > end)
		return -1;
	int middle_index = (start + end) / 2;
	int middle_data = arr[middle_index];
	if (middle_data == k)
	{
		if ((middle_index > 0 && arr[middle_index - 1] != k) || middle_index == 0)
			return middle_index;
		else
			end = middle_index - 1;
	}
	else if (middle_data > k)
		end = middle_index - 1;
	else if (middle_data < k)
		start = middle_index + 1;

	return GetFirstK(arr, k, start, end);
}

int GetLastK(int *arr, int k, int start, int end, int length)
{
	if (start > end)
		return -1;
	int middle_index = (start + end) / 2;
	int middle_data = arr[middle_index];
	if (middle_data == k)
	{
		if ((middle_index < length - 1 && arr[middle_index + 1] != k) || middle_index == length - 1)
			return middle_index;
		else
			start = middle_index + 1;
	}
	else if (middle_data > k)
		end = middle_index - 1;
	else if (middle_data < k)
		start = middle_index + 1;

	return GetLastK(arr, k, start, end, length);
}

int GetNumberOfK(int *arr, int n, int k)
{
	if(arr == NULL || n <= 0)
		return 0;
	int first = GetFirstK(arr, k, 0, n - 1);
	int last = GetLastK(arr, k, 0, n - 1, n);
	if (first != -1 && last != -1)
		return last - first + 1;
	else
		return 0;
}


int main(void)
{
	int m, n, k, count = 0;
	int arr[MAX];
	while (cin >> n)
	{
		for (int i = 0;i < n; i++)
			scanf("%d", &arr[i]);
		cin >> m;
		while (m --)
		{
			cin >> k;
			count = GetNumberOfK(arr, n, k);
			cout << count << endl;
		}
	}


	system("pause");
	return 0;
}


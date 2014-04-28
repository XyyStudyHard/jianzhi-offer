#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

#define MAX 10

void Swap(char *a, char *b)
{
	char tmp;
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
int QuickSortPartition1(char *arr, int left, int right)
{
	if (arr == NULL || left < 0 || right < 0 || left > right)
		return 0;
	int rand_num = Rand(left, right); //随机产生基准点
	//cout << rand_num << endl;
	//int rand_num = left;
	//将基准值和字符串的第一个字符交换，这样第一个位置的字符变成基准值，
	//基准值保存在ref中，就在第一个位置产生了空缺位
	Swap(&arr[rand_num], &arr[left]);
	char ref = arr[left]; 
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

//另外一种是看到剑指offer上面的快排方法。（快排是一种不稳定的排序算法）
//只用了一个循环，从字符串开头遍历到字符串尾，不是跟之前一样两边遍历
int QuickSortPartition2(char *arr, int left, int right)
{
	if (arr == NULL || left < 0 || right < 0 || left >= right)
		return 0;
	int rand_num = Rand(left, right);
	//将基准值放到字符串尾，便于之后的循环比较与位置互换
	Swap(&arr[rand_num], &arr[right]);
	
	//注意small位置指针的重要作用
	//它指向已经交换的最后的那个位置
	int small = left - 1;
	for (int i = left; i < right; i++)
	{
		//将比基准值大的字符放过，遇到比其小的数字则将其和small指向的位置进行交换
		//在small之前的字符都是交换过的，也就是比基准值小的，在small之后i之前的字符
		//都是没有交换过且比基准值大的！这样就能保证每次交换的时候，都是找到了小的
		//字符和之前大的字符进行交换。达到了我们的目的
		if (arr[i] < arr[right])
		{
			++small;
			//减少不必要的交换
			if (small != i)
				Swap(&arr[small], &arr[i]);
		}
	}
	++small; 
	//small变成大的数的第一个位置，则将它和基准值交换
	Swap(&arr[small], &arr[right]);
	return small;
}



void QuickSort(char *arr, int left, int right)
{
	if (arr == NULL || left < 0 || right < 0 || left >= right)
		return;
	int i = QuickSortPartition1(arr, left, right);
	//int i = QuickSortPartition2(arr, left, right);
	if (i > left)
		QuickSort(arr, left, i - 1);
	if (i < right)
		QuickSort(arr, i + 1, right);
}

//判断在数组arr中的[n和end)位之间是否有与arr[end]重复的字符
bool IsSwap(char *arr, int begin, int end)
{
	for (int k = begin; k < end; k++)
	if (*(arr + k) == *(arr + end))
		return false;
	return true;
}

//全排列就是从第一个数字起每个数分别与它后面的数字交换
//递归算法。考虑输入的字符有重复的情况!
void FullPermutation(char *arr, int len, int index)
{
	int i;
	if (index == len)
	{
		printf("%s\n", arr);
		return;
	}
	for (i = index; i <= len; i++)
	{
		//arr[index..i)之间没有和arr[i]重复的字符，则为true
		if (IsSwap(arr, index, i))
		{
			Swap(arr + index, arr + i);
			FullPermutation(arr, len, index + 1);
			Swap(arr + index, arr + i);
		}
	}
}






void sub(char *arr, vector<char> &path, vector<bool> &used)
{
	int len = strlen(arr);
	if (path.size() == len)
	{
		for (int i = 0; i < len; i++)
			printf("%c", path[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < len; i++)
	{
		//避免使用已经用到了的数字。排序后，相同的数都是相邻的了,为了避免重复的输出
		if (used[i] || (i != 0 && arr[i] == arr[i - 1] && used[i - 1]))
			continue;
		used[i] = true;
		path.push_back(arr[i]);
		sub(arr, path, used);
		used[i] = false;
		path.pop_back();
	}
}

//普通计算全排列的递归算法，递归打印下一个排列，可以按字典序打印
void FullPermutation3(char *arr)
{
	vector<bool> used(strlen(arr), false);
	vector<char> path;
	sub(arr, path, used);
}







void Reverse(char *arr, int start, int end)
{
	while (start < end)
	{
		Swap(&arr[start], &arr[end]);
		start++;
		end--;
	}
}

//计算下一个全排列，这样来得到全排列
//从后向前扫描，直到遇到相邻的两个是降序的（从右到左看是升序的），小的那个数就是我们要找的（替换数）
//再将该数和从右到左的比它大的第一个数交换，再把替换点之后的数字颠倒，即得下一个排列
bool NextPermutation(char *arr)
{
	if (arr == NULL)
		return false;
	int end = strlen(arr) - 1;
	int bigger;
	for (int i = end; i > 0;)
	{
		int j = i;
		i--;
		//找到降序的两个数，小的数为替换数
		if (arr[i] < arr[j])
		{
			//查找需要替换的数，即从右向左第一个比替换数大的数
			//且肯定存在
			bigger = end;
			while (bigger > i && arr[bigger] <= arr[i])
				--bigger;
			Swap(&arr[bigger], &arr[i]);
			//将替换数之后的数字反转
			Reverse(arr, j, end);
			return true;
		}
	}
	Reverse(arr, 0, end);
	return false;
}

//全排列的非递归算法
void FullPermutation2(char *arr)
{
	if (arr == NULL)
		return;
	do
	{
		printf("%s\n", arr);
	} while (NextPermutation(arr));
}



int main(void)
{
	char arr[MAX];

	while (cin >> arr)
	{
		if (arr == NULL)
			continue;
		
		//该递归解法。无法得到字典序，就算先进行排序也无法得到
		//FullPermutation(arr, strlen(arr) - 1, 0);
		//非递归解法
		//要得到字典序，先对字符串进行排序，使用的快排
		QuickSort(arr, 0, strlen(arr) - 1);
		//FullPermutation2(arr);
		//递归算法，这个可以得到字典序
		FullPermutation3(arr);
	}

	system("pause");
	return 0;
}
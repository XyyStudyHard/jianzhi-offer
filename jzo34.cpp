#include <iostream>
#include <cstdio>

using namespace std;

bool IsUglyNumber(int number)
{
	if (number <= 0)
		return false;
	while (number % 2 == 0)
		number = number / 2;
	while (number % 3 == 0)
		number = number / 3;
	while (number % 5 == 0)
		number = number / 5;
	return (number == 1) ? true : false;
}

//这种一个一个判断的方法效率低，超时了
int GetUglyNumber(int n)
{
	int count = 0, number = 0;
	if (n <= 0)
		return 0;
	while (count < n)
	{
		++number;
		if (IsUglyNumber(number))
			++ count;
	}

	return number;
}

int Min(int a, int b, int c)
{
	int min = (a < b) ? a : b;
	min = (min < c) ? min : c;
	return min;
}


//空间换时间，从小到大存储生成的丑数.效率高
int GetUglyNumber2(int n)
{
	if (n <= 0)
		return 0;
	//用来存储生成的n个丑数
	int *pUglyNumber = new int[n];
	pUglyNumber[0] = 1; //first uglynumber is 1
	int nexUnglyIndex = 1;
	//初始化各个乘数的开始的位置
	int *pMultiply2 = pUglyNumber;
	int *pMultiply3 = pUglyNumber;
	int *pMultiply5 = pUglyNumber;

	while (nexUnglyIndex < n)
	{
		pUglyNumber[nexUnglyIndex] = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		
		while (*pMultiply2 * 2 <= pUglyNumber[nexUnglyIndex])
			++pMultiply2;
		while (*pMultiply3 * 3 <= pUglyNumber[nexUnglyIndex])
			++pMultiply3;
		while (*pMultiply5 * 5 <= pUglyNumber[nexUnglyIndex])
			++pMultiply5;

		++ nexUnglyIndex;
	}
	int ugly = pUglyNumber[nexUnglyIndex - 1];
	delete[] pUglyNumber;
	return ugly;
}



int main(void)
{
	int n, number = 0;
	while (cin >> n)
	{
		number = GetUglyNumber2(n);
		printf("%d\n", number);



	}


	system("pause");
	return 0;
}


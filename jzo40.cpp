#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 10006

void FindNumsAppearOnce(int *num, int n)
{
	if (num == NULL || n < 2)
		return ;
	int i, xor_result = 0;
	for (i = 0; i < n; i ++)
		xor_result ^= num[i];
	int first_one = 0;

	while(((xor_result & 1) == 0) && (first_one < 8 * sizeof(int)))
	{
		xor_result = xor_result >> 1;
		first_one ++;
	}
	int index_bit = 1;
	int num1 = 0, num2 = 0;
	index_bit = index_bit << first_one;
	for (i = 0;i < n; i ++)
	{
		if (index_bit & num[i])
			num1 ^= num[i];
		else
			num2 ^= num[i];
	}
	if (num1 < num2)
		cout << num1 << " " << num2 << endl;
	else
		cout << num2 << " " << num1 << endl;
}




int main(void)
{
	int n;
	int num[MAX];
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);
		FindNumsAppearOnce(num, n);
	}

	system("pause");
	return 0;
}


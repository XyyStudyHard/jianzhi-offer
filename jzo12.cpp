#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

/*
bool increment(char *num)
{
	int jinwei = 0;
	bool overflow = false;
	int length = strlen(num);
	for (int i = length - 1; i >= 0; i--)
	{
		if (i == length - 1)
			num[i] ++;
		int nsum = num[i] - '0' + jinwei;
		if (nsum >= 10)
		{
			if (i == 0)
				overflow = true;
			else
			{
				nsum = nsum - 10;
				num[i] = nsum + '0';
				jinwei = 1;
			}
		}
		else
		{
			num[i] = '0' + nsum;
			break;
		}
	}
	return overflow;
}
*/

int PrintNumber(char *num)
{
	int length = strlen(num);
	int i;
	for (i = 0; num[i] == '0' && num[i] != '\0'; i ++);
	if (i == length)
		return 0;

	for (;i < length; i ++)
		printf("%c",num[i]);
	printf("\n");
	return 0;
}

int FullPermutation(char *num, int length, int index)
{
	if (index == length - 1)
	{
		PrintNumber(num);
		return 0;
	}
	for (int i = 0; i < 10; i ++)
	{
		num[index + 1] = i + '0';
		FullPermutation(num, length, index + 1);
	}
	return 0;
}


int main()
{
	int N;
	cin >> N;
	if (N < 0)
		return 0;
	/* haven't consider big data!
	int max = 1;
	while (N --)
	{
		max = max * 10;
	}
	for (int i = 1; i < max; i ++)
		printf("%d\n", i);
	*/

	//if N is very big, we need array to store the number, but not an int.
	//first solution, use big data plus 1, then print out every result
	/*
	char *num = new char[N + 1];
	memset(num, '0', N);
	num[N] = '\0';
	while (!increment(num))
		PrintNumber(num);
	delete num;
	*/
	
	//second solution, this question is equal to "full permutation";
	// it can use recursion
	char *num = new char[N + 1];
	memset(num, '0', N);
	num[N] = '\0';
	int length = strlen(num);
	for (int i = 0;i < 10; i ++)
	{
		num[0] = i + '0';
		FullPermutation(num, N, 0);
	}
	delete num;


	system("pause");
    return 0;
}
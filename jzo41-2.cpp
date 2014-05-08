#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;



void FindContinousSequenceOfSum(int sum)
{
	if (sum < 3)
	{
		printf("Pity!\n#\n");
		return;
	}
	int small = 1, big = 2;
	int current_sum = small + big, middle = (1 + sum) / 2;
	bool tf = false;
	while(small < middle)
	{
		if (current_sum == sum)
		{
			for (int i = small; i <= big; i++)
			{
				printf("%d", i);
				if (i != big)
					printf(" ");
				else
					printf("\n");
			}
			big ++;
			current_sum += big;
			tf = true;
		}
		else if (current_sum > sum)
		{
			current_sum -= small;
			small ++;
		}
		else 
		{
			big ++;
			current_sum += big;
		}
	}
	if (tf == false)
		printf("Pity!\n");
	printf("#\n");

}

/*剑指offer给的答案似乎很慢，要400ms以上，但是这种方法大约在100ms的样子。
主要思路是这样的：
S = ( a0 + aN)N/2 ---- 等差数列求和公式
   = ( 2a0 - 1 + N )N /2

==>  2a0 = 2S/N - N + 1  (设b = 2 * a0)
==>  2S % N == 0 && N < sqrt(2S) && b % 2 == 0

for N =  [ 2 , sqrt(2S) )
      if 2S % N == 0 && 2a0 % 2 == 0
            show( a0 , N )
*/
void FindContinousSequenceOfSum2(int sum)
{
	int a0, flag = 0, b;
	if (sum < 3)
	{
		printf("Pity!\n#\n");
		return ;
	}
	for (int i = sqrt(2 * sum); i >= 2; i--)
	{
		if ((2 * sum) % i == 0)
		{
			b = 2 * sum / i - i + 1;
			//如果b(等于2 * a0)是2的倍数，就表示存在a0
			//还要注意这个判断中的b & 1要用括号
			if ((b & 1) == 0)
			{
				flag = 1;
				a0 = b / 2;
				for (int j = 0; j < i; j ++)
				{
					printf("%d", a0 + j);
					if (j < i - 1)
						printf(" ");
					else
						printf("\n");
				}
			}
		}
	}
	if (flag == 0)
		printf("Pity!\n");
	printf("#\n");

}


int main(void)
{
	int n;
	scanf("%d", &n);
	while(n >= 0)
	{
		FindContinousSequenceOfSum2(n);

		scanf("%d", &n);
	}

	system("pause");
	return 0;
}


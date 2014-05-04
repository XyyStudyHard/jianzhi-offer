#include <iostream>
#include <cstdio>


using namespace std;

unsigned long long NumberOf1Between1AndN(unsigned long long n)
{
	//0           : 0
	//0~9         : 10 * 0 + 1 = 1
	//0~99        : 10 * 1 + 10 = 20
	//0~999       : 10 * 20 + 100 = 300
	//0~9999      : 10 * 300 + 1000 = 4000
	unsigned long long up_to_nine = 0;
	unsigned long long weight = 1;
	int x; //数当前位的值
	unsigned long long tmp = n, count = 0;
	while (tmp)
	{
		x = tmp % 10;
		count += x * up_to_nine;
		
		if (x > 1)
			count += weight; //若该位大于1，则当前位为1的个数为10^(m -1)
		else if (x == 1)
			count += n % weight + 1; //若该位为1，则当前位为1的个数就为该位右边的数字组成的数+1
		 
		up_to_nine = up_to_nine * 10 + weight;
		weight = weight * 10;
		tmp = tmp / 10;
	}
	return count;
}

int main(void)
{
	unsigned long long a, b;
	int counta = 0, countb = 0;
	
	while (cin >> a >> b)
	{
		if (a > b)
		{
			unsigned long long tmp = a;
			a = b; 
			b = tmp;
		}
		if (a == 0)
			counta = 0;
		else
			counta = NumberOf1Between1AndN(a - 1);
		countb = NumberOf1Between1AndN(b);
		printf("%d\n", countb - counta);
	
	}

	system("pause");
	return 0;
}
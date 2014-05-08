#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int Add(int num1, int num2)
{
	int sum, carry;
	do {
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;
		num1 = sum;
		num2 = carry;
	}while (num2 != 0);

	return num1;
}




int main(void)
{
	int m, n;
	while (cin >> m >> n)
	{
		int sum = Add(m, n);
		printf("%d\n", sum);
	}


	system("pause");
	return 0;
}


#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;
#define MAX 100001

bool StackSequence(int *num1, int *num2, int n)
{
	stack<int> stk;
	if (num1 == NULL || num2 == NULL || n <= 0)
		return false;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		while (stk.empty() || stk.top() != num2[i])
		{
			if (j >= n)
				return false;
			stk.push(num1[j]);
			j++;
		}

		if (stk.top() == num2[i])
			stk.pop();
	}
	return true;
}

int main(void)
{
	int n, num1[MAX], num2[MAX], i;
	while (cin >> n)
	{
		for (i = 0; i < n; i++)
			cin >> num1[i];
		for (i = 0; i < n; i++)
			cin >> num2[i];
		if (StackSequence(num1, num2, n))
			printf("Yes\n");
		else
			printf("No\n");
	}

	system("pause");
	return 0;
}
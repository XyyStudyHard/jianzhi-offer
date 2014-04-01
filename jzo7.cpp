#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int push(stack<int> &stack1, int num)
{
	stack1.push(num);
	return 0;
}

int pop(stack<int> &stack1, stack<int> &stack2)
{
	int num;
	if (!stack2.empty())
	{	
		num = stack2.top();
		stack2.pop();
		return num;
	}
	if (stack1.empty())
		return -1;
	while (!stack1.empty())
	{
		num = stack1.top();
		stack2.push(num);
		stack1.pop();
	}
	stack2.pop();
	return num;

}

int main(void)
{
	int n, num;
	string cmds;
	stack<int> stack1;
	stack<int> stack2;
	cin >> n;
	while (n --)
	{
		cin >> cmds;
		if (cmds == "PUSH")
		{
			cin >> num;
			push(stack1, num);
		}
		if (cmds == "POP")
		{
			num = pop(stack1, stack2);
			cout << num << endl;
		}
		
	}

	system("pause");
	return 0;
}
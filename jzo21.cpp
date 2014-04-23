#include <iostream>
#include <stack>

using namespace std;

int push(stack<int>&stack1, stack<int>&stack_min, int num)
{
	int min;
	stack1.push(num);
	if (stack_min.empty())
	{
		stack_min.push(num);
	//	cout << num << endl;
		return 0;
	}
	min  = stack_min.top();
	if (min <= num)
		stack_min.push(min);
	else
		stack_min.push(num);
	//cout << stack_min.top() << endl;
	return 0;
}

int pop(stack<int>&stack1, stack<int>&stack_min)
{
	if (stack1.empty() && stack_min.empty())
	{
	//	cout << "NULL" << endl;
		return 0;
	}
	else
	{
		stack1.pop();
		stack_min.pop();
	}
	return 0;
}

int min_top(stack<int>stack)
{
	if (stack.empty())
		cout << "NULL" << endl;
	else
		cout << stack.top() << endl;
	return 0;
}


int main(void)
{
	int n, num;
	char op;
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while(cin >> n)
	{
		stack<int> stack1, stack_min;
		while (n --)
		{
			cin >> op;
			if (op == 's')
			{
				cin >> num;
				push(stack1, stack_min, num);
				min_top(stack_min);
			}
			else if (op == 'o')
			{
				pop(stack1, stack_min);
				min_top(stack_min);
			}
			
		}
	}
	
	
	system("pause");
    return 0;
}
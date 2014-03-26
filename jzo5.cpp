#include <iostream>
#include <stack>

/*
#include <cstdio>
use scanf(), printf() can make it faster!
*/

using namespace std;

typedef struct node_list
{
	int value;
	node_list *next;
}node_list;

node_list *create_list(node_list **root)
{
	node_list *tmp = NULL, *head = NULL;
	int value;
	cin >> value;
	if (value == -1)
		return 0;
	head = new(node_list);
	if (head == NULL) return 0;
	head->value = value;
	tmp = head;
	cin >> value;
	while (value != -1)
	{
		tmp->next = new(node_list);
		tmp = tmp->next;
		tmp->value = value;
		cin >> value;
	}
	tmp->next = NULL;
	*root = head;
	return head;
}

int main(void)
{
	stack<node_list *> node;
	node_list *root = NULL, *index = NULL, *tmp = NULL;
	create_list(&root);

	index = root;
	while(index != NULL)
	{
		node.push(index);
		index = index->next;
	}

	while(!node.empty())
	{
		index = node.top();
		cout << index->value << endl;
		node.pop();
	}

	index = root;
	while(index != NULL)
	{
		tmp = index->next;
		delete(index);
		index = tmp;
	}

	system("pause");
	return 0;
}
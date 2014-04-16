#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node *next;
};

void CreateList(Node **root, int n)
{
	int i, tmp;
	Node *index;
	if (n <= 0)
		return ;
	*root = new Node;
	cin >> (*root)->value;
	(*root)->next = NULL;
	
	index = *root;
	for (i = 1; i < n; i ++)
	{
		cin >> tmp;
		index->next = new Node;
		index = index->next;
		index->value = tmp;
		index->next = NULL;
	}
	return ;
}

void DeleteList(Node **root)
{
	Node *index, *tmp;
	index = *root;
	if (index == NULL)
		return ; 
	while (index == NULL)
	{
		tmp = index;
		index = index->next;
		delete tmp;
	}
	return ;
}

/*
Node *ReverseList(Node *root)
{
	Node *index, *preindex, *aftindex;
	index = root;
	if (root == NULL)
		return NULL;
	aftindex = index->next;
	while(aftindex)
	{
		preindex = aftindex;
		aftindex = preindex->next;
		preindex->next = index;
		index = preindex;
	}
	return index;
}
*/

Node *head = NULL;

Node * RecursionList(Node *node)
{
	Node *index;
	if (node == NULL)
		return NULL;
	if (node->next == NULL)
	{
		head = node;
		return node;
	}
	index = RecursionList(node->next);
	
	index->next = node;
	node->next = NULL;
	return node;
}

int main(void)
{
	int n, i;
	Node *root = NULL, *index, *ListHead;

	while (cin >> n)
	{
		if (n <= 0)
		{
			cout << "NULL" << endl;
			continue;
		}
		CreateList(&root, n);
		//ListHead = ReverseList(root);
		ListHead = RecursionList(root);
		index = head;
		for (i = 0; i < n; i++)
		{
			cout << index->value;
			if (i != n - 1)
				cout << " ";
			index = index->next;
		}
		cout << endl;
		DeleteList(&ListHead);
	}

	
	system("pause");
    return 0;
}
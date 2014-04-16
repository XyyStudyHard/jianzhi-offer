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
Node * MergeList(Node *root1, Node *root2)
{
	Node *root = NULL;
	if (root1 == NULL)
		return root2;
	if (root2 == NULL)
		return root1;
	Node *index1, *index2, *index;
	if (root1->value <= root2->value)
	{	
		root = root1;
		index1 = root1->next;
		index2 = root2;
	}
	else
	{
		root = root2;
		index1 = root1;
		index2 = root2->next;
	}
	index = root;
	while ((index1 != NULL) && (index2 != NULL))
	{
		if (index1->value <= index2->value)
		{
			index->next = index1;
			index = index->next;
			index1 = index1->next;
		}
		else
		{
			index->next = index2;
			index = index->next;
			index2 = index2->next;
		}
	}
	if ((index1 == NULL) && (index2 == NULL))
		return root;
	if (index1 == NULL)
	{
		index->next = index2;
	}
	else if (index2 == NULL)
		index->next = index1;
	return root;
}
*/

Node *RecursionMergeList(Node *root1, Node *root2)
{
	if (root1 == NULL)
		return root2;
	if (root2 == NULL)
		return root1;
	Node *head = NULL;
	if (root1->value <= root2->value)
	{
		head = root1;
		head->next = RecursionMergeList(root1->next, root2);
	}
	else
	{
		head = root2;
		head->next = RecursionMergeList(root1, root2->next);
	}
	return head;
}

int main(void)
{
	int n, m;
	Node *root1 = NULL, *root2 = NULL, *index, *root;

	while (cin >> n >> m)
	{
		if (n <= 0 && m <= 0)
		{
			cout << "NULL" << endl;
			continue;
		}
		CreateList(&root1, n);
		CreateList(&root2, m);
		root = RecursionMergeList(root1, root2);
		index = root;
		while (index)
		{
			cout << index->value;
			index = index->next;
			if (index != NULL)
				cout << " ";
		}
		cout << endl;
		DeleteList(&root);
		root = NULL;
		root1 = NULL;
		root2 = NULL;
	}

	
	system("pause");
    return 0;
}
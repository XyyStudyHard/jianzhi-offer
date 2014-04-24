#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 1001

struct ComplexListNode
{
	int value;
	ComplexListNode *next;
	ComplexListNode *sibling;
};

void Create(int n, ComplexListNode **head)
{
	ComplexListNode* arr[MAX];
	int i, tmp;
	if (n <= 0)
	{
		*head = NULL;
		return ;
	}
	for (i = 0; i < n; i++)
	{
		arr[i] = new ComplexListNode;
		arr[i]->next = NULL;
		arr[i]->sibling = NULL;
		arr[i]->value = 0;
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		arr[i]->value = tmp;
		if (i != n - 1)
			arr[i]->next = arr[i + 1];
	}
	for (i = 0;  i < n; i++)
	{
		scanf("%d", &tmp);
		if (tmp != 0)
			arr[i]->sibling = arr[tmp - 1];
	}
	*head = arr[0];
}


void CloneNodes(ComplexListNode *head)
{
	ComplexListNode *index, *clone_index;
	index = head;
	while (index)
	{
		clone_index = new ComplexListNode;
		clone_index->value = index->value;
		clone_index->next = index->next;
		index->next = clone_index;
		clone_index->sibling = NULL;
		index = clone_index->next;
	}
}


void ConnectSiblingNodes(ComplexListNode *head)
{
	ComplexListNode *index = head;
	while (index)
	{
		if (index->sibling)
			index->next->sibling = index->sibling->next;
		index = index->next->next;
	}
}

ComplexListNode *ReconnectNodes(ComplexListNode *head)
{
	ComplexListNode *clone_head;
	ComplexListNode *index = head, *clone_index;
	if (head == NULL)
		return NULL;
	clone_head = index->next;
	index->next = clone_head->next;
	index = index->next;
	clone_index = clone_head;
	while (index)
	{
		clone_index->next = index->next;
		clone_index = clone_index->next;
		index->next = clone_index->next;
		index = index->next;
	}
	return clone_head;
}



ComplexListNode* Clone(ComplexListNode *head)
{
	CloneNodes(head);
	ConnectSiblingNodes(head);
	return ReconnectNodes(head);
}


void PrintSibling(ComplexListNode *head)
{
	ComplexListNode *index = head;
	if (index == NULL)
		return ;
	while (index)
	{
		if (index->sibling)
			printf("%d %d\n", index->value, index->sibling->value);
		else
			printf("%d 0\n", index->value);
		index = index->next;
	}
}


int main(void)
{
	int n;

	while (cin >> n)
	{
		ComplexListNode *head, *clone_head;
		Create(n, &head);
		clone_head = Clone(head);
		PrintSibling(clone_head);
	}


	system("pause");
    return 0;
}
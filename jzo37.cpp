#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX 1003

struct ListNode
{
	int value;
	ListNode *next;
};

ListNode *CreateList(ListNode **root, int n)
{
	if (n <= 0)
		return NULL;
	*root = new ListNode;
	ListNode *index;
	int tmp;
	cin >> tmp;
	(*root)->value = tmp;
	(*root)->next = NULL;
	index = *root;
	for (int i = 1; i < n; i++)
	{
		index->next = new ListNode;
		index = index->next;
		cin >> tmp;
		index->value = tmp;
		index->next = NULL;
	}
	return *root;
}

void DeletList(ListNode **root)
{
	if (*root == NULL)
		return;
	ListNode *index = *root, *tmp;
	while (index)
	{
		tmp = index->next;
		delete index;
		index = tmp;
	}

}

int FindFirstCommonNode(ListNode *list1, ListNode *list2, int m, int n)
{
	ListNode *index_long = NULL, *index_short = NULL;
	int lon, sht;
	if (m >= n)
	{
		lon = m;
		sht = n;
		index_long = list1;
		index_short = list2;
	}
	else
	{
		lon = n;
		sht = m;
		index_long = list2;
		index_short = list1;
	}
	for (int i = 0; i < lon - sht; i++)
		index_long = index_long->next;
	while ((index_long != NULL) && (index_short != NULL))
	{
		if (index_long->value != index_short->value)
		{
			index_long = index_long->next;
			index_short = index_short->next;
		}
		else
			break;
	}
	if (index_long != NULL && index_short != NULL)
		cout << index_long->value << endl;
	else
		cout << "My God" << endl;
	return 0;
}


int main(void)
{

	int m, n;
	while (cin >> m >> n)
	{
		ListNode *list1 = NULL;
		ListNode *list2 = NULL;
		CreateList(&list1, m);
		CreateList(&list2, n);
		FindFirstCommonNode(list1, list2, m, n);

		DeletList(&list1);
		DeletList(&list2);
	}


	system("pause");
	return 0;
}


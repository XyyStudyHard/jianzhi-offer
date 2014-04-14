#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
	int value;
	ListNode *next;
};

void FindKthToTail(ListNode *root, int k)
{
	ListNode *index1, *index2;
	if (root == NULL || k <= 0)
	{
		cout << "NULL" << endl;
		return ;
	}
	index1 = index2 = root;
	for (int i = 1; i < k; i ++)
	{
		index1 = index1->next;
		if (index1 == NULL)
		{
			cout << "NULL" << endl;
			return;
		}
	}
	while (index1->next != NULL)
	{
		index1 = index1->next;
		index2 = index2->next;
	}
	cout << index2->value << endl;
	return;
}

int main()
{
	int n, k, tmp;
	while (cin >> n >> k)
	{
		if (n <= 0)
		{
			cout << "NULL" << endl;
			continue;
		}
		ListNode *root = new ListNode;
		cin >> tmp;
		root->value = tmp;
		root->next = NULL;
		ListNode *index = root;
		while (--n)
		{
			index->next = new ListNode;
			index = index->next;
			cin >> tmp;
			index->value = tmp;
			index->next = NULL;
		}
		index = root;
		
		FindKthToTail(root, k);
	}

	system("pause");
    return 0;
}
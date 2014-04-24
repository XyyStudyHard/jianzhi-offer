#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

int num;

void CreateTree(BinaryTreeNode **root, int n)
{
	int *num = new int[n], i, tmp;
	char child_num;
	BinaryTreeNode *index, *tmpNode;
	queue<BinaryTreeNode *> Bqueue;
	if (n <= 0)
	{
		*root = NULL;
		return;
	}
	*root = new BinaryTreeNode;
	(*root)->left = NULL;
	(*root)->right = NULL;

	for (i = 0; i < n; i++)
		cin >> num[i];
	(*root)->value = num[0];
	Bqueue.push(*root);
	for (i = 0; i < n; i++)
	{
		cin >> child_num;
		index = Bqueue.front();
		Bqueue.pop();
		if (child_num == 'd')
		{
			cin >> tmp;
			tmpNode = new BinaryTreeNode;
			tmpNode->value = num[tmp - 1];
			tmpNode->left = NULL;
			tmpNode->right = NULL;
			index->left = tmpNode;
			Bqueue.push(tmpNode);
			cin >> tmp;
			tmpNode = new BinaryTreeNode;
			tmpNode->value = num[tmp - 1];
			tmpNode->left = NULL;
			tmpNode->right = NULL;
			index->right = tmpNode;
			Bqueue.push(tmpNode);
		}
		else if (child_num == 'l')
		{
			cin >> tmp;
			tmpNode = new BinaryTreeNode;
			tmpNode->value = num[tmp - 1];
			tmpNode->left = NULL;
			tmpNode->right = NULL;
			index->left = tmpNode;
			Bqueue.push(tmpNode);
		}
		else if (child_num == 'r')
		{
			cin >> tmp;
			tmpNode = new BinaryTreeNode;
			tmpNode->value = num[tmp - 1];
			tmpNode->right = NULL;
			tmpNode->left = NULL;
			index->right = tmpNode;
			Bqueue.push(tmpNode);
		}
		if (child_num == 'z')
		{
			continue;
		}
	}

	delete num;
	return;
}


int HierarchyBiTree(BinaryTreeNode *root)
{
	queue<BinaryTreeNode *> queues;
	BinaryTreeNode *index = root;
	if (root == NULL)
		return 0;
	queues.push(index);
	while (!queues.empty())
	{
		index = queues.front();
		cout << index->value;
		if (num > 1)
			cout << " ";
		num--;
		queues.pop();
		if (index->left)
			queues.push(index->left);
		if (index->right)
			queues.push(index->right);

	}
	return 0;
}


int DeleteTree(BinaryTreeNode **root)
{
	if (*root == NULL)
		return 0;
	if ((*root)->left != NULL)
		DeleteTree(&((*root)->left));
	if ((*root)->right != NULL)
		DeleteTree(&((*root)->right));
	delete *root;
	return 0;
}



int main(void)
{
	int m;
	BinaryTreeNode *root = NULL;
	while (cin >> m)
	{
		num = m;
		if (m == 0)
		{
			cout << "NULL" << endl;
			return 0;
		}
		CreateTree(&root, m);
		HierarchyBiTree(root);
		
		cout << endl;
		DeleteTree(&root);
		root = NULL;
	}

	system("pause");
	return 0;
}
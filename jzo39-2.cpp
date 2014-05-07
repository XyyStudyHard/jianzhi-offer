#include <iostream>
#include <cstdio>

using namespace std;


#define MAX 12

struct BinaryTree
{
	BinaryTree *left;
	BinaryTree *right;
};

void CreateTree(BinaryTree **root, int n)
{
	if (n <= 0)
		return ;
	BinaryTree* arr[MAX];

	for (int i = 0;i < n;i ++)
	{
		arr[i] = new BinaryTree;
		arr[i]->left = NULL;
		arr[i]->right = NULL;
	}
	int left, right;
	for (int i = 0;i < n; i++)
	{
		cin >> left >> right;
		if (left != -1)
			arr[i]->left = arr[left - 1];
		if (right != -1)
			arr[i]->right = arr[right - 1];
	}
	*root = arr[0];
}

void DeleteTree(BinaryTree **root)
{
	if ((*root) == NULL)
		return ;
	DeleteTree(&((*root)->left));
	DeleteTree(&((*root)->right));
	delete *root;
}


bool IsBalanceTreePartition(BinaryTree *root, int &depth)
{
	if (root == NULL)
	{
		depth = 0;
		return true;
	}
	int left = 0, right = 0;
	if (IsBalanceTreePartition(root->left, left) && IsBalanceTreePartition(root->right, right))
	{
		int diff = left - right;
		if (diff <= 1 && diff >= -1)
		{	depth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false;
}



bool IsBalanceTree(BinaryTree *root)
{
	if(root == NULL)
		return false;
	int depth;
	return IsBalanceTreePartition(root, depth);
}

int main(void)
{
	int n;
	while (cin >> n)
	{
		BinaryTree *root = NULL;
		CreateTree(&root, n);
		bool TF = IsBalanceTree(root);
		if (TF)
			cout << "true" << endl;
		else
			cout << "false" << endl;
		DeleteTree(&root);
	}

	system("pause");
	return 0;
}


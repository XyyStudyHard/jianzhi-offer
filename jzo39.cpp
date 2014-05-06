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

int MaxDepth(BinaryTree *root)
{
	if(root == NULL)
		return 0;
	int left = MaxDepth(root->left);
	int right = MaxDepth(root->right);
	if (left >= right)
		return left + 1;
	else
		 return right + 1;
}

int main(void)
{
	int n;
	while (cin >> n)
	{
		BinaryTree *root = NULL;
		CreateTree(&root, n);
		int depth = MaxDepth(root);
		cout << depth << endl;
		DeleteTree(&root);
	}

	system("pause");
	return 0;
}


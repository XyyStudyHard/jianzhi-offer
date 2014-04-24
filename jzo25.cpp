#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

#define MAX 10001

struct BinaryTreeNode{
	int value;
	int NO;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

void CreateTree(BinaryTreeNode ** root, int n)
{
	BinaryTreeNode *index;
	int tmp, tmp1, tmp2;
	vector<BinaryTreeNode *> node_arr;
	if ((*root) != NULL || n <= 0 )
		return ;
	for (int i = 0; i < n; i++)
	{
		index = new BinaryTreeNode;
		index->left = NULL;
		index->right = NULL;
		index->value = 0;
		index->NO = i + 1;
		node_arr.push_back(index);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		index = node_arr[i];
		index->value = tmp;
		cin >> tmp1 >> tmp2;
		if (tmp1 > tmp2)
		{
			tmp = tmp1;
			tmp1 = tmp2;
			tmp2 = tmp;
		}
		if (tmp1 != -1)
			index->left = node_arr[tmp1 - 1];
		if (tmp2 != -1)
			index->right = node_arr[tmp2 - 1];
	}
	*root = node_arr[0];
	return ;
}



void DeleteTree(BinaryTreeNode **root)
{
	BinaryTreeNode *index;
	index = *root;
	if ((*root) == NULL)
		return ;
	if (index->left)
		DeleteTree(&(index->left));
	if (index->right)
		DeleteTree(&(index->right));
	delete index;
	index = NULL;
}

void FindPathPartition(BinaryTreeNode *root, int expected_sum, int &current_sum, vector<BinaryTreeNode *> &path)
{
	// calculate the current_sum, and push this node into vector. 
	// we use vector to simulate a stack, because it can print out the path.
	current_sum += root->value;
	path.push_back(root);
	BinaryTreeNode *index;
	// if this is a leaf node, and expected_sum is equal to current_sum, print the path
	bool is_leaf = (root->left == NULL) && (root->right == NULL);
	if (current_sum == expected_sum && is_leaf)
	{
		printf("A path is found: ");
		vector<BinaryTreeNode *>::iterator iter = path.begin();
		for (; iter != path.end(); iter++)
		{
			index = *iter;
			printf("%d", index->NO);
			if (iter != path.end() - 1)
				printf(" ");
			else
				printf("\n");
		}
	}
	// it is not a leaf node, see its children
	if (root->left)
		FindPathPartition(root->left, expected_sum,  current_sum, path);
	if (root->right)
		FindPathPartition(root->right, expected_sum, current_sum, path);
	// before return to its father, delete itself from vector and
	// minus it value from current_sum
	current_sum -= root->value;
	path.pop_back();
	
}

void FindPath(BinaryTreeNode *root, int expected_sum)
{
	if (root == NULL)
		return ;
	vector<BinaryTreeNode *> path;
	int current_sum = 0;
	FindPathPartition(root, expected_sum, current_sum, path);
}

int main(void)
{
	int n, k;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> n)
	{
		BinaryTreeNode *root = NULL;
		cin >> k;
		CreateTree(&root, n);
		printf("result:\n");
		FindPath(root, k);
		DeleteTree(&root);
	}
	
    return 0;
}
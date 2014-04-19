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


void CreateTree(BinaryTreeNode **root, int n)
{
	int *num = new int[n], i, child_num, tmp;
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
	
	for (i = 0; i < n; i ++)
		cin >> num[i];
	(*root)->value = num[0];
	Bqueue.push(*root);
	for (i = 0; i < n; i++)
	{
		cin >> child_num;
		index = Bqueue.front();
		Bqueue.pop();
		if (child_num == 2)
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
		if (child_num == 1)
		{
			cin >> tmp;
			tmpNode = new BinaryTreeNode;
			tmpNode->value = num[tmp - 1];
			tmpNode->left = NULL;
			tmpNode->right = NULL;
			index->left = tmpNode;
			Bqueue.push(tmpNode);
		}
		if (child_num == 0)
		{
			continue;
		}
	}

	delete num;
	return ;
}


int InOrderRecursion(BinaryTreeNode *root)
{
	if (root == NULL)
		return 0;
	InOrderRecursion(root->left);
	cout << root->value;
	InOrderRecursion(root->right);
	return 0;
}


int InOrderTraverse(BinaryTreeNode *root)
{
	stack<BinaryTreeNode *> stacks;
	BinaryTreeNode *index = root;
	
	while (index || !stacks.empty())
	{
		if (index)
		{
			stacks.push(index);
			index = index->left;
		}
		else
		{
			index = stacks.top();
			stacks.pop();
			if (index == NULL)
				return -1;
			cout << index->value;
			index = index->right;
		}
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

bool DoesTree1HaveTree2(BinaryTreeNode *root1, BinaryTreeNode *root2)
{
	// first to judge root2, then judge root1.
	//when they are NULL at the same time, exchange them will be wrong!
	if (root2 == NULL)
		return true;
	if (root1 == NULL)
		return false;
	if (root1->value != root2->value)
		return false;
	return DoesTree1HaveTree2(root1->left, root2->left) &&
		DoesTree1HaveTree2(root1->right, root2->right);
}


bool HasSubtree(BinaryTreeNode *root1, BinaryTreeNode *root2)
{
	bool result = false;
	if (root1 != NULL && root2 != NULL)
	{
		if (root1->value == root2->value)
			result = DoesTree1HaveTree2(root1, root2);
		if (!result)
			result = HasSubtree(root1->left, root2);
		if (!result)
			result = HasSubtree(root1->right, root2);
	}
	return result;
}


int main(void)
{
	int m, n;
	bool TF;
	BinaryTreeNode *root1 = NULL, *root2 = NULL;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> m >> n)
	{
		if (n == 0)
		{
			cout << "NO" << endl;
			continue;
		}
		CreateTree(&root1, m);
		CreateTree(&root2, n);
		//InOrderTraverse(root1);
		//InOrderTraverse(root2);
		TF = HasSubtree(root1, root2);
		if (TF == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		DeleteTree(&root1);
		DeleteTree(&root2);
		root1 = root2 = NULL;
	}
	

	
	system("pause");
    return 0;
}
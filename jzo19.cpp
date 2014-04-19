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
	
	for (i = 0; i < n; i ++)
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
	return ;
}

int PreOrderRecursion(BinaryTreeNode *root)
{
	if (root == NULL)
		return 0;
	cout << root->value << " ";
	PreOrderRecursion(root->left);
	PreOrderRecursion(root->right);
	return 0;
}

int PreOrderTraverse(BinaryTreeNode *root)
{
	BinaryTreeNode *index;
	stack<BinaryTreeNode *> stacks;
	index = root;
	while (index || !stacks.empty())
	{
		if (index)
		{
			cout << index->value;
			num --;
			if (num != 0)
				cout << " ";
			stacks.push(index);
			index = index->left;
			
		}
		else
		{
			index = stacks.top();
			stacks.pop();
			index = index->right;
		}
	}
	return 0;
}


int InOrderRecursion(BinaryTreeNode *root)
{
	if (root == NULL)
		return 0;
	InOrderRecursion(root->left);
	cout << root->value << " ";
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


void MirrorRecursively(BinaryTreeNode *node)
{
	if(node == NULL || ((node->left == NULL) && (node->right == NULL)))
		return ;
	BinaryTreeNode *tmp;
	tmp = node->left;
	node->left = node->right;
	node->right = tmp;

	if (node->left)
		MirrorRecursively(node->left);
	if (node->right)
		MirrorRecursively(node->right);
	return ;
}


int main(void)
{
	int m;
	BinaryTreeNode *root = NULL;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> m)
	{
		num = m;
		if (m == 0)
		{
			cout << "NULL" << endl;
			return 0;
		}
		CreateTree(&root, m);
		
		MirrorRecursively(root);
		//PreOrderRecursion(root);
		//cout << endl;
		PreOrderTraverse(root);
		cout << endl;
		DeleteTree(&root);
		root = NULL;
	}
	

	
	system("pause");
    return 0;
}
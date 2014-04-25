#include <iostream>
#include <cstdio>

using namespace std;

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


void CreateTree(BinaryTreeNode ** root)
{
	//BinaryTreeNode *index;
	int value;
	cin >> value;
	if (value != 0)
	{
		(*root) = new BinaryTreeNode;
		(*root)->value = value;
		(*root)->left = NULL;
		(*root)->right = NULL;
		CreateTree(&(*root)->left);
		CreateTree(&((*root)->right));
	
	}
	
}

void ConvertNode(BinaryTreeNode *root, BinaryTreeNode **last_node)
{
	if (root == NULL)
		return;
	BinaryTreeNode *current = root;
	if (root->left != NULL)
		ConvertNode(current->left, last_node);

	current->left = *last_node;
	if (*last_node != NULL)
		(*last_node)->right = current;
	*last_node = current;
	
	if (current->right != NULL)
		ConvertNode(current->right, last_node);
}


BinaryTreeNode* ConvertToList(BinaryTreeNode *root)
{
	if (root == NULL)
		return NULL;
	BinaryTreeNode *last_node = NULL;
	ConvertNode(root, &last_node);

	BinaryTreeNode *head = last_node;
	while (head->left != NULL && head != NULL)
		head = head->left;
	return head;
}


void DeleteTree(BinaryTreeNode **root)
{
	if((*root) == NULL)
		return ;
	BinaryTreeNode *index = *root;
	BinaryTreeNode *tmp = index;
	while (index)
	{
		tmp = index;
		index = index->right;
		delete (tmp);
	}
}

void PrintList(BinaryTreeNode *head)
{
	if(head == NULL)
		return ;
	BinaryTreeNode *index = head;
	while (index)
	{
		cout << index->value << " ";
		index = index->right;
	}

}


int main(void)
{
	int n;
	cin >> n;
	while (n --)
	{
		BinaryTreeNode *root = NULL;
		CreateTree(&root);
		root = ConvertToList(root);
		PrintList(root);
		cout << endl;
		DeleteTree(&root);

	}
	

	system("pause");
    return 0;
}
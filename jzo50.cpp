#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define MAX 100006
bool TF = false;

struct BinaryTree
{
	int value;
	BinaryTree *left;
	BinaryTree *right;
};

BinaryTree *CreateTree(BinaryTree **root)
{
	BinaryTree *index = NULL;
	int tmp;
	cin >> tmp;
	if (tmp == 0)
		return NULL;
	(*root) = new BinaryTree;
	index = *root;
	index->value = tmp;
	index->left = NULL;
	index->right = NULL;
	CreateTree(&(index->left));
	CreateTree(&(index->right));
	return *root;
}

void DeleteTree(BinaryTree **root)
{
	if ((*root) == NULL)
		return ;
	BinaryTree *index = *root;
	DeleteTree(&(index->left));
	DeleteTree(&(index->right));
	delete index;
}

void PreOrderTraverse(BinaryTree *root)
{
	if (root == NULL)
		return;
	BinaryTree *index = root;
	PreOrderTraverse(index->left);
	cout << index->value << " ";
	PreOrderTraverse(index->right);
}

bool GetNodePath(BinaryTree *root, int value, vector<BinaryTree *> &path)
{
	BinaryTree *index;
	if (root == NULL)
		return false;
	path.push_back(root);
	if (root->value == value)
		return true;
	
	bool found = GetNodePath(root->left, value, path);
	if (found)
		return true;
	else
	{
		found = GetNodePath(root->right, value, path);
		if (found)
			return true;
		else
		{
			path.pop_back();
			return false;
		}
	}
}

BinaryTree *GetLastCommonNode(vector<BinaryTree *> path1, vector<BinaryTree *> path2)
{
	vector<BinaryTree *>::iterator iter1 = path1.begin(), iter2 = path2.begin();
	BinaryTree *last_node = 0;
	if (path1.size() == 0 || path2.size() == 0)
	{
		TF = false;
		return 0;
	}
	while (iter1 != path1.end() && iter2 != path2.end())
	{
		if (*iter1 == *iter2)
		{
			TF = true;
			last_node = *iter1;
		}
		iter1 ++;
		iter2 ++;
	}
	return last_node;
}



BinaryTree* GetLastCommonParent(BinaryTree *root, int num1, int num2)
{
	if (root == NULL)
	{
		TF = false;
		return 0;
	}
	vector<BinaryTree *> path1, path2;
	bool TF1, TF2;
	GetNodePath(root, num1, path1);
	GetNodePath(root, num2, path2);
	return GetLastCommonNode(path1, path2);
}

int main(void)
{
	int n, num1, num2;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> n;
	while (n--)
	{
		BinaryTree *root = NULL;
		CreateTree(&root);
		scanf("%d", &num1);
		scanf("%d", &num2);
		BinaryTree* common_node = GetLastCommonParent(root, num1, num2);
		if (TF == false)
			printf("My God\n");
		else
			printf("%d\n", common_node->value);

		DeleteTree(&root);
	}


	//system("pause");
	return 0;
}



/* 只用一次遍历解决LCA */
/*
#include <iostream>
using namespace std;
struct Node
{
    struct Node *left, *right;
    int key;
};
Node* newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

// 返回n1和n2的 LCA的指针
// 假设n1和n2都出现在树中
struct Node *findLCA(struct Node* root, int n1, int n2)
{
    if (root == NULL) return NULL;

    // 只要n1 或 n2 的任一个匹配即可
    //  (注意：如果 一个节点是另一个祖先，则返回的是祖先节点。因为递归是要返回到祖先的 )
    if (root->key == n1 || root->key == n2)
        return root;
    // 分别在左右子树查找
    Node *left_lca  = findLCA(root->left, n1, n2);
    Node *right_lca = findLCA(root->right, n1, n2);
    // 如果都返回非空指针 Non-NULL, 则说明两个节点分别出现了在两个子树中，则当前节点肯定为LCA
    if (left_lca && right_lca)  return root;
    // 如果一个为空，在说明LCA在另一个子树
    return (left_lca != NULL)? left_lca: right_lca;
}

//测试
int main()
{
    // 构造上面图中的树
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->key;
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->key;
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->key;
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->key;
	system("pause");
    return 0;
}
	*/

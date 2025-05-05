#include "data_types.h"
#define MAX_TREE_SIZE 100

TreeNode* creatNewTreeNode(int data)
{
	TreeNode* new_tree_node = 
		(TreeNode*)malloc(sizeof(TreeNode));
	if (!new_tree_node)
	{
		printf("Memory allocation failed\n");
		return NULL;
	}
	new_tree_node->data = data;
	new_tree_node->left = NULL;
	new_tree_node->right = NULL;
	return new_tree_node;
}

void insertTree(TreeNode** root, int data)
{
	TreeNode* new_tree_node = creatNewTreeNode(data);
	if (!*root)
	{
		*root = new_tree_node;
		return;
	}

	TreeNode* temp;
	TreeNode* queue[MAX_TREE_SIZE];
	int rear = -1;
	int front = -1;
	queue[++rear] = *root;

	while (rear != front)
	{
		temp = queue[++front];
		if (!temp->left)
		{
			temp->left = new_tree_node;
			return;
		}
		queue[++rear] = temp->left;

		if (!temp->right)
		{
			temp->right = new_tree_node;
			return;
		}
		queue[++rear] = temp->right;
	}
}

void inorderTraversal(TreeNode* root)
{
	if (!root)
		return;

	inorderTraversal(root->left);
	printf("%d ", root->data);
	inorderTraversal(root->right);
}

Node* getDeepestRightmostNode(Node* root)
{
	if (!root)
		return NULL;

	TreeNode* temp = NULL;
	TreeNode* queue[MAX_TREE_SIZE];
	int rear = -1;
	int front = -1;
	queue[++rear] = root;

	while (rear != front)
	{
		temp = queue[++front];
		if (temp->left)
			queue[++rear] = temp->left;

		if (temp->right)
			queue[++rear] = temp->right;
	}

	return temp;
}

Node* search(Node* root, int data)
{
	if (!root)
		return NULL;

	TreeNode* temp = NULL;
	TreeNode* queue[MAX_TREE_SIZE];
	int rear = -1;
	int front = -1;
	queue[++rear] = root;

	while (rear != front)
	{
		temp = queue[++front];
		if (temp->data == data)
			return temp;
		if (temp->left)
			queue[++rear] = temp->left;

		if (temp->right)
			queue[++rear] = temp->right;
	}
	return NULL;
}
void treeTest()
{
	printf("Testing the trees\n");
	TreeNode* root = NULL;
	insertTree(&root, 10);
	insertTree(&root, 20);
	insertTree(&root, 30);
	insertTree(&root, 40);
	insertTree(&root, 50);
	insertTree(&root, 60);
	insertTree(&root, 70);
	insertTree(&root, 80);

	inorderTraversal(root);
	printf("\n");

	TreeNode* test = getDeepestRightmostNode(root);
	printf("%d\n", test->data);
	int value = 16;
	test = search(root, 16);
	if (test)
		printf("Value %d found", test->data);
	else
		printf("Value %d not fond", value);
}

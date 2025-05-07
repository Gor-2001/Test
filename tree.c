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

TreeNode* getDeepestRightmostNode(TreeNode* root)
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

TreeNode* search(TreeNode* root, int data)
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

void deleteDeepestRightmostNode(TreeNode* root, TreeNode* dNode)
{
	TreeNode* temp = NULL;
	TreeNode* queue[MAX_TREE_SIZE];
	int rear = -1;
	int front = -1;
	queue[++rear] = root;

	while (rear != front)
	{
		temp = queue[++front];
		if (temp == dNode)
		{
			temp = NULL;
			free(dNode);
			return;
		}
		if (temp->right != NULL) 
		{
			if (temp->right == dNode) 
			{
				temp->right = NULL;
				free(dNode);
				return;

			}
			else 
			{
				queue[++rear] = temp->right;
			}
		}

		if (temp->left != NULL)
		{
			if (temp->left == dNode)
			{
				temp->left = NULL;
				free(dNode);
				return;
			}
			else
			{
				queue[++rear] = temp->left;
			}
		}
	}
	return;
}
void delete (TreeNode** root, int data)
{
	if (!(*root))
	{
		printf("Tree is empty.\n");
		return;
	}

	if (!((*root)->left) && !((*root)->right))
	{
		if ((*root)->data == data)
		{
			free(*root);
			*root = NULL;
			return;
		}
		else
		{
			printf("Node not found.\n");
			return;
		}
	}

	TreeNode* temp = NULL;
	TreeNode* key = NULL;
	TreeNode* queue[MAX_TREE_SIZE];
	int rear = -1;
	int front = -1;
	queue[++rear] = *root;

	while (rear != front)
	{
		temp = queue[++front];
		if (temp->data == data)
			key = temp;
		if (temp->left)
			queue[++rear] = temp->left;
		if (temp->right)
			queue[++rear] = temp->right;
	}

	if (key)
	{
		temp = getDeepestRightmostNode(*root);
		key->data = temp->data;
		deleteDeepestRightmostNode(*root, temp);
	}
	else
		printf("Node not found.\n");
}

void treeTest()
{
	TreeNode* root = NULL;

	// Inserting nodes
	insertTree(&root, 20);
	insertTree(&root, 30);
	insertTree(&root, 40);
	insertTree(&root, 50);
	insertTree(&root, 60);
	insertTree(&root, 70);
	insertTree(&root, 80);

	// Inorder traversal
	printf("Inorder traversal of the given Tree is: ");
	inorderTraversal(root);
	printf("\n");

	// Deleting a node
	int deleteValue = 20;
	delete (&root, deleteValue);
	printf("After deletion of %d: ", deleteValue);
	inorderTraversal(root);
	printf("\n");

	// Inserting a new node
	int insertValue = 25;
	insertTree(&root, insertValue);
	printf("After insertion of %d: ", insertValue);
	inorderTraversal(root);
	printf("\n");

	// Searching for a node
	int target = 25;
	TreeNode* searchResult = search(root, target);
	if (searchResult != NULL)
		printf("TreeNode %d found in the Tree.\n", target);
	else
		printf("TreeNode %d not found in the Tree.\n", target);
}

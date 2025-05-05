#include "data_types.h"

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

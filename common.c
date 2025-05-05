#include "data_types.h"

Node* newNode(int data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (!new_node)
	{
		printf("Memory Allocation failed\n");
		return NULL;
	}
	new_node->next = NULL;
	new_node->data = data;

	return new_node;
}
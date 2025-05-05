#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
} Node;

Node* newNode(int data);

typedef struct Queue
{
	Node* front;
	Node* rear;
} Queue;

void	initializeQueue(Queue* queue);
int		queueIsEmpty(Queue* queue);
void	enqueue(Queue* queue, int new_data);
int		dequeue(Queue* queue);
void	cleanupQueue(Queue* queue);
void	displayQueue(Queue* queue);
void	queueTest();

typedef struct Stack
{
	struct Node* head;
} Stack;

void	initializeStack(Stack* stack);
int		stackIsEmpty(Stack* stack);
void	push(Stack* stack, int data);
int		pop(Stack* stack);
void	cleanupStack(Stack* stack);
void	displayStack(Stack* stack);
void	stackTest();

typedef struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

TreeNode*	creatNewTreeNode(int data);
void		insertTree(TreeNode** root, int data);
void		treeTest();
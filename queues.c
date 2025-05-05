#include "data_types.h"

void initializeQueue(Queue* queue)
{
	queue->front = NULL;
	queue->rear = NULL;
}

int queueIsEmpty(Queue* queue)
{
	return queue->front == NULL;
}

void enqueue(Queue* queue, int new_data)
{
	Node* new_node = (Node*)newNode(new_data);
	if (!new_node)
	{
		printf("Memory allocation failed\n");
		return;
	}
	if (queueIsEmpty(queue))
	{
		queue->rear = queue->front = new_node;
		return;
	}
	queue->rear->next = new_node;
	queue->rear = new_node;
}

int dequeue(Queue* queue)
{
	if (queueIsEmpty(queue))
		return -1;
	Node* temp = queue->front;
	queue->front = queue->front->next;
	if (!queue->front)
		queue->rear = NULL;

	int data = temp->data;
	free(temp);
	return data;
}

void cleanupQueue(Queue* queue)
{
	while (!queueIsEmpty(queue))
		dequeue(queue);

	queue->front = NULL;
	queue->rear = NULL;
}

void displayQueue(Queue* queue)
{
	if (queueIsEmpty(queue))
	{
		printf("Queue is empty\n");
		return;
	}
	printf("The queue is following\n");
	Node* temp = queue->front;
	while (temp)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void queueTest()
{
	struct Queue q;
	initializeQueue(&q);

	enqueue(&q, 10);
	enqueue(&q, 20);
	displayQueue(&q);

	dequeue(&q);
	dequeue(&q);
	displayQueue(&q);

	enqueue(&q, 30);
	enqueue(&q, 40);
	enqueue(&q, 50);
	displayQueue(&q);

	dequeue(&q);
	displayQueue(&q);
}
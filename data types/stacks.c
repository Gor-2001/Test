#include "data_types.h"

void initializeStack(Stack* stack)
{
    stack->head = NULL;
}

int stackIsEmpty(Stack* stack)
{
    return stack->head == NULL;
}

void push(Stack* stack, int data)
{
    Node* new_node = newNode(data);
    new_node->next = stack->head;
    stack->head = new_node;
}

int pop(Stack* stack)
{
    if (stackIsEmpty(stack))
    {
        printf("Stack underflow\n");
        return -1;
    }
    int data;
    Node* temp = stack->head;
    stack->head = stack->head->next;
    data = temp->data;
    free(temp);
    return data;
}

void cleanupStack(Stack* stack)
{
    while (!stackIsEmpty(stack))
        pop(stack);

    stack->head = NULL;
}

void displayStack(Stack* stack)
{
    Node* temp = stack->head;
    printf("The stack is following\n");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int peek(Stack* stack)
{
    if (stackIsEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }

    return stack->head->data;
}

void	stackTest()
{
    Stack stack;
    initializeStack(&stack);

    push(&stack, 11);
    push(&stack, 22);
    push(&stack, 33);
    push(&stack, 44);
    
    displayStack(&stack);
    printf("Top element is %d\n", peek(&stack));

    printf("Removing two elements...\n");
    pop(&stack);
    pop(&stack);

    displayStack(&stack);
    printf("Top element is %d\n", peek(&stack));
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

node* create_node();
void push(node**, int);
void pop(node**);
void top(node**);
int empty(node**);
int size(node**);
void print(node*);

int main()
{
    node* stack = NULL;
    push(&stack,10);
    push(&stack,20);
    push(&stack,30);
    print(stack);
    pop(&stack);
    print(stack);
}

node* create_node()
{
    node* temp = (node*)malloc(sizeof(node));
    if(temp == NULL)
    {
        printf("Not enough memory\n");
        exit(1);
    }
    temp->next = NULL;
    return temp;
}

void push(node** stack, int d)
{
    node* n = create_node();
    n->data = d;
    if (empty(stack))
    {
        *stack = n;
        return;
    }
    
    n->next = *stack;
    *stack = n;
}

void pop(node** stack)
{
    if (!empty(stack))
    {
        node* temp = *stack;
        *stack = temp->next;
        free(temp);
    }
}

void top(node** stack)
{
    if (!empty(stack))
        printf("%d ", (*stack)->data);
}

int empty(node** stack)
{
    return *stack == NULL;
}

int size(node** stack)
{
    if (empty(stack))
        return 0;
    int ctr = 1;
    node* temp = *stack;
    while (temp->next != NULL)
    {
        temp = temp->next;
        ctr++;
    }
    return ctr;
}

void print(node* stack)
{
    if (stack == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("\n");
    for (node* temp = stack; temp != NULL; temp = temp->next)
    {
        printf("%d ", temp->data);
    }
    printf("\n");
}
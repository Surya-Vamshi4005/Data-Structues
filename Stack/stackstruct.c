#include <stdio.h>
#define N 1000

typedef struct
{
    int data[N];
    int top;
}stack;

void push(stack*, int);
void pop(stack*);
void top_(stack*);
int empty(stack*);
int size(stack*);

int main()
{
    stack s1; s1.top = -1;
    push(&s1, 10);
    push(&s1, 20);
    push(&s1, 30);
    top_(&s1);pop(&s1);
    top_(&s1);pop(&s1);
    top_(&s1);pop(&s1);
}

void push(stack* s, int d)
{
    s->top++;
    s->data[s->top] = d;
}

void pop(stack* s)
{
    if(!empty(s))
    s->top--;
}

void top_(stack* s)
{
    printf("%d ", s->data[s->top]);
}

int empty(stack* s)
{
    return s->top == -1;
}

int size(stack* s)
{
    return s->top + 1;
}


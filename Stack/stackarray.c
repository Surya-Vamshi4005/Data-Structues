#include <stdio.h>
#define N 1000
int top = -1;

void push(int[], int);
void pop();
void top_(int[]);
int empty();
int size();

int main()
{
    int stack[N];
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    top_(stack);pop();
    top_(stack);pop();
    top_(stack);pop();
    
}

void push(int stack[], int data)
{
    stack[++top] = data;
}

void pop()
{
    if(!empty())
        top--;
}

void top_(int stack[])
{
    if(!empty())
        printf("%d ", stack[top]);
}

int empty()
{
    return (top == -1);
}

int size()
{
    return top+1;
}
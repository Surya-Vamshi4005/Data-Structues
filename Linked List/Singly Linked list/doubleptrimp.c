// Importance of double pointers to change the first node of a list using function calls.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}
node;

void add(node* list)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = 175;
    temp->next = list;
    list = temp;
}

void print(node* list)
{
    if (list == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("\n");
    for (node* temp = list; temp != NULL; temp = temp->next)
    {
        printf("%d ", temp->data);
    }
    printf("\n");
}

int main()
{
    node* head = NULL;
    head = (node*)malloc(sizeof(node));
    head->data = 10;
    head->next = (node*)malloc(sizeof(node));
    head->next->data = 11;
    head->next->next = NULL;
    add(head);

    print(head);
}
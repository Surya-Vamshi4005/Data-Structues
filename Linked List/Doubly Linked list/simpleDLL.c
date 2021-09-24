// Implementation of doubly linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}node;

int main()
{
    node* head = NULL;

    node* n = (node*)malloc(sizeof(node));
    n->data = 1;
    n->next = NULL;
    n->prev = NULL;

    head = n;

    n = (node*)malloc(sizeof(node));
    n->data = 2;
    n->next = NULL;
    n->prev = head;
    // head->next = n; // 1st method to link 1st to 2nd
    n->prev->next = n; // 2nd method to link 1st to 2nd

    n = (node*)malloc(sizeof(node));
    n->data = 3;
    n->next = NULL;
    n->prev = head->next;
    // head->next->next = n; // 1st method to link 2nd to 3rd
    n->prev->next = n;// 2nd method to link 2nd to 3rd

    for (node* temp = head; temp != NULL; temp = temp->next)
    {
        printf("%d ", temp->data);
    }
    
    return 0;
}
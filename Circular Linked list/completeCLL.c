// Circular Linked rear.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}
node;


node* create_node();
node* create_list(node*, int);
node* add_front(node*, int);
node* add_rear(node*, int);
node* delete_head(node*);
node* delete_rear(node*);

void print(node*);

int main()
{
    // Access circular rear by rear
    node* rear = create_list(rear,5);
    print(rear);
    rear = add_front(rear, 1);
    print(rear);
    rear = add_rear(rear, 7);
    print(rear);
    rear = delete_head(rear);
    print(rear);
    rear = delete_rear(rear);
    print(rear);
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

node* create_list(node* head, int n)
{

    if (n > 0)
    {
        int ctr = 1;
        head = create_node();
        printf("Enter the data value of the node %d : ", ctr++);
        int buf;
        scanf("%d", &buf);
        head->data = buf;
        node* temp = head;
        while(ctr <= n)
        {
            node* n = create_node();
            printf("Enter the data value of the node %d : ", ctr++);
            int buff;
            scanf("%d", &buff);
            n->data = buff;
            temp->next = n;
            temp = temp->next;
        }
        temp->next = head;
        return temp;
    }
    return head;
}

node* add_front(node* rear, int i)
{   
    node* n = create_node();
    n->data = i;
    if (rear == NULL)
        rear = n;
    else
    {
        n->next = rear->next;
        rear->next = n;
    }
    return rear;
}

node* add_rear(node* rear, int i)
{
    node* n = create_node();
    n->data = i;
    if (rear == NULL)
        rear = n;
    else
    {
        n->next = rear->next;
        rear->next = n;
        rear = n;
    }
    return rear;
}

void print(node* rear)
{
    if (rear == NULL)
    {
        printf("rear is empty.\n");
        return;
    }
    printf("\n");
    
    node* temp = rear->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next);
    
    printf("\n");
}

node* delete_head(node* rear)
{
    if (rear == NULL)
        return rear;
    if (rear == rear->next)
    {
        free(rear);
        return NULL;
    }
    node* head = rear->next;
    rear->next = head->next;
    free(head);
    return rear;
}

node* delete_rear(node* rear)
{
    if (rear == NULL)
        return rear;
    if (rear == rear->next)
    {
        free(rear);
        return NULL;
    }
    node* temp = rear->next;
    while(temp->next != rear)
        temp = temp->next;
    temp->next = rear->next;
    free(rear);
    rear = temp;
    return rear;    
}

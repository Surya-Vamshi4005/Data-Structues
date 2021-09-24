// Queue is like a the thing we humans stand in line in public to get things done in a sequnetial manner. First come first serve.
// New members join from the last of the queue and will go out from the front. 
// FIFO model.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

node* create_node();
void print(node*);
void enqueue(node**, node**, int);
void dequeue(node**, node**);
void peek(node*);
int isempty(node*);

int main()
{
    node* Qfront = NULL;
    node* Qrear = NULL;
    enqueue(&Qfront, &Qrear, 1);
    enqueue(&Qfront, &Qrear, 2);
    enqueue(&Qfront, &Qrear, 3);
    enqueue(&Qfront, &Qrear, 4);
    peek(Qfront);
    dequeue(&Qfront, &Qrear);
    print(Qfront);
    return 0;
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

void enqueue(node* *Qfront, node* *Qrear, int d)
{
    node* new = create_node();
    new->data = d;
    new->next = NULL;
    if(isempty(*Qrear))
    {
        *Qrear = new;
        *Qfront = new;
    }
    else
    {
        (*Qrear)->next = new;
        *Qrear = new;
    }
}

void dequeue(node* *Qfront, node* *Qrear)
{
    if (isempty(*Qfront))
        return;
    node* temp = *Qfront;
    *Qfront = temp->next;
    free(temp);
}

void peek(node* Qfront)
{
    if (isempty(Qfront))
    {
        printf("The queue is empty.\n");
        return;
    }
    printf("%d ",Qfront->data);
}

int isempty(node* Qfront)
{
    return (Qfront == NULL);
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}node;

node* create_node();
node* create_list(node*, int);
node* add_front(node*, int);
node* add_rear(node*, int);
node* add_after(node*, int, int);
node* delete_rear(node*);
void print(node*);

int main()
{
    node* head = create_list(head, 5);
    print(head);
    head = add_front(head,0);
    print(head);
    head = add_rear(head, 6);
    print(head);
    head = add_after(head,6, 7);
    print(head);
    head = delete_rear(head);
    print(head);
    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    for (node* t = temp; t != NULL; t = t->prev)
        printf("%d ", t->data);
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
    temp->prev = NULL;
    return temp;
}

node* create_list(node* list, int n)
{
    if (n < 1)
        return NULL;
    int ctr = 1;
    int buf;
    list = create_node();
    printf("Enter the value of node %d : ", ctr++);
    scanf("%d", &buf);
    list->data = buf;
    node* temp = list;
    while (ctr <= n)
    {
        node* new = create_node();
        printf("Enter the value of node %d : ", ctr++);
        scanf("%d", &buf);
        new->data = buf;
        new->next = NULL;
        node* ite = temp;
        temp->next = new;
        temp = temp->next;
        temp->prev = ite;
    }
    return list;
}

node* add_front(node* list, int i)
{
    node* n = create_node();
    n->data = i;
    if (list == NULL)
        list = n;
    else
    {
        n->next = list;
        list->prev = n;
        list = n;
    }
    return list;
}

node* add_rear(node* list, int i)
{
    node* n = create_node();
    n->data = i;
    if (list == NULL)
        list = n;
    else
    {
        node* temp = list;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }
    return list;
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

node* add_after(node* head, int k, int i)
{
    node* n = create_node();
    n->data = i;
    if (head == NULL)
        return NULL;
    node* temp = head;
    while (temp->next != NULL || temp->data != k)
    {
        temp = temp->next;
    }
    if (temp->data == k)
    {
        n->next = temp->next;
        n->prev = temp;
        temp->next = n;
        if (n->next != NULL)
            n->next->prev = n;
    }
    return head;
}

node* delete_rear(node* head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    node* n = temp->prev;
    free(temp);
    n->next = NULL;
    return head;
}
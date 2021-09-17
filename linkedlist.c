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
node* add_node_rear(node*, int);
node* add_node_front(node*, int);
node* delete_front(node*);
node* delete_rear(node*);
node* delete_kth(node*, int);
node* add5_to_nodes(node*);
node* add_node_kth(node*, int, int);
node* concat_list(node*, node*);
int rec_count(node*);
void print(node*);
void print_last(node*);
void search_list(node*, int);
void rec_print(node*);
void rec_print_rev(node*);
void copy_list(node**, node**);
void copy_list_in_reverse(node**, node**);
void delete_alt(node**);
void delete_list(node**);
void reverse(node**);


int main()
{
    node* head = NULL, *head2 = NULL;
    head = create_list(head, 10);
    // head2 = create_list(head2, 5);
    // head = add_node_rear(head, 5);
    // head = add_node_rear(head, 10);
    // head = add_node_front(head,1);
    // head = add_node_rear(head, 5);
    // head = add_node_rear(head, 10);
    // head = add_node_front(head,2);
    // rec_print(head);
    // head = add5_to_nodes(head);
    // head = delete_kth(head,2);
    // head = add_node_kth(head, 10, 2);
    print(head);
    reverse(&head);
    // delete_list(&head);
    print(head);
    // delete_alt(&head);
    // print(head2);
    // copy_list(&head,&head2);
    // copy_list_in_reverse(&head,&head2);
    // head = concat_list(head, head2);
    // print(head);
    // print(head2);
    // putchar('\n');
    // rec_print_rev(head);
    // print_last(head);
    // search_list(head, 1);
    // printf("\nThe size of the list is %d.\n", rec_count(head));

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
    }

    return head;
}

node* add_node_rear(node* head, int data)
{
    node* temp = create_node();
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        node* ite = head;
        while (ite->next != NULL)
            ite = ite->next;
        ite->next = temp;
    }
    return head;
}
node* add_node_front(node* head, int data)
{
    node* temp = create_node();
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        temp->next = head;
        head = temp;
    }
    return head;
}

node* delete_front(node* list)
{
    if (list != NULL)
    {
        node* temp = list;
        list = list->next;
        free(temp);
    }
    return list;
}
node* delete_rear(node* list)
{
    if (list != NULL)
    {
        if (list->next == NULL)
        {
            node* temp = list;
            list = NULL;
            free(temp);
            return list;
        }
        node* temp = list;
        node* ite = temp;
        while(temp->next != NULL)
        {
            ite = temp;
            temp = temp->next;
        }
        free(ite->next);
        ite->next = NULL;
    }
    return list;
}

node* delete_kth(node* list, int k)
{
    node* temp = list;
    int ctr = 1;
    if (list != NULL)
    {
        if(k == 1 && list->next == NULL)
        {
            return delete_front(list);
        }
        node* ite = temp;
        while(temp->next != NULL)
        {
            if (k == ctr)
            {
                break;
            }
            ctr++;
            ite = temp;
            temp = temp->next;
        }
        if(k == 1)
        {
            node* temp = list;
            list = list->next;
            free(temp);
        }
        else if (k == ctr)
        {
            node* n = ite->next;
            ite->next = temp->next;
            free(n);
        }
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

void print_last(node* list)
{
    if (list == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    node* temp = list;
    while (temp->next != NULL)
        temp = temp->next;
    printf("Value of the last node : %d\n", temp->data);
}

void search_list(node* list, int k)
{
    if (list == NULL)
    {
        printf("\nThe list is empty.\n");
        return;
    }
    node* temp = list;
    int ctr = 1;
    while(temp!= NULL)
    {
        if (temp->data == k)
        {
            printf("\nThe position of the number %d in the list is %d\n", k, ctr);
            return;
        }
        temp = temp->next;
        ctr++;
    }
    printf("\nELEMENT NOT FOUND.\n");
}

void rec_print(node* list)
{
    if (list == NULL)
        return;
    printf("%d ", list->data);
    rec_print(list->next);
}

void rec_print_rev(node* list)
{
    if (list == NULL)
        return;
    else
        rec_print_rev(list->next);
    printf("%d ", list->data);
}

int rec_count(node* list)
{
    if (list == NULL)
        return 0;
    else
        return 1 + rec_count(list->next);
}

node* add5_to_nodes(node* list)
{
    if (list == NULL)
        return list;
    list->data += 5;
    list->next = add5_to_nodes(list->next);
    return list;
}

node* add_node_kth(node* list, int dt, int k)
{
    if(list == NULL)
        return NULL;
    if (k > 0)
    {
        node* n = create_node();
        n->data = dt;
        int ctr = 1;
        if (k == 1)
        {
            n->next = list;
            list = n;
        }
        else
        {
            node* temp = list;
            while(ctr < k - 1)
            {
                temp = temp->next;
                ctr++;
            }
            n->next = temp->next;
            temp->next = n;
        }
    }
    return list;
}

node* concat_list(node* first, node* second)
{
    if(first == NULL)
        first = second;
    node* temp = first;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = second;
    return first;
}

void copy_list(node** src, node** dest)
{
    *dest = NULL;
    if (*src == NULL)
        *dest = NULL;
    else
    {
        if ((*src)->next == NULL)
        {
            node* n = create_node();
            n->data = (*src)->data;
            n->next = NULL;
            *dest = n;
        }
        else
        {
            node* src_temp = *src;
            node* dest_temp = *dest;
            while (src_temp->next != NULL)
            {
                node* n = create_node();
                n->data = src_temp->data;
                n->next = src_temp->next;
                if (*dest == NULL)
                {
                    *dest = n;
                    dest_temp = *dest;
                    src_temp = src_temp->next;
                }
                else
                {
                    dest_temp->next = n;
                    dest_temp = dest_temp->next;
                    src_temp = src_temp->next;
                }
            }
        }
    }
}

void delete_alt(node** list)
{
    if (*list == NULL || (*list)->next == NULL)
        return;
    node* temp = *list;
    while (temp->next != NULL)
    {
        node* n = temp->next;
        temp->next = n->next;
        free(n);
        if(temp->next != NULL)
            temp = temp->next;
    }
}

void delete_list(node* *list)
{
    while(*list != NULL)
    {
        node* temp = (*list)->next;
        free(*list);
        *list = temp;
    }
    *list = NULL;
}
void copy_list_in_reverse(node**src, node**dest)
{
    *dest = NULL;
    if (*src == NULL)
        *dest = NULL;
    else
    {
        node* src_temp = *src;
        while (src_temp != NULL)
        {
            node* n = create_node();
            n->data = src_temp->data;
            n->next = *dest;
            *dest = n;
            src_temp = src_temp->next;
        }
    }
}

void reverse(node** list)
{
    if (*list == NULL || (*list)->next == NULL)
        return;
    
    node* cur = *list;
    node* prev = NULL;
    node* n = NULL;
    while (cur != NULL)
    {
        n = cur->next;
        cur->next = prev;
        prev = cur;
        cur = n;
    }
    *list = prev;
}

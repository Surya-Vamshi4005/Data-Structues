// Surya Vamshi.
// Only hardcoding values.
// Works only for three nodes.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    // Here we should use struct node instead of just node. because typedef works ony at last. so here at this line typedef is not implemented yet.
    struct node *next; // We should use another pointer which is of type struct to store the address of next struct.

}
node;

int main()
{
    node *list; // For Pointing to the first node.
    list = NULL; // pointing to NULL as of now.

    node *n = malloc(sizeof(node)); // Allocating Memory for first node and storing it in a pointer of type node.
    // So n points to a chunk of memory which is the first node.

    if (n == NULL)
    {
        return 1;
    }
    // So as n points to a chunk of memory which is a type node. so we are assigning values to it using -> operator.
    // -> == (*).
    n->number = 1; //Same as . *(n).number = 1; So n points to a chunk of memory. *(n) refers go to that memory and store 1 in number in it.
    n->next = NULL;

    // List also points to the chunk of memory which n is pointing. So derefencing list can also cause the values to be changed.
    list = n; 

    // 2nd Node.
    n = malloc(sizeof(node));

    if(n == NULL)
    {
        // if memory not allocated properly we have to exit.
        // but before exiting we have to free the previously allocated memory at line 20.
        // So to free that we have list which points to that chunk of memory.
        free(list);
        return 1;
    }
    n->number = 2;
    n->next = NULL;

    // So now this second chunk of memory is pointed by n. but we have to connect this to our first node.
    // So to do that we can use first chunk of memory's next pointer to point to this.
    // To access first chunk of memory we have pointer list.
    list->next = n;

    // 3rd Node.
    n = malloc(sizeof(node));

    if(n == NULL)
    {
        // we have to free all the memory which was allocated before i.e at line 20 and 36.
        // We can use the pointers which point to them to free.
        // But we have to do that from last otherwise if we free the first memory we will lose the connection. So first we have to free 2nd chunk of memory.
        free(list->next);
        free(list);
        return 1;
    }
    n->number = 3;
    n->next = NULL;

    // We have to connect this 3rd chunk to 2nd memory. so to do this.
    // We will use the 2nd memory's pointer and use its next to point to this.
    list->next->next = n;

    // So now all chunks of memories i.e nodes are connected.
    // So we will print them.
    int ctr = 1;
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {   
        // So to print first node number. 
        // We have to point our tmp to the first memory. This can be done by list. So in first loop tmp is assigned to list, which finally poits to first node.
        // So to print 2nd node number.
        // We have to point the tmp to 2nd memory. This can be done by list->next which points to 2nd memory.
        // So pointing tmp to list->next will allow tmp to point to 2nd memory.
        // But in a for loop we have to form a sequence. The trick is tmp = tmp->next will allow us to point to the next node every time.
        // this works because list also points to first node and tmp also points to first node. So instead of list we can use tmp->next.
        // So this sequence follows for rest.
        printf("Node %d : Value %d\n",ctr, tmp->number);
        ctr++;
    }

    // before completing the program we have to free the memory of all three nodes created at lines 20,36,55.
    // Mind it we have to free them from last. Already explained above why.

    while(list != NULL)
    {
        // So before freeing the first memory. we will use tmp to point to the 2nd memory before hand and then we will free first memory by list.
        node *tmp = list->next;
        free(list);
        // After freeing first memory. we will assign both list and tmp point to 2nd memory, because the next we have to free is 2nd memory.
        // and so list points to 2nd and tmp points to third memory by using list->next.
        // this ultimately frees all the memory.
        list = tmp;
    }

}

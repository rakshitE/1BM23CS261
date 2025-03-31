#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *create_ll(void);
void reverse(node *start);
void concat(node *start1, node *start2);
void sort(node *start);
void append(node *start, int val);

int main()
{
    node *start1 = create_ll();
    node *start2 = create_ll();
    reverse(start1);
    sort(start2);
    concat(start1, start2);
    return 0;
}

node *create_ll(void)
{
    int choice;
    node *ptr, *start;
    start = (node*) malloc(sizeof(node));
    if (start == NULL)
        exit(1);
    start->data = 10;
    append(start, 15);
    append(start, 20);
    append(start, 9);
    ptr = start;
    printf("initilly ll:\n");
    while (ptr->next != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    return start;
}

void reverse(node *start)
{
    node *ptr, *preptr, *nxtptr;
    preptr = start;
    ptr = preptr->next;
    nxtptr = ptr->next;
    while (ptr->next != NULL)
    {
        ptr->next = preptr;
        preptr = ptr;
        ptr = nxtptr;
        nxtptr = nxtptr->next;
    }
    start->next = NULL;
    start = ptr;
    preptr = NULL;
    nxtptr = NULL;
    printf("list after reversing: \n");
    ptr = start;
    while (ptr->next != NULL)
    {
        printf("%d -> ", &ptr->data);
        ptr = ptr->next;
    }
}

void concat(node *start1, node *start2)
{
    node *ptr = start1;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = start2;
}

void sort(node *start)
{
    node *ptr = start;
    int temp, swap = 0;
    do
    {
        while (ptr->next != NULL)
        {
            if (ptr->data > ptr->next->data)
            {
                temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swap = 1;
            }
            ptr = ptr->next;
        }
        ptr = start;
    }while (swap != 0);
    ptr = start;
    printf("list after sorting: \n");
    while (ptr->next != NULL)
    {
        printf("%d ->", &ptr->data);
        ptr = ptr->next;
    }
}

void append(node *start, int val)
{
    node *new_node, *ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    new_node = (node*)malloc (sizeof(node));
    if (!new_node)
    {
        printf("Error\n");
        return;
    }
    new_node->data = val;
    new_node->next = NULL;
    ptr->next = new_node;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *create_ll(void);
void reverse(node **start);
void concat(node *start1, node *start2);
void sort(node *start);
void append(node *start, int val);

int main()
{
    node *start1 = create_ll();
    node *start2 = create_ll();
    reverse(&start1);
    sort(start2);
    concat(start1, start2);

    printf("Final concatenated list:\n");
    node *ptr = start1;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    return 0;
}

node *create_ll(void)
{
    node *start = (node *)malloc(sizeof(node));
    if (!start)
    {
        printf("Memory allocation error\n");
        exit(1);
    }
    start->data = 10;
    start->next = NULL;
    append(start, 15);
    append(start, 20);
    append(start, 9);

    printf("Initial linked list:\n");
    node *ptr = start;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    return start;
}

void reverse(node **start)
{
    node *prev = NULL, *current = *start, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *start = prev;

    printf("List after reversing:\n");
    node *ptr = *start;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
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
    if (!start) return;

    node *ptr;
    int temp, swapped;
    do
    {
        swapped = 0;
        ptr = start;
        while (ptr->next != NULL)
        {
            if (ptr->data > ptr->next->data)
            {
                temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
    } while (swapped);

    printf("List after sorting:\n");
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void append(node *start, int val)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (!new_node)
    {
        printf("Memory allocation error\n");
        return;
    }
    new_node->data = val;
    new_node->next = NULL;

    node *ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void display(node *start);
node *create_node(int num);
node *insert_beg(node **start);
node *insert_end(node *start);
node *insert_pos(node **start);
node *delete_beg(node **start);
node *delete_end(node **start);
node *delete_pos(node **start);

int main()
{
    int choice;
    node *start = NULL;
    do
    {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete at beginning\n5. Delete at position\n6. Delete at end\n7. Display list\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                start = insert_beg(&start);
                break;
            case 2:
                start = insert_end(start);
                break;
            case 3:
                start = insert_pos(&start);
                break;
            case 4:
                start = delete_beg(&start);
                break;
            case 5:
                start = delete_pos(&start);
                break;
            case 6:
                start = delete_end(&start);
                break;
            case 7:
                display(start);
                break;
            case 8:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 8);
}

node *create_node(int num)
{
    node *new_node;
    new_node = (node*) malloc(sizeof(node));
    if (!new_node)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = num;
    new_node->next = NULL;
    return new_node;
}

node *insert_beg(node **start)
{
    node *new_node;
    int val;
    printf("Enter data to insert at beg: ");
    scanf("%d", &val);
    getchar();
    new_node = create_node(val);
    if (*start == NULL)
        return new_node;
    new_node->next = *start;
    *start = new_node;
    return *start;
}

node *insert_end(node *start)
{
    node *new_node, *ptr;
    int val;
    printf("Enter data to insert at end: ");
    scanf("%d", &val);
    getchar();
    new_node = create_node(val);
    if (start == NULL)
        return new_node;
    ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new_node;
    return start;
}

node *insert_pos(node **start)
{
    node *new_node, *ptr;
    int val, pos, count = 1;

    ptr = *start;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    printf("Enter data to insert: ");
    scanf("%d", &val);
    getchar();
    new_node = create_node(val);

    do {
        printf("Enter position: ");
        scanf("%d", &pos);
        if (pos > count || pos <= 0)
            printf("Unable to insert at that position\n");
    } while (pos > count || pos <= 0);

    ptr = *start;
    for (int i = 0; i < pos - 2; i++)
        ptr = ptr->next;
    if (pos == 1)
    {
        new_node->next = *start;
        *start = new_node;
    }
    else
    {
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
    return *start;
}

node *delete_beg(node **start)
{
    if (*start == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    node *ptr = *start;
    *start = ptr->next;
    free(ptr);
    return *start;
}

node *delete_end(node **start)
{
    if (*start == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    node *ptr, *preptr;
    ptr = *start;
    if (ptr->next == NULL)
    {
        *start = NULL;
        free(ptr);
        printf("Element deleted\n");
        return *start;
    }
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    free(ptr);
    preptr->next = NULL;
    printf("Element deleted\n");
    return *start;
}

node *delete_pos(node **start)
{
    if (*start == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    node *ptr, *preptr;
    int pos, count = 1;
    ptr = *start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    do {
        printf("Enter position: ");
        scanf("%d", &pos);
        if (pos > count || pos <= 0)
            printf("Unable to insert at that position\n");
    } while (pos > count || pos <= 0);

    ptr = *start;
    if (pos == 1)
    {
        *start = ptr->next;
        free(ptr);
        printf("Element deleted\n");
        return *start;
    }
    for (int i = 0; i < pos - 1; i++)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    printf("Element deleted\n");
    return *start;
}

void display(node *start)
{
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *ptr = start;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    return;
}

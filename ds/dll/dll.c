#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

node *create_ll(void);
void insert_left(node **head, int target, int val);
void delete_node(node **head, int target);
void display(node *head);

int main()
{
    int choice = 0, val, target;
    node *head = NULL;
    while (choice != 5)
    {
        printf("Enter your choice: \n");
        printf("1. Create ll\n2. Display ll\n3. Insert to left of a node\n4. Delete a node\n5. Exit\n");
        scanf("%d", &choice);
        if (choice == 5)
            break;
        switch (choice)
        {
        case 1:
            head = create_ll();
            break;
        case 2:
            display(head);
            break;
        case 3:
            printf("Enter val for target: ");
            scanf("%d", &target);
            printf("Enter val for new node: ");
            scanf("%d", &val);
            insert_left(&head, target, val);
            break;
        case 4:
            printf("Enter val for target: ");
            scanf("%d", &target);
            delete_node(&head, target);
            break;
        case 5:
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

node *create_ll(void)
{
    int choice = 0;
    node *head, *ptr, *new_node;
    head = (node*) malloc(sizeof(node));
    if (!head)
    {
        printf("Memory not allocated\n");
        exit(1);
    }
    printf("Enter the value for first node: ");
    scanf("%d", &(head->data));
    head->prev = NULL;
    head->next = NULL;
    ptr = head;
    while (choice != 2)
    {
        printf("1. Add Node\n2. Exit\n");
        scanf("%d", &choice);
        if (choice == 2)
        {
            break;
        }
        new_node = (node*) malloc(sizeof(node));
        if (!new_node)
        {
            printf("Memory not allocated\n");
            exit(2);
        }
        printf("Enter value for new node: ");
        scanf("%d", &(new_node->data));
        new_node -> prev = ptr;
        new_node -> next = NULL;
        ptr->next = new_node;
        ptr = ptr->next;
    }
    return head;
}

void insert_left(node **head, int target, int val)
{
   node *temp, *new_node;
   if (!(*head))
   {
       printf("List is empty\n");
       return;
   }
   temp = *head;
   while (temp != NULL)
   {
        if (temp->data == target)
        {
            new_node = (node*) malloc(sizeof(node));
            if (!new_node)
            {
                exit(3);
            }
            new_node->data = val;
            new_node->next = temp;
            if (temp == *head)
            {
                *head = new_node;
                temp->prev = new_node;
                new_node->prev = NULL;
                return;
            }
            new_node->prev = temp->prev;
            temp->prev->next = new_node;
            temp->prev = new_node;
            return;
        }
        temp = temp->next;
    }
    printf("Target not found\n");
}

void delete_node(node **head, int target)
{
    if (!(*head))
    {
        printf("List is empty\n");
        return;
    }
    node *ptr = *head;
    while (ptr != NULL)
    {
        if (ptr->data == target)
        {
            if (ptr == *head)
            {
                *head = ptr->next;
                if (*head)
                    {
                    (*head)->prev = NULL;
                    }

                ptr->next->prev = NULL;
                free(ptr);
                return;
            }
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
            return;
        }
        ptr = ptr->next;
    }
    printf("Target not found\n");
}

void display(node *head)
{
    if (!head)
    {
        printf("list is empty\n");
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return;
}

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

int main() {
    int choice = 0, val, target;
    node *head = NULL;
    while (choice != 5) {
        printf("\nEnter your choice:\n");
        printf("1. Create ll\n2. Display ll\n3. Insert to left of a node\n4. Delete a node\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = create_ll();
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter value of target node: ");
                scanf("%d", &target);
                printf("Enter value for new node: ");
                scanf("%d", &val);
                insert_left(&head, target, val);
                break;
            case 4:
                printf("Enter value of node to delete: ");
                scanf("%d", &target);
                delete_node(&head, target);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }


    while (head != NULL) {
        node *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}

node *create_ll(void) {
    int choice = 0;
    node *head = NULL, *ptr = NULL, *new_node = NULL;

    while (choice != 2) {
        printf("1. Add Node\n2. Exit\n");
        scanf("%d", &choice);
        if (choice == 2) {
            break;
        }

        new_node = (node *)malloc(sizeof(node));
        if (!new_node) {
            printf("Memory allocation error\n");
            exit(1);
        }

        printf("Enter value for new node: ");
        scanf("%d", &new_node->data);
        new_node->prev = NULL;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            ptr->next = new_node;
            new_node->prev = ptr;
        }
        ptr = new_node;
    }
    return head;
}

void insert_left(node **head, int target, int val) {
    node *temp, *new_node;
    if (!(*head)) {
        printf("List is empty. Cannot insert.\n");
        return;
    }

    temp = *head;
    while (temp != NULL) {
        if (temp->data == target) {
            new_node = (node *)malloc(sizeof(node));
            if (!new_node) {
                printf("Memory allocation error\n");
                exit(2);
            }
            new_node->data = val;
            new_node->next = temp;
            new_node->prev = temp->prev;

            if (temp == *head) {
                *head = new_node;
            } else {
                temp->prev->next = new_node;
            }
            temp->prev = new_node;
            return;
        }
        temp = temp->next;
    }
    printf("Target node not found.\n");
}

void delete_node(node **head, int target) {
    if (!(*head)) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    node *ptr = *head;
    while (ptr != NULL) {
        if (ptr->data == target) {
            if (ptr == *head) {
                *head = ptr->next;
                if (*head != NULL) {
                    (*head)->prev = NULL;
                }
            } else if (ptr->next == NULL) {
                ptr->prev->next = NULL;
            } else {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
            }
            free(ptr);
            printf("Node with value %d deleted successfully.\n", target);
            return;
        }
        ptr = ptr->next;
    }
    printf("Target node not found.\n");
}

void display(node *head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }

    node *temp = head;
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

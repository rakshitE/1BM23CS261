#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

int queue[SIZE], front = -1, rear = -1;

void enqueue(int x) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is full\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        queue[rear] = x;
        printf("%d inserted to queue\n", x);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("%d dequeued from Queue\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    do {
        printf("\nEnter 1 for Enqueue\nEnter 2 for Dequeue\nEnter 3 to Display Queue elements\nEnter 4 to exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

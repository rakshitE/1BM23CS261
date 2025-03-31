#include <stdio.h>
#include <conio.h>
#define SIZE 3

int q[SIZE];
int front = -1; rear = -1;
void insert(void);
void delete(void);
void display(void);

int main()
{
    int opt, val;
    do
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);
        getchar();
        switch(opt)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid\n");
                break;
        }
    } while (opt != 4);
}

void insert()
{
    if (rear == SIZE - 1)
    {
        printf("Overflow\n");
        return;
    }
    else if (front == -1 && rear == -1)
        front = rear = 0;
    else
        rear++;
    int num;
    printf("Enter the number to be inserted: ");
    scanf("%d", &num);
    getchar();
    q[rear] = num;
}

void delete()
{
    int val;
    if (front == -1 || front > rear)
    {
        printf("Underflow\n");
        return;
    }
    val = q[front++];
    printf("The number deleted is %d\n", val);
    if (front > rear)
        front = rear = -1;
    return;
}

void display()
{
    int i;
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    for (i = front; i <= rear; i++)
        printf("%d -> ", q[i]);
    printf("\n");
}

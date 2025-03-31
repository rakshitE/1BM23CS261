#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int top = -1;
char stack[SIZE];

void push(char a);
void pop();
void display();

int main()
{
    int choice;
    char ele;
    do
    {
            printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
            scanf("%d", &choice);
            getchar();
            switch(choice)
            {
                case 1:
                    printf("Enter the char to push: ");
                    scanf("%c", &ele);
                    getchar();
                    push(ele);
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    display();
                    break;
                case 4:
                    printf("Exiting the program\n");
                    break;
                default:
                    printf("Invalid\n");
                    break;
            }
    }while (choice != 4);
}

void push(char a)
{
    if (top == SIZE - 1)
    {
            printf("Stack overflow\n");
            return;
    }
    stack[++top] = a;
}

void pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    printf("The popped element is : %c\n", stack[top--]);
    return;
}

void display()
{
    if (top == -1)
    {
        printf("Empty\n");
        return;
    }
    printf("The stack elements are\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%c\n", stack[i]);
    }
    return;
}


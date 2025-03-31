#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int index1 = 0, pos = 0, top = -1, length;
char symbol, temp, infix[20], postfix[20], stack[20];
void infixtopostfix();
int pred(char symbol);
char pop();
void push(char a);

int main()
{
    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';
    infixtopostfix();
    printf("\nInfix expression: %s", infix);
    printf("\nPostfix expression: %s", postfix);
}

void infixtopostfix()
{
    length = strlen(infix);
    push('#');
    while (index1 < length)
    {
        symbol = infix[index1];
        switch (symbol)
        {
            case '(':;

                push(symbol);
                break;
            case ')':
                temp = pop();
                while (temp != '(')
                {
                    postfix[pos] = temp;
                    pos++;
                    temp = pop();
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (pred(stack[top]) >= pred(symbol))
                {
                    temp = pop();
                    postfix[pos++] = temp;
                }
                push(symbol);
                break;
            default:
                postfix[pos++] = symbol;
                break;
        }
        index1++;
    }
    while (top > 0)
    {
        temp = pop();
        postfix[pos++] = temp;
    }
    postfix[pos] = '\0';
}

void push(char symbol)
{
    top++;
    stack[top] = symbol;
}

char pop()
{
    char symb;
    symb = stack[top];
    top =  top - 1;
    return symb;
}

int pred(char symbol)
{
    int p;
    switch(symbol)
    {
        case '^':
            p = 3;
            break;
        case '*':
        case '/':
            p = 2;
            break;
        case '+':
        case '-':
            p = 1;
            break;
        case '(':
            p = 0;
            break;
        case '#':
            p = -1;
            break;
    }
    return p;
}

#include <stdio.h>
#define MAX 50

int stack[MAX], top = -1;
char x;

void push(char item)
{
    stack[++top] = item;
}

char pop()
{
    if (top == -1)
        return -1;
    return stack[top--];
}

int precedence(char item)
{
    if (item == '(')
        return 0;
    if (item == '+' || item == '-')
        return 1;
    if (item == '*' || item == '/')
        return 2;
    return -1; 
}

int main()
{
    char expression[MAX], *e;
    printf("\n\tINFIX TO POSTFIX OPERATION\n\t");
    printf("\n\tEnter your infix expression: \n\t");
    scanf("%s", expression);
    e = expression;
    while (*e != '\0')
    {
        if (isalnum(*e))
        {
            printf("%c", *e);
        }
        else if (*e == '(')
        {
            push(*e);
        }
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
            {
                printf("%c", x);
            }
        }
        else
        {
            while (precedence(stack[top]) >= precedence(*e))
            {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }
    while (top != -1)
    {
        printf("%c", pop());
    }
    return 0;
}

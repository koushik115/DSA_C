#include <stdio.h>

#define MAX 30

int top = -1;
int stack[MAX];

void push(char item);
int pop(void);
int match(char a, char b);
int check(char exp[]);

int main(void)
{
    char exp[MAX];
    int valid;
    printf("Enter an algebraic expression: ");
    gets(exp);
    valid = check(exp);

    if (valid)
    {
        printf("Valid Expression!\n");
    }
    else
    {
        printf("Invalid Expression!\n");
    }

    return 0;
}

int check(char exp[])
{
    int i;
    char temp;

    for (i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);

        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (top == -1)
            {
                printf("Right Paranthesis is more than the left Paranthesis");
                return 0;
            }
            else
            {
                temp = pop();
                if (!match(temp, exp[i]))
                {
                    printf("Mismatched parenthesis are: ");
                    printf("%c and %c\n", temp, exp[i]);
                    return 0;
                }
            }
        }
    }
}

int match(char a, char b)
{
    if ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'))
        return 1;

    return 0;
}

void push(char item)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }

    stack[++top] = item;
}

int pop(void)
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
        exit(1);
    }

    return stack[top--];
}
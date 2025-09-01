#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define BLANK ' '
#define TAB '\t'
#define MAX 50

char infix[MAX], postfix[MAX];
long int stack[MAX];
int top;

void push(long int symbol);
long int pop(void);
void infix_to_postfix(void);
long int eval_post(void);
int white_space(char symbol);
int priority(char symbol);
int isEmpty(void);

int main(void)
{
    long int value;
    top = -1;

    printf("Enter infix: ");
    gets(infix);

    infix_to_postfix();

    printf("Postfix: %s\n", postfix);
    value = eval_post();
    printf("Value of expression: %ld\n", value);

    return 0;
}

void infix_to_postfix(void)
{
    unsigned int i, p = 0;
    char next, symbol;

    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        if (!white_space(symbol))
        {
            switch (symbol)
            {
            case '(':
                push(symbol);
                break;

            case ')':
                while ((next = pop()) != ')')
                    postfix[p++] = next;
                break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while (!isEmpty() && priority(stack[top]) >= priority(symbol))
                    postfix[p++] = pop();
                push(symbol);
                break;

            default:
                postfix[p++] = symbol;
            }
        }
    }

    while (!isEmpty())
        postfix[p++] = pop();

    postfix[p] = '\0';
}

void push(long int symbol)
{
    if (top > MAX - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }

    stack[++top] = symbol;
}

long int pop(void)
{
    if (isEmpty())
    {
        printf("Stack Undeflow!\n");
        exit(1);
    }

    return stack[top--];
}

int white_space(char symbol)
{
    if (symbol == BLANK || symbol == TAB)
        return 1;

    return 0;
}
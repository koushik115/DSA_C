#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

int top = -1;
char stack[MAX];

char pop(void);
void push(char item);

int main(void)
{
    char str[20];
    unsigned int i;

    gets(str);
    for (i = 0; i < strlen(str); i++)
        push(str[i]);

    for (i = 0; i < strlen(str); i++)
        str[i] = pop();

    printf("Reversed String is %s", str);
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

char pop(void)
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
        exit(1);
    }

    return stack[top--];
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack_arr[MAX];
int top = -1;

void push(int item);
int pop(void);
int peek(void);
int isEmpty(void);
int isFull(void);
void display(void);

int main(void)
{
    int choice, item;

    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display top element\n");
        printf("4. Display all stack elements\n");
        printf("5. Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the item to be pushed: ");
            scanf("%d", &item);
            push(item);
            break;

        case 2:
            item = pop();
            printf("Popped item id %d\n", item);
            break;

        case 3:
            item = peek();
            printf("Element at the top is %d\n", item);
            break;

        case 4:
            display();
            break;

        case 5:
            exit(1);

        default:
            printf("Invalid choice!\n");
            break;
        }
    }

    return 0;
}

void push(int item)
{
    if (isFull())
    {
        printf("Stack Overflow!\n");
        return;
    }

    stack_arr[++top] = item;
}

int pop(void)
{
    if (isEmpty)
    {
        printf("Stack Undeflow!\n");
        exit(1);
    }

    return stack_arr[top--];
}

int peek(void)
{
    if (isEmpty)
    {
        printf("Stack Undeflow!\n");
        exit(1);
    }

    return stack_arr[top];
}

int isEmpty(void)
{
    return (top == -1);
}

int isFull(void)
{
    return (top >= MAX - 1);
}

void display(void)
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are : ");
    for (int i = top; i >= 0; i--)
        printf(" %d", stack_arr[i]);
}
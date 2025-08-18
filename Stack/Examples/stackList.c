#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
} *top = NULL;

void push(int item);
int pop(void);
int peek(void);
int isEmpty(void);
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
    struct node *tmp = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));

    if (tmp == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }

    tmp->info = item;
    tmp->link = top;
    top = tmp;
}

int pop(void)
{
    struct node *tmp = NULL;
    int item;

    if (isEmpty())
    {
        printf("Stack Underflow!\n");
        exit(1);
    }

    tmp = top;
    item = top->info;
    top = top->link;
    free(tmp);
    tmp = NULL;

    return item;
}

int peek(void)
{
    if (isEmpty())
    {
        printf("Stack Undeflow!\n");
        exit(1);
    }

    return top->info;
}

int isEmpty(void)
{
    return (top == NULL);
}

void display(void)
{
    struct node *ptr = NULL;
    ptr = top;

    if (isEmpty())
    {
        printf("Stack is empty\n");
        return;
    }

    while (ptr != NULL)
    {
        printf(" %d", ptr->info);
        ptr = ptr->link;
    }
}
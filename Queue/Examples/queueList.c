#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
} *front = NULL, *rear = NULL;

void insert(int item);
int del(void);
int peek(void);
int isEmpty(void);
void display(void);

int main(void)
{
    int choice, item;

    while (1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display top element\n");
        printf("4. Display all queue elements\n");
        printf("5. Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the item to be pushed: ");
            scanf("%d", &item);
            insert(item);
            break;

        case 2:
            item = del();
            printf("Deleted item is %d\n", item);
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

void insert(int item)
{
    struct node *tmp = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));

    if (tmp == NULL)
    {
        printf("Queue Overflow!\n");
        return;
    }

    tmp->info = item;
    tmp->link = NULL;
    if (front == NULL)
        front = tmp;
    else
        rear->link = tmp;
    rear = tmp;
}

int del(void)
{
    struct node *tmp = NULL;
    int item;

    if (isEmpty())
    {
        printf("Stack Undeflow!\n");
        exit(1);
    }

    tmp = front;
    item = front->info;
    front = front->link;
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

    return front->info;
}

void display(void)
{
    struct node *ptr = NULL;

    if (isEmpty())
    {
        printf("No elements in the queue!\n");
        return;
    }

    ptr = front;
    while (ptr != NULL)
    {
        printf(" %d", ptr->info);
        ptr = ptr->link;
    }
}

int isEmpty(void)
{
    return (front == NULL);
}
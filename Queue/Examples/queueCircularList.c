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

    if (rear == NULL)
    {
        rear = tmp;
        tmp->link = rear;
    }
    else
    {
        tmp->link = rear;
        rear->link = tmp;
        rear = tmp;
    }
}
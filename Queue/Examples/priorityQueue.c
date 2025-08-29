#include <stdio.h>
#include <stdlib.h>

struct node
{
    int priority;
    int info;
    struct node *link;
} *front = NULL;

void insert(int item, int item_priority);
int del(void);
void display(void);
int isEmpty(void);

int main(void)
{
    int choice, item, item_priority;
    while (1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Input the item to be added in the queue: ");
            scanf("%d", &item);
            printf("Enter its priority: ");
            scanf("%d", &item_priority);
            insert(item, item_priority);
            break;

        case 2:
            printf("Deleted item is %d\n", del());
            break;

        case 3:
            display();
            break;

        case 4:
            exit(1);

        default:
            printf("Invalid Choice!\n");
            break;
        }
    }

    return 1;
}

void insert(int item, int item_priority)
{
    struct node *p, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));

    if (tmp == NULL)
    {
        printf("Memory not available!\n");
        return;
    }

    tmp->info = item;
    tmp->priority = item_priority;

    if (isEmpty() || item_priority < front->priority)
    {
        tmp->link = front;
        front = tmp;
    }
    else
    {
        p = front;
        while ((p->link != NULL && p->link->priority <= item_priority))
            p = p->link;

        tmp->link = p->link;
        p->link = tmp;
    }
}

int del(void)
{
    struct node *tmp;
    int item = -1;

    if (isEmpty())
    {
        printf("Queue Underflow!\n");
        exit(1);
    }
    else
    {
        tmp = front;
        item = front->info;
        front = front->link;
        free(tmp);
        tmp = NULL;
    }

    return item;
}

int isEmpty(void)
{
    return (front == NULL);
}

void display(void)
{
    struct node *ptr;
    ptr = front;

    if (isEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }
    else
    {
        printf("Queue is: ");
        while (ptr != NULL)
        {
            printf(" %d", ptr->info);
            ptr = ptr->link;
        }
    }
}
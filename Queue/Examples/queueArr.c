#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue_arr[MAX];
int front = -1, rear = -1;

void insert(int item);
int del(void);
int peek(void);
int isEmpty(void);
int isFull(void);
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
    if (isFull())
    {
        printf("Stack Overflow!\n");
        return;
    }

    if (front == -1)
        front = 0;

    queue_arr[++rear] = item;
}

int del(void)
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }

    return queue_arr[front++];
}

int peek(void)
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }

    return queue_arr[front];
}

int isEmpty(void)
{
    return (front == rear + 1 || front == -1);
}

int isFull(void)
{
    return (rear == MAX - 1);
}

void display(void)
{
    if (isEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements are: \n");
    for (int i = front; i <= rear; i++)
        printf(" %d", queue_arr[i]);
}
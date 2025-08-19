#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int cqueue_arr[MAX];
int front = -1;
int rear = -1;

void display(void);
void insert(int item);
int del(void);
int peek(void);
int isEmpty(void);
int isFull(void);

int main(void)
{
    int choice, item;

    while (1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Input the element for the insertion: ");
            scanf("%d", &item);
            insert(item);
            break;

        case 2:
            printf("Element deleted is : %d\n", del());
            break;

        case 3:
            printf("Element at the front is : %d\n", peek());
            break;

        case 4:
            display();
            break;

        case 5:
            exit(1);

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

void insert(int item)
{
    if (isFull())
    {
        printf("Queue Overflow!\n");
        return;
    }

    if (front == -1)
        front = 0;

    if (rear == MAX - 1)
        rear = 0;
    else
        rear += 1;

    cqueue_arr[rear] = item;
}

int del(void)
{
    int item;
    if (isEmpty())
    {
        printf("Stack Underflow!\n");
        exit(1);
    }

    item = cqueue_arr[front];

    if (front = rear)
        front = rear = -1;
    else if (front == MAX - 1)
        front = 0;
    else
        front += 1;

    return item;
}

int isEmpty(void)
{
    return (front == -1);
}

int isFull(void)
{
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

int peek(void)
{
    if (isEmpty())
    {
        printf("Stack Underflow!\n");
        exit(1);
    }

    return cqueue_arr[front];
}

void display(void)
{
    int i;
    if (isEmpty())
    {
        printf("No elements int hte list\n");
        return;
    }

    printf("Queue elements: \n");
    i = front;

    if (front <= rear)
    {
        while (i <= rear)
        {
            printf(" %d", cqueue_arr[i++]);
        }
    }
    else
    {
        while (i <= MAX - 1)
        {
            printf(" %d", cqueue_arr[i++]);
        }

        i = 0;
        while (i <= rear)
        {
            printf(" %d", cqueue_arr[i++]);
        }
    }
}
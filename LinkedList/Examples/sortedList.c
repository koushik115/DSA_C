#include <stdio.h>
#include <stdlib.h>

// Structure Declararion
struct node
{
    int info;
    struct node *link;
};

// Function Prototype
struct node *insert_s(struct node *start, int data);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start, int data);
struct node *del(struct node *start, int data);
struct node *reverse(struct node *start);

int main(void)
{
    struct node *start = NULL;
    int choice, data, item, pos;

    while (1)
    {
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Count\n");
        printf("4. Search\n");
        printf("5. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted\n");
            scanf("%d", &data);
            start = insert_s(start, data);
            break;

        case 2:
            display(start);
            break;

        case 3:
            count(start);
            break;

        case 4:
            printf("Enter the elements to be searched : ");
            scanf("%d", &data);
            search(start, data);
            break;

        case 5:
            exit(1);

        default:
            printf("Illegal command!!\n");
            break;
        }
    }
}

struct node *insert_s(struct node *start, int data)
{
    struct node *tmp = NULL, *p = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;

    if (start == NULL || data < start->info)
    {
        tmp->link = start;
        start = tmp;
        return start;
    }
    else
    {
        p = start;

        while (p->link != NULL && p->link->info < data)
            p = p->link;
        tmp->link = p->link;
        p->link = tmp;
    }

    return start;
}

void display(struct node *start)
{
    struct node *p = start;

    if (!p)
    {
        printf("List is empty!!\n");
        return;
    }
    else
    {
        while (p != NULL)
        {
            printf("%d\t", p->info);
            p = p->link;
        }
    }

    printf("\n\n");
}

void count(struct node *start)
{
    struct node *p = NULL;
    int count = 0;

    if (start == NULL)
    {
        printf("No elements found in the list!\n");
        return;
    }

    p = start;
    while (p != NULL)
    {
        count++;
        p = p->link;
    }

    printf("%d elements found in the list!\n", count);
}

void search(struct node *start, int data)
{
    struct node *p = start;
    int pos = 1;

    if(start == NULL || data < start->info) {
        printf("%d not found in the list\n");
        return;
    }

    while(p != NULL && p->info <= data) {
        if(p->info == data) {
            printf("%d found at position %d", data, pos);
            return;
        }

        p = p->link;
        pos++;
    }

    printf("Item %d not found in the list\n", data);
}

struct node *del(struct node *start, int data)
{
    struct node *tmp = NULL, *p = NULL;

    if (start == NULL)
    {
        printf("List is empty!!\n");
        return start;
    }

    // First item to be deleted
    if (data == start->info)
    {
        tmp = start;
        start = start->link;
        free(tmp);
        return start;
    }

    // Item to be deleted in between the nodes
    p = start;
    while (p->link != NULL)
    {
        if (p->link->info == data)
        {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return start;
        }

        p = p->link;
    }

    printf("Element %d not found in the list!\n", data);
    return start;
}

struct node *reverse(struct node *start)
{
    struct node *prev = NULL, *ptr = NULL, *next = NULL;

    prev = NULL;
    ptr = start;
    while (ptr != NULL)
    {
        next = ptr->link;
        ptr->link = prev;
        prev = ptr;
        ptr = next;
    }

    start = prev;
    return start;
}
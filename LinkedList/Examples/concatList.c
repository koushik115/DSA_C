#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *create(struct node *start);
struct node *insert_s(struct node *start, int data);
struct node *insert(struct node *start, int data);
struct node *concat(struct node *start1, struct node *start2);
void display(struct node *start);

int main(void)
{
    struct node *start1 = NULL, *start2 = NULL;
    start1 = create(start1);
    start2 = create(start2);
    printf("List1: ");
    display(start1);
    printf("List2: ");
    display(start2);
    concat(start1, start2);

    return 0;
}

struct node *create(struct node *start)
{
    int i, n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    start = NULL;

    for (i = 1; i <= n; i++)
    {
        printf("Enter the the element to be inserted: ");
        scanf("%d", &data);
        start = insert_s(start, data);
    }

    return start;
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

struct node *insert(struct node *start, int data)
{
    struct node *tmp = NULL, *p = NULL;

    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;

    if (start == NULL)
    {
        tmp->link = NULL;
        start = tmp;
    }
    else
    {
        p = start;
        while (p->link != NULL)
            p = p->link;

        tmp->link = p->link;
        p->link = tmp;
    }

    return start;
}

struct node *concat(struct node *start1, struct node *start2)
{
    struct node *p = NULL;

    if (start1 == NULL)
    {
        start1 = start2;
        return start1;
    }

    if (start2 == NULL)
        return start1;

    p = start1;
    while (p->link != NULL)
        p = p->link;

    p->link = start2;
    return start2;
}

void display(struct node *start)
{
    struct node *p = NULL;
    p = start;

    if (start == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    else
    {
        while (p != NULL)
        {
            printf("%d ", p->info);
            p = p->link;
        }
    }
}
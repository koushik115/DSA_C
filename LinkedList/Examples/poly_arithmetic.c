#include <stdio.h>
#include <stdlib.h>

struct node
{
    float coef;
    int expo;
    struct node *link;
};

struct node *create(struct node *start);
struct node *insert_s(struct node *start, float coef, int expo);
struct node *insert(struct node *start, float coef, int expo);
void display(struct node *start);
void poly_add(struct node *p1, struct node *p2);
void poly_mul(struct node *p1, struct node *p2);

int main(void)
{
    struct node *start1 = NULL, *start2 = NULL;

    printf("Enter polynomial 1: ");
    start1 = create(start1);
    printf("Enter polynomial 2: ");
    start2 = create(start2);

    printf("Polynomial 1 is : ");
    display(start1);
    printf("Polynomial 2 is : ");
    display(start2);

    return 0;
}

struct node *create(struct node *start)
{
    int i, n, expo;
    float coef;

    printf("Enter the number of terms: ");
    sacnf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the Coefficient: ");
        scanf("%f", &coef);

        printf("Enter the exponent: ");
        scanf("%d", &expo);

        start = insert_s(start, coef, expo);
    }

    return start;
}

struct node *insert_s(struct node *start, float coef, int expo)
{
    struct node *tmp = NULL, *p = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->coef = coef;
    tmp->expo = expo;

    if (start == NULL || expo < start->expo)
    {
        tmp->link = start;
        start = tmp;
    }
    else
    {
        p = start;
        while (p->link != NULL && p->expo < expo)
            p = p->link;

        tmp->link = p->link;
        p->link = tmp;
    }

    return start;
}

struct node *insert(struct node *start, float coef, int expo)
{
    struct node *tmp = NULL, *p = NULL;

    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->coef = coef;
    tmp->expo = expo;

    if (start == NULL)
    {
        tmp->link = start;
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

void display(struct node *start)
{
    struct node *p = NULL;

    if (start == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    else
    {
        p = start;
        while (p != NULL)
        {
            printf("%.1fx^%d", p->coef, p->expo);
            if (p->link != NULL)
                printf(" + ");
            else
                printf("\n");
            p = p->link;
        }
    }
}

void poly_add(struct node *p1, struct node *p2)
{
    struct node *start3 = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->expo > p2->expo)
        {
            start3 = insert(start3, p1->coef, p1->expo);
            p1 = p1->link;
        }
        else if (p2->expo > p1->expo)
        {
            start3 = insert(start3, p2->coef, p2->expo);
            p2 = p2->link;
        }
        else if (p1->expo == p2->expo)
        {
            start3 = insert(start3, p1->coef + p2->coef, p1->expo);
            p1 = p1->link;
            p2 = p2->link;
        }
    }

    while (p1 != NULL)
    {
        start3 = insert(start3, p1->coef, p1->expo);
        p1 = p1->link;
    }

    while (p2 != NULL)
    {
        start3 = insert(start3, p2->coef, p2->expo);
        p2 = p2->link;
    }

    printf("Added Polynomial is: ");
    display(start3);
}

void poly_mul(struct node *p1, struct node *p2)
{
    struct node *start3 = NULL, *p2_beg = NULL;
    p2_beg = p2;

    if (p1 == NULL || p2 == NULL)
    {
        printf("Multiplied Polynomial is a zero polynomial\n");
        return;
    }

    while (p1 != NULL)
    {
        p2 = p2_beg;
        while (p2 != NULL)
        {
            start3 = insert_s(start3, p1->coef * p2->coef, p1->expo + p2->expo);
            p2 = p2->link;
        }
        p1 = p1->link;
    }

    printf("Multiplied Polynomial is: ");
    display(start3);
}
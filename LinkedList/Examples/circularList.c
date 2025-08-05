#include <stdio.h>
#include <stdlib.h>

// Structure Declararion
struct node
{
    int info;
    struct node *link;
};

// Function Prototype
struct node *create_list(struct node *last);
void display(struct node *last);
struct node *addatbeg(struct node *last, int data);
struct node *addatempty(struct node *last, int data);
struct node *addatend(struct node *last, int data);
struct node *addafter(struct node *last, int data, int item);
struct node *del(struct node *last, int data);

int main(void)
{
    struct node *last = NULL;
    int choice, data, item, pos;

    while (1)
    {
        printf("1. Create a list\n");
        printf("2. Display\n");
        printf("3. Add to empty list\n");
        printf("4. Add at beginning\n");
        printf("5. Add at end\n");
        printf("6. Add after\n");
        printf("7. Delete\n");
        printf("8. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            last = create_list(last);
            break;

        case 2:
            display(last);
            break;

        case 3:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            last = addatempty(last, data);
            break;

        case 4:
            printf("Enter the elements to be inserted : ");
            scanf("%d", &data);
            last = addatbeg(last, data);
            break;

        case 5:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            last = addatend(last, data);
            break;

        case 6:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the element after which to insert : ");
            scanf("%d", &item);
            last = addafter(last, data, item);
            break;

        case 7:
            printf("Enter the element to be deleted : ");
            scanf("%d", &data);
            last = del(last, data);
            break;

        case 12:
            exit(1);

        default:
            printf("Illegal command!!\n");
            break;
        }
    }
}

struct node *create_list(struct node *last)
{
    int noOfNode = 0, data = 0;
    last = NULL;

    printf("Enter the number of nodes to be created: ");
    scanf("%d", &noOfNode);

    if (!noOfNode)
        return last;

    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    last = addatempty(last, data);

    for (int i = 2; i <= noOfNode; i++)
    {
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        last = addatend(last, data);
    }

    return last;
}

void display(struct node *last)
{
    struct node *p = NULL;

    if (last == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    p = last->link;
    do
    {
        printf("%d\t", p->info);
        p = p->link;
    } while (p != last->link);

    printf("\n\n");
}

struct node *addatbeg(struct node *last, int data)
{
    struct node *tmp = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));

    tmp->info = data;
    tmp->link = last->link;
    last->link = tmp;

    return last;
}

struct node *addatempty(struct node *last, int data)
{
    struct node *tmp = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));

    tmp->info = data;
    last = tmp;
    last->link = last;

    return last;
}

struct node *addatend(struct node *last, int data)
{
    struct node *tmp = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));

    tmp->info = data;
    tmp->link = last->link;
    last->link = tmp;
    last = tmp;

    return last;
}

struct node *addafter(struct node *last, int data, int item)
{
    struct node *tmp = NULL, *p = NULL;

    p = last->link;
    do
    {
        if (p->info == item)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;

            tmp->link = p->link;
            p->link = tmp;
            if (p == last)
                last = tmp;

            return last;
        }

        p = p->link;
    } while (p != last->link);

    printf("%d element not found in the list!", item);
    return last;
}

struct node *del(struct node *last, int data)
{
    struct node *p = NULL, *tmp = NULL;
    p = last;

    // If list is empty
    if (last == NULL)
    {
        printf("list is empty!\n");
        return last;
    }

    // If only one node
    if (last->link == last && last->info == data)
    {
        tmp = last;
        last = NULL;
        free(tmp);
        return last;
    }

    // If 1st node
    if (last->link->info == data)
    {
        tmp = last->link;
        last->link = tmp->link;
        free(tmp);
        return last;
    }

    // In between the nodes
    p = last->link;
    while (p->link != last)
    {
        if (p->link->info == data)
        {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return last;
        }
        p = p->link;
    }

    // Deletion of last node
    if (p->link->info == data)
    {
        tmp = p->link;
        p->link = tmp->link;
        last = p;
        free(tmp);
        return last;
    }

    printf("%d element not found in the list\n", data);
m    return last;
}

#include <stdio.h>
#include <stdlib.h>

// Structure Declararion
struct node
{
    int info;
    struct node *link;
};

// Function Prototype
struct node *create_list(struct node *head);
void display(struct node *head);
struct node *addatend(struct node *head, int data);
struct node *addbefore(struct node *head, int data, int item);
struct node *addatpos(struct node *head, int data, int pos);
struct node *del(struct node *head, int data);
struct node *reverse(struct node *head);

int main(void)
{
    struct node *head = NULL;
    int choice, data, item, pos;

    head = (struct node *)malloc(sizeof(struct node));
    head->info = 0;
    head->link = NULL;

    head = create_list(head);

    while (1)
    {
        printf("1. Display\n");
        printf("2. Add at end\n");
        printf("3. Add before node\n");
        printf("4. Add at position\n");
        printf("5. Delete\n");
        printf("6. Reverse\n");
        printf("7. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            display(head);
            break;

        case 2:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            head = addatend(head, data);
            break;

        case 3:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the element before which to insert : ");
            scanf("%d", &item);
            head = addbefore(head, data, item);
            break;

        case 4:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the position at which to insert : ");
            scanf("%d", &pos);
            head = addatpos(head, data, pos);
            break;

        case 5:
            printf("Enter the element to be deleted : ");
            scanf("%d", &data);
            head = del(head, data);
            break;

        case 6:
            head = reverse(head);
            break;

        case 7:
            exit(1);

        default:
            printf("Illegal command!!\n");
            break;
        }
    }
}

struct node *create_list(struct node *head)
{
    int noOfNode = 0, data = 0;

    printf("Enter the number of nodes : ");
    scanf("%d", &noOfNode);

    if (noOfNode == 0)
        return head;

    printf("Enter the element to be inserted : ");
    scanf("%d", &data);

    head = addatbeg(head, data);
    for (int i = 2; i <= noOfNode; i++)
    {
        printf("Enter the element to be inserted : ");
        scanf("%d", &data);
        head = addatend(head, data);
    }

    return head;
}

void display(struct node *head)
{
    struct node *p = head;

    if (head->link == NULL)
    {
        printf("List is empty!!\n");
        return;
    }
    else
    {
        p = head->link;
        while (p != NULL)
        {
            printf("%d\t", p->info);
            p = p->link;
        }
    }

    printf("\n\n");
}

struct node *addatend(struct node *head, int data)
{
    struct node *tmp = NULL, *p = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;

    p = head;
    while (p->link != NULL)
        p = p->link;

    p->link = tmp;
    tmp->link = NULL;

    return head;
}

struct node *addbefore(struct node *head, int data, int item)
{
    struct node *tmp = NULL, *p = NULL;
    p = head;
    while (p->link != NULL)
    {
        if (p->link->info == item)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;

            tmp->link = p->link;
            p->link = tmp;
            return head;
        }

        p = p->link;
    }

    printf("%d not present in the list\n", item);
    return head;
}

struct node *addatpos(struct node *head, int data, int pos)
{
    struct node *tmp = NULL, *p = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    int i;

    p = head;
    for (i = 1; i < pos; i++)
    {
        p = p->link;
        if(p == NULL) {
            printf("There are less than %d elements in the list\n", pos);
            return head;
        }
    }

    tmp->link = p->link;
    p->link = tmp;

    return head;
}

struct node *del(struct node *head, int data)
{
    struct node *tmp = NULL, *p = NULL;
    p = head;

    while(p->link != NULL) {
        if(p->link->info == data) {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return head;
        }
    }

    printf("%d element not present in the list\n", data);
    return head;
}

struct node *reverse(struct node *head)
{
    struct node *prev = NULL, *ptr = NULL, *next = NULL;

    prev = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        next = ptr->link;
        ptr->link = prev;
        prev = ptr;
        ptr = next;
    }

    head = prev;
    return head;
}
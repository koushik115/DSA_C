#include <stdio.h>
#include <stdlib.h>

// Structure Declararion
struct node {struct node *prev; int info; struct node *next;};

// Function Prototype
struct node *create_list(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start, int data);
struct node *addtoempty(struct node *start, int data);
struct node *addatbeg(struct node *start, int data);
struct node *addatend(struct node *start, int data);
struct node *addafter(struct node *start, int data, int item);
struct node *addbefore(struct node *start, int data, int item);
struct node *addatpos(struct node *start, int data, int pos);
struct node *del(struct node *start, int data);
struct node *reverse(struct node *start);

int main(void) {
    struct node *start = NULL;
    int choice, data, item, pos;

    while(1) {
        printf("1. Create a list\n");
        printf("2. Display\n");
        printf("3. Count\n");
        printf("4. Search\n");
        printf("5. Add to empty list \\ Add at beginning\n");
        printf("6. Add at end\n");
        printf("7. Add after node\n");
        printf("8. Add before node\n");
        printf("9. Add at position\n");
        printf("10. Delete\n");
        printf("11. Reverse\n");
        printf("12. Quit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start = create_list(start);
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
            printf("Enter the elements to be inserted : ");
            scanf("%d", &data);
            start = addatbeg(start, data);
            break;

        case 6:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            start = addatend(start, data);
            break;

        case 7:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the element after which to insert : ");
            scanf("%d", &item);
            start = addafter(start, data, item);
            break;

        case 8:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the element before which to insert : ");
            scanf("%d", &item);
            start = addbefore(start, data, item);
            break;

        case 9:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the position at which to insert : ");
            scanf("%d", &pos);
            start = addatpos(start, data, pos);
            break;

        case 10:
            printf("Enter the element to be deleted : ");
            scanf("%d", &data);
            start = del(start, data);
            break;

        case 11:
            start = reverse(start);
            break;

        case 12:
            exit(1);

        default:
            printf("Illegal command!!\n");
            break;
        }
    }
}

struct node *create_list(struct node *start) {
    int i, n, data;

    printf("Enter the number of nodes : ");
    scanf("%d", &n);

    start = NULL;
    if(start == NULL)
        return start;

    printf("Enter the elements to be inserted : ");
    scanf("%d", &data);
    start = addatbeg(start, data);
    
    for(i = 2; i <= n; i++) {
    printf("Enter the elements to be inserted : ");
    scanf("%d", &data);
    start = addatend(start, data);        
    }

    return start;
}

void display(struct node *start) {
    struct node *p = start;

    if(p == NULL) {
        printf("No elements in the list!!\n");
        return;
    }

    while(p != NULL) {
        printf("%d ", p->info);
        p = p->next;
    }

    printf("\n\n");
}

void count(struct node *start) {
    struct node *p = NULL;
    int count = 0;

    if(start == NULL) {
        printf("No elements found in the list!\n");
        return;
    } 

    p = start;
    while(p != NULL) {
        count++;
        p = p->next;
    }

    printf("%d elements found in the list!\n", count);
}

void search(struct node *start, int data) {
    struct node *p = start;
    int pos = 1;

    while(p != NULL) {
        if(p->info == data) {
            printf("Item %d found at %d position\n", data, pos);
            return;
        }

        p = p->next;
        pos++;
    }

    printf("Item %d not found in the list\n");
}

struct node *addtoempty(struct node *start, int data) {
    struct node *tmp = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));

    tmp->prev = NULL;
    tmp->info = data;
    tmp->next = NULL;
    start = tmp;

    return start;
}

struct node *addatbeg(struct node *start, int data) {
    struct node *tmp = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));

    tmp->prev = NULL;
    tmp->info = data;
    tmp->next = start;
    start->prev = tmp;
    start = tmp;

    return start;
}

struct node *addatend(struct node *start, int data) {
    struct node *tmp = NULL, *p = NULL;
    
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;

    p = start;
    while(p->next != NULL)
        p = p->next;

    p->next = tmp;
    tmp->prev = p;
    tmp->next = NULL;

    return start;
}

struct node *addafter(struct node *start, int data, int item) {
    struct node *tmp = NULL, *p = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;

    while(p != NULL) {
        if(p->info == item) {
            tmp->prev = p;
            tmp->next = p->next;
            if(p->next != NULL) {
                p->next->prev = tmp;
            }
            p->next = tmp;

            return start;
        }
        p = p->next;
    }
    printf("Element %d not found in the list!\n", item);

    return start;
}

struct node *addbefore(struct node *start, int data, int item) {
    struct node *tmp = NULL, *q = NULL;
    
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;

    if(start == NULL) {
        printf("List is empty!\n");
        return start;
    }

    if(start->info == item) {
        tmp->next = start;
        tmp->prev = NULL;
        start->prev = tmp;
        start = tmp;

        return start;
    }

    q = start;
    while(q != NULL) {
        if(q->info == item) {
            tmp->next = q;
            tmp->prev = q->prev;
            q->prev->next = tmp;
            q->prev = tmp;

            return start;
        }
        q = q->next;
    }

    printf("Element %d not found in the list!\n", item);
    printf("\n\n");

    return start;
}

struct node *addatpos(struct node *start, int data, int pos) {
    struct node *tmp = NULL, *p = NULL;

    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;

    if(pos == 1) {
        tmp->link = start;
        start = tmp;
        return start;
    }

    p = start;
    for(int i = 0; i < pos - 1 && p != NULL; i++)
        p = p->link;

    if(p == NULL) 
        printf("There are less than %d elements in the list!\n", pos);
    else {
        tmp->link = p->link;
        p->link = tmp;
    }

    return start;
}

struct node *del(struct node *start, int data) {
    struct node *tmp = NULL;

    if(start == NULL) {
        printf("List is empty!\n");
        return start;
    }

    if(start->next == NULL) {
        if(start->info == data) {
            tmp = start;
            start = NULL;
            free(tmp);
        
            return start;
        } else {
            printf("Element %d not found in the list\n", data);
            return start;
        }
    }

    if(start->info == data) {
        tmp = start;
        start = start->next;
        start->prev = NULL;
        free(tmp);

        return start;
    }

    tmp = start->next;
    while (tmp->next != NULL) {
        if(tmp->info == data) {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            free(tmp);

            return start;
        }
    }

    if(tmp->next == NULL && tmp->info == data)  {
        tmp->prev->next = NULL;
        free(tmp);

        return start;
    }

    printf("Element %d not found in the list!\n", data);
    return start;
}

struct node *reverse(struct node *start) {
    struct node *p1 = NULL, *p2 = NULL;

    p1 = start;
    p2 = p1->next;

    p1->next = NULL;
    p1->prev = p2;
    
    while(p2 != NULL) {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }

    start = p1;

    return start;
}

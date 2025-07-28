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
    int noOfNode = 0, data = 0;
    
    printf("Enter the number of nodes : ");
    scanf("%d", &noOfNode);

    if(noOfNode == 0) 
        return start;

    printf("Enter the element to be inserted : ");
    scanf("%d", &data);

    start = addatbeg(start, data);
    for(int i = 2; i <= noOfNode; i++) {
        printf("Enter the element to be inserted : ");
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
        p = p->link;
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

        p = p->link;
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
    struct node *tmp = NULL, *p = NULL;

    if(start == NULL) {
        printf("List is empty!!\n");
        return start;
    }

    // First item to be deleted
    if(data == start->info) {
        tmp = start;
        start = start->link;
        free(tmp);
        return start;
    }

    // Item to be deleted in between the nodes
    p = start;
    while(p->link != NULL) {
        if(p->link->info == data) {
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

struct node *reverse(struct node *start) {
    struct node *prev = NULL, *ptr = NULL, *next = NULL;

    prev = NULL;
    ptr = start;
    while(ptr != NULL) {
        next = ptr->link;
        ptr->link = prev;
        prev = ptr;
        ptr = next;
    }

    start = prev;
    return start;
}
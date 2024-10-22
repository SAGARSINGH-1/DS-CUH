#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;
struct node *top;

void traverse()
{
    if (head == NULL && top == NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Linked list is : ");
        struct node *loc = head;
        while (loc != NULL)
        {
            printf("%d\t", loc->data);
            loc = loc->next;
        }
    }
}

void insert()
{
    int data;
    printf("Enter the data to insert : ");
    scanf("%d", &data);

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    if (head == NULL && top == NULL)
    {
        head = ptr;
        ptr->next = NULL;
        top = ptr;
    }
    else
    {
        struct node *loc = head;
        while (loc->next != NULL)
        {
            loc = loc->next;
        }
        loc->next = ptr;
        ptr->next = NULL;
        top = ptr;
    }
    traverse();
}

void delete()
{
    struct node *loc, *ptr;
    loc = head;

    if (head == NULL)
    {
        printf("Stack is empty.");
        return;
    }
    else if (head->next == NULL)
    {
        head = NULL;
        top = NULL;
        free(loc);
        return;
    }
    else
    {
        while (loc->next != NULL)
        {
            ptr = loc;
            loc = loc->next;
        }
        ptr->next = NULL;
        top = ptr;
        free(loc);
    }
    traverse();
}

int main()
{
    int choice;
    while (1 < 4)
    {
        printf("\n\n1. Insertion\n2. Deletion\n3. Traverse \n4. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            traverse();
            break;
        case 4:
            printf("Exiting program");
            exit(0);
        default:
            printf("Undefined choice.");
            break;
        }
    }
}
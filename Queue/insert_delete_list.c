#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front;
struct node *rear;

void traverse()
{
    struct node *loc = front;
    printf("Queue is : ");
    while (loc != NULL)
    {
        printf("%d\t", loc->data);
        loc = loc->next;
    }
}

void insert()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data to insert : ");
    scanf("%d", &ptr->data);
    ptr->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = ptr;
        rear = ptr;
    }
    else
    {
        struct node *loc = front;

        while (loc->next != NULL)
        {
            loc = loc->next;
        }
        loc->next = ptr;
        rear = ptr;
    }
    traverse();
}

void delete()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty.");
        return;
    }
    else if (front->next == NULL)
    {
        front = NULL;
        rear = NULL;
        return;
    }
    else
    {
        struct node *loc = front;
        front = front->next;
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
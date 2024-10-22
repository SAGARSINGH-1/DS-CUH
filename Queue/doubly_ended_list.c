#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void traverse()
{
    if (front == NULL)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        printf("Queue elements are : ");
        struct node *loc = front;
        while (loc != NULL)
        {
            printf("%d ", loc->data);
            loc = loc->next;
        }
        printf("\n");
    }
}

void beg_insert()
{
    int data;
    printf("Enter the data to be inserted : ");
    scanf("%d", &data);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    if (front == NULL)
    {
        front = ptr;
        rear = ptr;
        ptr->next = NULL;
    }
    else
    {
        ptr->next = front;
        front = ptr;
    }
}

void beg_delete()
{
    if (front == NULL)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        struct node *loc = front;
        front = front->next;
        free(loc);
    }
}

void end_insert()
{
    int data;
    printf("Enter the data to be inserted : ");
    scanf("%d", &data);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;

    if (front == NULL)
    {
        ptr->next = NULL;
        front = ptr;
        rear = ptr;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
    }
}

void end_delete()
{
    if (front == NULL)
    {
        printf("\nQueue is empty.\n");
    }
    else if (front == rear)
    {
        free(front);
        front = rear = NULL;
    }
    else
    {
        struct node *loc = front;
        while (loc->next != rear)
        {
            loc = loc->next;
        }
        free(rear);
        rear = loc;
        loc->next = NULL;
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\nEnter the choice : \n");
        printf("\n1. Insertion from beginning.\n2. Insertion from end.\n3. Deletion from beginning.\n4. Deletion from end.\n5. Traverse\n6. Exit.\n");
        scanf("%d", &choice);

        // int QueueType;
        // printf("Enter the type of queue you have : ");
        // scanf("%d", &QueueType);

        switch (choice)
        {
        case 1:
            beg_insert();
            break;
        case 2:
            end_insert();
            break;
        case 3:
            beg_delete();
            break;
        case 4:
            end_delete();
            break;
        case 5:
            traverse();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice : ");
            break;
        }
    }
}

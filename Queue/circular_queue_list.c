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
    if (front == NULL)
    {
        printf("Queue is empty");
    }
    else if (front->next == front)
    {
        printf("One element is present: %d\n", front->data);
    }
    else
    {
        struct node *loc = front;
        printf("Elements are : ");
        do
        {
            printf("%d ", loc->data);
            loc = loc->next;
        } while (loc != front);

        printf("\n");
    }
}

void insert()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data to insert: ");
    scanf("%d", &ptr->data);

    if (front == NULL)
    {
        front = ptr;
        ptr->next = front;
        rear = ptr;
    }
    else
    {
        ptr->next = front;
        rear->next = ptr;
        rear = ptr;
    }
}

void delete()
{
    struct node *loc = front;

    if (front == NULL)
    {
        printf("Queue is empty");
    }
    else if (front->next == front)
    {
        front = rear = NULL;
        printf("Last element to be deleted is : %d\n", loc->data);
        free(loc);
    }
    else
    {
        front = front->next;
        rear->next = front;
        free(loc);
    }
}

int main()
{

    int choice;
    printf("Enter the choice : \n");

    while (1)
    {
        printf("1. Insertion\n2. Deletion\n3. Traverse\n4. Exit\n");
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
            exit(0);
            break;
        default:
            printf("Option dekh le bhai.");
            break;
        }
    }
}
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;
struct node *end;

void traverse()
{
    if (head == NULL && end == NULL)
    {
        printf("Linked list is empty..");
        return;
    }
    else
    {
        struct node *loc = head;
        printf("Linked list is : ");

        do
        {
            printf("%d\t", loc->data);
            loc = loc->next;
        } while (loc != head);
        printf("\n");
    }
}

void beg_insert()
{
    int data;
    printf("Enter the data to be inserted : ");
    scanf("%d", &data);

    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    if (head == NULL && end == NULL)
    {
        head = ptr;
        end = ptr;
        ptr->next = head;
    }
    else
    {
        ptr->next = head;
        head = ptr;
        end->next = head;
    }
    traverse();
}

void end_insert()
{
    int data;
    printf("Enter the data : ");
    scanf("%d", &data);

    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    if (head == NULL && end == NULL)
    {
        head = ptr;
        end = ptr;
        ptr->next = head;
    }
    else
    {
        struct node *loc = head;
        while (loc->next != head)
        {
            loc = loc->next;
        }
        loc->next = ptr;
        ptr->next = head;
        end = ptr;
    }
    traverse();
}

void position_insert()
{
    int data, index;
    printf("Enter the data to insert : \n");
    scanf("%d", &data);
    printf("Enter the index to insert in : \n");
    scanf("%d", &index);

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    if (head == NULL && end == NULL)
    {
        head = ptr;
        end = ptr;
        ptr->next = head;
    }
    else
    {
        struct node *loc = head;
        for (int i = 0; i < index; i++)
        {
            loc = loc->next;
        }
        ptr->next = loc->next;
        loc->next = ptr;
    }
    traverse();
}

// Deletion

void beg_delete()
{
    struct node *loc = head;
    if (head == NULL && end == NULL)
    {
        printf("No Nodes to be deleted");
    }
    else if (head->next == head)
    {
        printf("Last element is %d which is removed.", head->data);
        head = NULL, end = NULL;
    }
    else
    {
        printf("Element is deleted is : %d", head->data);
        head = head->next;
        end->next = head;
        free(loc);
    }
    traverse();
}

void end_delete()
{
    struct node *loc = head;

    if (head == NULL && end == NULL)
    {
        printf("No Nodes to be deleted");
    }
    else if (head->next == head)
    {
        printf("Last element is %d which is removed.", head->data);
        head = NULL, end = NULL;
    }
    else
    {
        struct node *ptr;
        while (loc->next != head)
        {
            ptr = loc;
            loc = loc->next;
        }
        end = ptr;
        ptr->next = head;
    }
}

void position_delete()
{
    struct node *loc = head;
    int index;
    printf("Enter the index of node to be deleted.");
    scanf("%d", &index);

    if (index == 0)
    {
        head = head->next;
        if (head == NULL)
        {
            end = NULL;
        }
        free(loc);
        return;
    }
    else if (head->next == head)
    {
        printf("Last element is %d which is removed.", head->data);
        head = NULL, end = NULL;
        return;
    }
    else
    {

        struct node *ptr;
        for (int i = 0; i < index; i++)
        {
            if (loc == NULL || loc->next == NULL)
            {
                printf("Index out of range.\n");
                return;
            }
            ptr = loc;
            loc = loc->next;
        }
        ptr->next = loc->next;
        free(loc);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n\nEnter the position to insert in : ");
        printf("\n1. Insertion from front\n2. Insertion from back\n3. Insertion at specific position\n4. Traverse\n5. Deletion from begining\n6. Deletion at last\n7. Deletion at specific position\n8. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            beg_insert();
            break;
        case 2:
            end_insert();
            break;
        case 3:
            position_insert();
            break;
        case 4:
            traverse();
            break;
        case 5:
            beg_delete();
            break;
        case 6:
            end_delete();
            break;
        case 7:
            position_delete();
            break;
        case 8:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Out of options selected..");
            break;
        }
    }
}
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void beg_insert()
{
    int data;
    struct node *ptr;
    printf("Enter the data to be inserted : ");
    scanf("%d", &data);

    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    if (head != NULL)
    {
        ptr->next = head;
        head = ptr;
    }
    else
    {
        head = ptr;
    }
}

void end_insert()
{
    int data;

    printf("Enter the data to be inserted : ");
    scanf("%d", &data);

    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->next = NULL;
    ptr->data = data;

    struct node *loc = head;

    if (head != NULL)
    {
        while (loc->next != NULL)
        {
            loc = loc->next;
        }
        loc->next = ptr;
    }
    else
    {
        head = ptr;
    }
}

void position_insert()
{
    int data, index, i = 0;
    printf("Enter the data to be inserted : ");
    scanf("%d", &data);
    printf("Enter the index to be inserted in : ");
    scanf("%d", &index);

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    if (index == 0)
    {
        ptr->next = head;
        head = ptr;
    }
    else if (head != NULL && index > 0)
    {
        struct node *loc = head;

        while (i < index - 1 && loc->next != NULL)
        {
            loc = loc->next;
            i++;
        }
        ptr->next = loc->next;
        loc->next = ptr;
    }
}

void traverse()
{
    struct node *ptr = head;

    if (ptr != NULL)
    {
        printf("Linked list is : ");

        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
    else
    {
        printf("Linked List is empty..\n");
    }
}

void beg_delete()
{
    if (head != NULL)
    {
        struct node *loc = head;
        head = loc->next;
        printf("Item %d has been deleted\n", loc->data);
        free(loc);
    }
    else
    {
        printf("No nodes to delete..");
    }
}

void end_delete()
{
    if (head == NULL)
    {
        printf("No nodes to be deleted.");
    }
    else if (head->next == NULL)
    {
        printf("Only one element exits deleted the %d", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        struct node *ptr = head;
        struct node *loc;
        while (ptr->next != NULL)
        {
            loc = ptr;
            ptr = ptr->next;
        }
        loc->next = NULL;
        printf("Node %d is deleted succesfully..", ptr->data);
        free(ptr);
    }
}

void position_delete()
{

    if (head == NULL)
    {
        printf("Linked list is empty..");
    }
    else if (head->next == NULL)
    {
        printf("Only one element exits deleted the %d", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        int index;
        printf("Enter the index node which you want to delete..");
        scanf("%d", &index);
        struct node *ptr = head;
        struct node *loc;
        for (int i = 0; i < index - 1; i++)
        {
            if (ptr->next != NULL)
            {
                loc = ptr;
                ptr = ptr->next;
            }
            else
            {
                printf("Given index is not present in list");
                return;
            }
        }
        loc->next = ptr->next;
        printf("Node %d has been removed", ptr->data);
        free(ptr);
    }
}

int main()
{

    int b = 3;
    int choice;
    while (b < 4)
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
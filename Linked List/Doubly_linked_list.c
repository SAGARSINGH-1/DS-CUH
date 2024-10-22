#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head;

void beg_insert()
{
    int data;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));

    printf("Enter the node data : \t");
    scanf("%d", &data);
    ptr->data = data;

    if (head == NULL)
    {
        head = ptr;
        ptr->next = NULL;
        ptr->prev = NULL;
    }
    else
    {
        head->prev = ptr;
        ptr->next = head;
        ptr->prev = NULL;
        head = ptr;
    }
}

void end_insert()
{
    int data;
    printf("Enter the data to be inserted : ");
    scanf("%d", &data);

    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    if (head == NULL)
    {
        head = ptr;
        ptr->next = NULL;
        ptr->prev = NULL;
    }
    else if (head->next == NULL)
    {
        ptr->next = NULL;
        head->next = ptr;
        ptr->prev = head;
    }
    else
    {
        struct node *loc = head;

        while (loc->next != NULL)
        {
            loc = loc->next;
        }
        loc->next = ptr;
        ptr->prev = loc;
        ptr->next = NULL;
    }
}

void position_insert()
{
    int data, index;
    printf("Enter the data to insert in the list\t");
    scanf("%d", &data);

    printf("Enter the index to insert in the list\t");
    scanf("%d", &index);

    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    if (index == 0)
    {
        ptr->next = head;
        ptr->prev = NULL;
        head->prev = ptr;
        head = ptr;
        return;
    }

    if (head == NULL)
    {
        ptr->next = NULL;
        ptr->prev = NULL;
        head = ptr;
        return;
    }
    else if (head->next == NULL)
    {
        head->next = ptr;
        ptr->prev = head;
        ptr->next = NULL;
        return;
    }
    else
    {
        struct node *loc = head;
        for (int i = 0; i < index - 1; i++)
        {
            loc = loc->next;
        }
        ptr->next = loc->next;
        loc->next->prev = ptr;
        loc->next = ptr;
        ptr->prev = loc;
    }
}

void traverse()
{
    if (head == NULL)
    {
        printf("No Nodes are present in the list\n");
    }
    else
    {
        struct node *ptr = head;

        printf("Linked list is : ");
        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
}

void beg_delete()
{
    struct node *loc = head;

    if (head == NULL)
    {
        printf("Lined list is empty");
    }
    else if (head->next == NULL)
    {
        head == NULL;
        free(loc);
    }
    else
    {
        loc->next->prev = NULL;
        head = loc->next;
        free(loc);
    }
}

void end_delete()
{
    struct node *loc = head;

    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(loc);
    }
    else
    {
        struct node *ptr;
        while (loc->next != NULL)
        {
            ptr = loc;
            loc = loc->next;
        }
        ptr->next = NULL;
        free(loc);
    }
}

void position_delete()
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct node *loc = head;
    struct node *ptr = NULL;
    int index;

    printf("Enter the index of the node: ");
    scanf("%d", &index);

    // Case 1: Deletion at the head (index 0)
    if (index == 0)
    {
        head = loc->next; // Move head to the next node
        if (head != NULL) // Check if the list had more than one node
        {
            head->prev = NULL;
        }
        free(loc); // Free the old head
        return;
    }

    // Case 2: Deletion at other positions
    for (int i = 0; i < index; i++)
    {
        ptr = loc;       // Keep track of the previous node
        loc = loc->next; // Move to the next node

        if (loc == NULL)
        {
            // If we reach the end and still haven't found the index, it's out of bounds
            printf("Index out of bounds. No such node exists.\n");
            return;
        }
    }

    // Now, 'loc' is the node to be deleted, and 'ptr' is its previous node

    // Case 2a: If deleting the last node
    if (loc->next == NULL)
    {
        ptr->next = NULL; // Remove the link from the previous node
    }
    else
    {
        // Case 2b: If deleting in the middle
        ptr->next = loc->next;
        loc->next->prev = ptr;
    }

    printf("Node %d at index %d has been removed.\n", loc->data, index);
    free(loc); // Free the memory of the node to be deleted
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
#include <stdio.h>
#include <stdlib.h>

void traverse(int arr[], int size, int front, int rear)
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements are: ");
    int i = front;
    while (i != rear)
    {
        printf("%d ", arr[i]);
        i = (i + 1) % size;
    }
    printf("%d\n", arr[rear]);
}

void insert(int arr[], int size, int *front, int *rear)
{

    if ((*rear + 1) % size == *front)
    {
        printf("Queue is full");
        return;
    }
    else
    {
        int data;
        printf("Enter the data to be inserted : ");
        scanf("%d", &data);
        if (*front == -1)
        {
            *front = 0;
            *rear = 0;
        }
        else
        {
            *rear = (*rear + 1) % size;
        }
        arr[*rear] = data;
    }
}

void delete(int arr[], int size, int *front, int *rear)
{
    if (*front == -1)
    {
        printf("Queue is empty");
        return;
    }
    if (*front == *rear)
    {
        *front = *rear = -1;
    }
    else
    {
        *front = (*front + 1) % size;
    }
}

int main()
{
    int size;
    printf("Enter the size of the array : ");
    scanf("%d", &size);

    int arr[size];

    int front = -1;
    int rear = -1;

    int choice;
    while (1 < 4)
    {
        printf("\n\n1. Insertion\n2. Deletion\n3. Traverse \n4. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert(arr, size, &front, &rear);
            break;
        case 2:
            delete (arr, size, &front, &rear);
            break;
        case 3:
            traverse(arr, size, front, rear);
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
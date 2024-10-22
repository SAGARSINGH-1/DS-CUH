// Problem in simple queue : when u delete delete elements the front go to next so the empty space is available in the queue but due to the other element present at the back of the queue in the rear i mean, so if we delete all elements then we can insert new elements before that we can 't do anything that' s why the concept of circular queue is introduced.

#include <stdio.h>

void traverse(int arr[], int front, int rear)
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements is : ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void insert(int arr[], int size, int *front, int *rear)
{

    if (*rear == size)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        int data;
        printf("Enter the data to insert : \n");
        scanf("%d", &data);
        if (*front == -1)
        {
            *front = 0;
        }
        (*rear)++;
        arr[*rear] = data;
        printf("Inserted %d\n", data);
    }
}

void delete(int arr[], int size, int *front, int *rear)
{
    if (*front == -1)
    {
        printf("Queue is empty.");
    }
    else if (*front > *rear)
    {
        *rear = -1;
        *front = -1;
    }
    else
    {
        printf("Elements %d is deleted\n", &arr[*front]);
        (*front)++;
    }
}

int main()
{
    int size;
    printf("Enter the size of an array : \n");
    scanf("%d", &size);
    int arr[size];
    int front = -1;
    int rear = -1;

    int choice;
    printf("Enter the choice : \n");

    while (1)
    {
        printf("1. Insertion\n2. Deletion\n3. Traverse\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert(arr, size - 1, &front, &rear);
            break;
        case 2:
            delete (arr, size, &front, &rear);
            break;
        case 3:
            traverse(arr, front, rear);
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
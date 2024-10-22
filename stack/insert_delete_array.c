#include <stdio.h>
#include <stdlib.h>

void traverse(int arr[], int *size, int *top)
{
    if (*top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements are : ");
    for (int i = 0; i <= *top; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void insert(int arr[], int *size, int *top)
{
    if (*top >= (*size) - 1)
    {
        printf("Stack is full.\n");
        return;
    }
    else
    {
        int data;
        printf("Enter the data to insert: \n");
        scanf("%d", &data);
        (*top)++;
        arr[(*top)] = data;
    }
}

void delete(int arr[], int *top)
{
    if (*top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        (*top)--;
    }
}

int main()
{
    int size;
    printf("Enter the size of an stack\n");
    scanf("%d", &size);
    int arr[size];
    int top = -1;

    int choice;

    while (1)
    {
        printf("Enter the choice : ");
        printf("\n\n1. Insertion\n2. Deletion\n3. Traverse\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert(arr, &size, &top);
            break;
        case 2:
            delete (arr, &top);
            break;
        case 3:
            traverse(arr, &size, &top);
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    }
}
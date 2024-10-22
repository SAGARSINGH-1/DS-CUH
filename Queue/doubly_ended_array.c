#include <stdio.h>
#include <stdlib.h>

void beg_insert(int arr[], int size, int *front, int *rear)
{
    int data;
    printf("Enter the data to be inserted : ");
    scanf("%d", &data);

    if (*front == -1)
    {
        (*front)++;
        (*rear)++;
        arr[*front] = data;
    }
    else
    {
        }
}

int main()
{
    int size;
    printf("Enter the size of queue : ");
    scanf("%d", &size);

    int arr[size];
    int front = -1;
    int rear = -1;

    int choice;

    while (1)
    {
        printf("\nEnter the choice : \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            beg_insert(arr, size, &front, &rear);
            break;
        case 2:
            // beg_delete();
            break;

        default:
            break;
        }
    }
}
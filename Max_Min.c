#include <stdio.h>
#include <limits.h>

void printMinMax(int arr[], int length) {
    int max = INT_MIN;
    int min = INT_MAX;
    
    for (int i = 0; i < length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    
    printf("Max value is: %d\n", max);
    printf("Min value is: %d\n", min);
}

int main() {
    int length;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &length);
    
    int arr[length];
    
    printf("Enter the elements:\n");
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }
    
    printMinMax(arr, length);
    
    return 0;
}

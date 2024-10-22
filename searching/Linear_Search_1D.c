#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 25, 47, 36, 72, 18, 54};
    int size = 7;
    int target;

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    int index = linearSearch(arr, size, target);

    if (index != -1) {
        printf("Element found at index %d.\n", index);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}

#include <stdio.h>

int BinarySearch(int arr[], int size, int target){
    int Lb=0,Ub=size;
    while(Lb<=Ub){
        int mid= Lb + Ub/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            Lb=mid+1;
        }
        else{
            Ub=mid-1;
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

    int index = BinarySearch(arr, size, target);

    if (index != -1) {
        printf("Element found at index %d.\n", index);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}

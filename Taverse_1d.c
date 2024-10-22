#include <stdio.h>

void SumOf(int arr[], int size) {
    int sum=0;
    for(int i=0; i<size; i++){
        sum+=arr[i];
    }
    printf("Sum of all elements present in array is: %d",sum);
}

int main() {
    int arr[4] = {9, 10, 11, 12};
    
    SumOf(arr, 4);

    return 0;
}
